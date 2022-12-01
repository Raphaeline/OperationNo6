#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//title
void TitleRegist();
void TitleMain();
void TitleAdmin();
void TitleInputListRumah();
void TitleInputListApartment();

//display
void DisplayAdmin();
void DisplayMain();
void DisplayUser();
void DisplayAccAdmin();
void DisplayListRumahAdmin();
void DisplayListApartmentAdmin();

//fungsi pembantu
void cls();
void PilihanKeluar();
int InputPilihanMain();
int InputPilihanAdmin();
int PilihanAccAdmin();
int InputPilihanListRumahAdmin();
int InputPilihanListApartmentAdmin();
int SortDataListRumahJual();
int SortDataListRumahSewa();
int SortDataListApartmentSewa();
int SortDataListApartmentJual();

//admin
void AdminMenu();
int LoginAdmin();
void UserAccAdmin();
void ListRumahAdmin();
void ListApartmentAdmin();
void LihatAkun();
void HapusAkun();
void InputListRumah();
void InputListApartment();
void MenghapusListRumah();
void LihatListRumah();
void MenghapusListApartment();
void LihatListApartment();
void LihatListApartmentSewa();
void LihatListApartmentJual();
void LihatListRumahJual();
void LihatListRumahSewa();

//user
void UserMenu();
void RegisterUser();
struct User{
	char nama[100],tanggallahir[100],kewarganegaraan[50], alamat[100];
	char passport[100], username[100], password[100];
	int umur;
}dataUser;
FILE *fp;
FILE *fp2;

char *tempFile = "temp.dat";
char *userBiodata = "userBiodata.dat";
#define fwriteUser fwrite(&dataUser, sizeof(dataUser), 1, fp)
#define fwriteUser2 fwrite(&dataUser, sizeof(dataUser), 1, fp2)
#define freadUser fread(&dataUser, sizeof(dataUser), 1, fp)

//rumah
struct rumahandapartment{
	char lokasi[100], harga[100], besarbangunan[100], tipe[50], waktu[10];
}dataRumah, temp, local[50], local4[50], temp4;
struct rumahandapartment dataApartment, local2[50], temp2,local3[50],temp3; 
FILE *fr;
char *listRumah = "listRumah.dat";
#define fwriteRumah fwrite(&dataRumah, sizeof(dataRumah), 1, fr)
#define freadRumah fread(&dataRumah, sizeof(dataRumah), 1, fr)
#define fwriteRumah2 fwrite(&dataRumah, sizeof(dataRumah), 1, fp2)

FILE *fr2;
char *listApartment = "listApartment.dat";
#define fwriteApartment fwrite(&dataApartment, sizeof(dataApartment), 1, fr2)
#define freadApartment fread(&dataApartment, sizeof(dataApartment), 1, fr2)
#define fwriteApartment2 fwrite(&dataApartment, sizeof(dataApartment), 1, fp2)

//FUNGSI MENU

int main(){
    TitleMain();
    int pilihan = InputPilihanMain();
    while(pilihan != 4){
	    switch(pilihan){
	        case 1 : 
	            printf("Menuju menu ADMIN !! \n");
	            cls();
	            AdminMenu();
	            break;
	        case 2 : 
	            printf("Menuju menu USER !! \n");
	            cls();
	            UserMenu();
	            break;
	        
	        case 3: 
	            printf("Menuju menu REGISTRASI !! \n");
	            cls();
	            RegisterUser();
	            break;
	        case 0: 
	        	printf("Pilihan Salah !! \n");
	        	break;
	    }
	    cls();
	    TitleMain();
	    pilihan = InputPilihanMain();
	}
	if(pilihan == 4){
		printf("Yakin akan keluar ?(Y/N) \n");
		PilihanKeluar();
	}
    return 0;
}

void AdminMenu(){
	TitleAdmin();
	int success = LoginAdmin();
	if(success)
 		{
	 	int pilihan = InputPilihanAdmin();
		while(pilihan != 4){
			switch(pilihan){
				case 1 :
						cls();
						UserAccAdmin();
						break;
				case 2 :
						cls();
						ListRumahAdmin();
						break;
				case 3 :
						cls();
						ListApartmentAdmin();
						break;
				case 0 : 
						printf("Pilihan Salah!!\n");
						break;			
			}
			cls();
			TitleAdmin();
			pilihan = InputPilihanAdmin();
		}
		if(pilihan == 4){
			printf("\nLogging Out\n");
			cls();
		}
	}
}

void UserAccAdmin(){
	int pilihan = PilihanAccAdmin();
	while(pilihan != 3){ 
    	switch(pilihan){
    		case 1 :
    				cls();
    				LihatAkun();
    				break;
    				
    		case 2 : 
    				cls();
    				HapusAkun();
    				break;
    		
    		case 0 : 
    				printf("\nPilihan salah !! \n");
    				break;
		}
		cls();
		pilihan = PilihanAccAdmin();
	}
	if(pilihan == 3){
		printf("Back To Admin Menu\n");
    	cls();
	}
}

void ListRumahAdmin(){
	int pilihan = InputPilihanListRumahAdmin();
	while(pilihan != 5){ 
    	switch(pilihan){
    		case 1 :
    				cls();
    				InputListRumah();
    				break;
    				
    		case 2 : 
    				cls();
    				MenghapusListRumah();
    				break;
    		case 3 : 
    				cls();
    				LihatListRumahJual();
    				break;
    		case 4 : 
					cls();
					LihatListRumahSewa();
					break;
    		case 0 : 
    				printf("\nPilihan salah !! \n");
    				break;
		}
		cls();
		pilihan = InputPilihanListRumahAdmin();
	}
	if(pilihan == 5){
		printf("Back To Admin Menu\n");
    	cls();
	}
}

void ListApartmentAdmin(){
	int pilihan = InputPilihanListApartmentAdmin();
	while(pilihan != 5){ 
    	switch(pilihan){
    		case 1 :
    				cls();
    				InputListApartment();
    				break;
    				
    		case 2 : 
    				cls();
    				MenghapusListApartment();
    				break;
    		case 3 : 
    				cls();
    				LihatListApartmentJual();
    				break;
    		case 4 : 
    				cls();
    				LihatListApartmentSewa();
    				break;
    				
    		case 0 : 
    				printf("\nPilihan salah !! \n");
    				break;
		}
		cls();
		pilihan = InputPilihanListApartmentAdmin();
	}
	if(pilihan == 5){
		printf("Back To Admin Menu\n");
    	cls();
	}
}



//FUNGSI TITLE

void TitleMain(){
    char *judul = 
" ____      ____      __                                       _                    \n"
"|_  _|    |_  _|    [  |                                     / |_                  \n"
"  \\ \\  /\\  / /.---.  | |  .---.   .--.   _ .--..--.  .---.  `| |-' .--.            \n"
"   \\ \\/  \\/ // /__\\  | | / /'`\\]/ .'`\\ \\[ `.-. .-. |/ /__\\  | | / .'`\\ \\          \n"
"    \\  /\\  / | \\__., | | | \\__. | \\__. | | | | | | || \\__.,  | |,| \\__. |          \n"
"     \\/  \\/   '.__.'[___]'.___.' '.__.' [___||__||__]'.__.'  \\__/ '.__.'           \n"
" ______    _  _______                  __   ________         _          _          \n"
"|_   _ `. | ||_   __ \\                [  | |_   __  |       / |_       / |_        \n"
"  | | `. \\_|  | |__) |  .---.  ,--.   | |   | |_ \\_| .--. `| |-',--. `| |-'.---.  \n"
"  | |  | |     |  __ /  / /__\\`'_\\ :  | |   |  _| _ ( (`\\] | | `'_\\ : | | / /__\\ \n"
" _| |_.' /    _| |  \\ \\_| \\__.,// | |, | |  _| |__/ | `'.'. | |,// | |,| |,| \\__., \n"
"|______.'    |____| |___|'.__.'\'-;__/[___]|________|[\\__) )\\__/\'-;__/\\__/ '.__.' \n"
"                                                                                   "; 
puts(judul);
}

void TitleAdmin(){
	char *title = 
"		     _       _           _         __  __           \n"       
"    / \\   __| |_ __ ___ (_)_ __   |  \\/  | ___ _ __  _   _ \n"
"   / _ \\ / _` | '_ ` _ \\| | '_ \\  | |\\/| |/ _ \\ '_ \\| | | |\n"
"  / ___ \\ (_| | | | | | | | | | | | |  | |  __/ | | | |_| |\n"
" /_/   \\_\\__,_|_| |_| |_|_|_| |_| |_|  |_|\\___|_| |_|\\__,_|\n"
"                                                             ";
	puts(title);
}

void TitleRegist(){
	char *title = 
"											 \n"
"  ____            _     _                 _ \n"
" |  _ \\ ___  __ _(_)___| |_ _ __ __ _ ___(_)\n"
" | |_) / _ \\/ _` | / __| __| '__/ _` / __| |\n"
" |  _ <  __/ (_| | \\__ \\ |_| | | (_| \\__ \\ |\n"
" |_| \\_\\___|\\__, |_|___/\\__|_|  \\__,_|___/_|\n"
"            |___/                           \n"
"                                              ";
	puts(title);
}

void TitleInputListRumah(){
	printf("\nList Rumah\n");
}

void TitleInputListApartment(){
	printf("\nList Apartment!\n");
}


//FUNGSI DISPLAY

void DisplayMain(){
    char *display =
    "===============   MAIN MENU   ===============   \n"
    "|       1. ADMIN                             |  \n"
    "|       2. USER                              |  \n"
    "|       3. REGISTRASI                        |  \n"
    "|       4. EXIT                              |  \n"
    "=============================================     ";
    puts(display);
}

void DisplayAdmin(){
	char *display =
    "===============   ADMIN MENU   ===============   \n"
    "|       1. MELIHAT & MENGHAPUS AKUN          |  \n"
    "|       2. LIST PROPERTY RUMAH               |  \n"
    "|       3. LIST PROPERTY APARMENT            |  \n"
    "|       4. LOG OUT                           |  \n"
    "=============================================     ";
    puts(display);
}

void DisplayAccAdmin(){
	char *display =
	   "===============   LIHAT AKUN   ===============   \n"
	    "|       1. MELIHAT AKUN USER                 |  \n"
	    "|       2. MENGHAPUS AKUN USER               |  \n"
	    "|       3. KEMBALI                           |  \n"
	    "=============================================     ";
	    puts(display);
}

void DisplayListRumahAdmin(){
	char *display =
	    "=================   RUMAH   =================   \n"
	    "|       1. INPUT LIST RUMAH                  |  \n"
	    "|       2. MENGHAPUS LIST                    |  \n"
	    "|       3. MELIHAT LIST JUAL                 |  \n"
	    "|       4. MELIHAT LIST SEWA                 |  \n"
	    "|       5. KEMBALI                           |  \n"
	    "=============================================     ";
	    puts(display);
}

void DisplayListApartmentAdmin(){
	char *display = 
	"=================   APARTMENT   =================   \n"
	    "|       1. INPUT LIST APARTMENT              |  \n"
	    "|       2. MENGHAPUS LIST                    |  \n"
	    "|       3. MELIHAT LIST JUAL                 |  \n"
	    "|       4. MELIHAT LIST SEWA                 |  \n"
	    "|       5. KEMBALI                           |  \n"
	    "=============================================     ";
	    puts(display);
}


//FUNGSI INPUT PILIHAN

int InputPilihanMain(){
	int pilihan, min = 1, max = 4;
	DisplayMain();
	printf("Input Pilihan: ");
        scanf("%d", &pilihan);getchar();
	if(pilihan >= min && pilihan <= max){
		return pilihan;
	}
	else return 0;
}

int InputPilihanAdmin(){
	int pilihan, min = 1, max = 4;
	DisplayAdmin();
	printf("Input Pilihan: ");
        scanf("%d", &pilihan);getchar();
	if(pilihan >= min && pilihan <= max){
		return pilihan;
	}
	else return 0;
}

int PilihanAccAdmin(){
	int pilihan, min = 1, max = 3;
	DisplayAccAdmin();
	printf("Input Pilihan: ");
        scanf("%d", &pilihan);getchar();
	if(pilihan >= min && pilihan <= max){
		return pilihan;
	}
	else return 0;
}

int InputPilihanListRumahAdmin(){
	int pilihan, min = 1, max = 5;
	DisplayListRumahAdmin();
	printf("Input Pilihan: ");
        scanf("%d", &pilihan);getchar();
	if(pilihan >= min && pilihan <= max){
		return pilihan;
	}
	else return 0;
}

int InputPilihanListApartmentAdmin(){
	int pilihan, min = 1, max = 5;
	DisplayListApartmentAdmin();
	printf("Input Pilihan: ");
        scanf("%d", &pilihan);getchar();
	if(pilihan >= min && pilihan <= max){
		return pilihan;
	}
	else return 0;
}


//FUNGSI PEMBANTU

void cls(){
    system("pause");
    system("cls");
}

void PilihanKeluar(){
    getchar();
    char pilihan;
    scanf("%c", &pilihan);
    if(pilihan == 'Y'){
        exit(0);
    }
    else if(pilihan == 'N'){
        printf("Tidak jadi keluar !!\n");
        cls();
        main();
    }
}

//FUNGSI SORT DATA

int SortDataListRumahJual(){
	int n = 0;
	
	fr = fopen(listRumah, "rb");
	while(freadRumah == 1){
		if(strcasecmp(dataRumah.tipe,"jual") == 0){
			local[n] = dataRumah;
			n++;
		}
	}
	fclose(fr);
	
	for(int i = n-1 ; i >= 1 ; i-- ){
		for(int j = 1 ; j <= i ; j++ ){
			if(strcmp(local[j-1].harga,local[j].harga) > 0){
				temp = local[j-1];
				local[j-1] = local[j];
				local[j] = temp;
			}
		}
	}
	return n;
}

int SortDataListRumahSewa(){
	int n = 0;
	
	fr = fopen(listRumah, "rb");
	while(freadRumah == 1){
		if(strcasecmp(dataRumah.tipe,"jual") != 0){
			local4[n] = dataRumah;
			n++;
		}
	}
	fclose(fr);
	
	for(int i = n-1 ; i >= 1 ; i-- ){
		for(int j = 1 ; j <= i ; j++ ){
			if(strcmp(local4[j-1].waktu,local4[j].waktu) > 0){
				temp4 = local4[j-1];
				local4[j-1] = local4[j];
				local4[j] = temp4;
			}
		}
	}
	return n;
}

int SortDataListApartmentJual(){
	int n = 0;
	
	fr2 = fopen(listApartment, "rb");
	while(freadApartment == 1){
		if(strcasecmp(dataApartment.tipe,"jual") == 0){
			local2[n] = dataRumah;
			n++;
		}
	}
	fclose(fr2);
	
	for(int i = n-1 ; i >= 1 ; i-- ){
		for(int j = 1 ; j <= i ; j++ ){
			if(strcmp(local2[j-1].harga,local2[j].harga) > 0){
				temp2 = local2[j-1];
				local2[j-1] = local2[j];
				local2[j] = temp2;
			}
		}
	}
	return n;
}

int SortDataListApartmentSewa(){
	int n = 0;
	
	fr2 = fopen(listApartment, "rb");
	while(freadApartment == 1){
		if(strcasecmp(dataApartment.tipe,"jual") != 0){
			local3[n] = dataApartment;
			n++;                                           
		}
	}
	
	for(int i = n-1 ; i >= 1 ; i-- ){
		for(int j = 1 ; j <= i ; j++ ){
			if(strcmp(local3[j-1].waktu,local3[j].waktu) > 0){
				temp3 = local3[j-1];
				local3[j-1] = local3[j];
				local3[j] = temp3;
			}
		}
	}
	return n;
}

//FUNGSI ADMIN

int LoginAdmin(){
	int count = 0, success=0;
	char Username[] = "admin", Password[] = "admin";
	char InputUser[50], InputPass[50];
	
	do{
		printf("=============== Silahkan Login! ===============");
		printf("\n| Masukkan Username : ");gets(InputUser);
		printf("\n| Masukkan Password : ");gets(InputPass);
		
		if(strcmp(InputUser,Username) == 0 && strcmp(InputPass,Password) == 0){
			printf("\n LOGIN BERHASIL \n");
			cls();
			success = 1;
			break;
		}
		else{
			printf("\n USERNAME atau PASSWORD SALAH !! \n Silahkan coba kembali !\n");
			cls();
			count++;
		}
	}while(count < 3 && !success);
	if (count == 3 && success == 0){
		printf("Percobaan Telah Habis !\n");
		printf("Kembali ke Main Menu \n");
		cls();
		
	}
	return success;
}

void LihatAkun(){
	int i = 1;
	fp = fopen(userBiodata,"rb");
	while(freadUser == 1){
		printf("Data ke %d \n", i);
		printf("Username\t: %s\n", dataUser.username);
		printf("Password\t: %s\n", dataUser.password);
		printf("Nama\t\t: %s\n", dataUser.nama);
		printf("Tanggal Lahir\t: %s\n",dataUser.tanggallahir);
		printf("Umur\t\t: %d\n",dataUser.umur);
		printf("Kewarganegaraan (WNA/WNI): %s\n",dataUser.kewarganegaraan);
		i++;
	}
	fclose(fp);
}

void HapusAkun(){
	int hapus = 0;
	char pilihan[50];
	LihatAkun();
	printf("Masukkan nama yang ingin dihapus: ");
		gets(pilihan);
	fp = fopen(userBiodata, "rb");
	fp2 = fopen(tempFile, "wb");
	
	while(freadUser == 1){
		if(strcmp(dataUser.nama,pilihan)){
			fwriteUser2;
		}
		else { 
			printf("Akun %s akan dihapus!\n", dataUser.nama);
			hapus = 1;
		}
	}
	fclose(fp);
	fclose(fp2);
	
	remove(userBiodata);
	rename(tempFile, userBiodata);
	if(!hapus){
		printf("Akun %s tidak ditemukan !\n", pilihan);
	}
}

void InputListRumah(){
	TitleInputListRumah();
	fr = fopen(listRumah,"ab");
	printf("Besar Bangunan\t: ");
		gets(dataRumah.besarbangunan);
	printf("Lokasi\t\t: ");
		gets(dataRumah.lokasi);
	printf("Harga\t\t: ");
		gets(dataRumah.harga);
	printf("sewa/jual: ");
		gets(dataRumah.tipe);
	if(strcasecmp(dataRumah.tipe,"sewa")==0){
		printf("Lama sewa\t: ");
			gets(dataRumah.waktu);
	}
	fwriteRumah;
	fclose(fr);
}

void LihatListRumah(){
	int i = 1;
	fr = fopen(listRumah, "rb");
	while(freadRumah == 1){
		printf("\nData ke %d \n", i);
		printf("Besar Bangunan\t: %s \n",dataRumah.besarbangunan);
		printf("Lokasi\t\t: %s \n",dataRumah.lokasi);
		printf("Harga\t\t: %s \n",dataRumah.harga);
		printf("sewa/jual\t: %s \n",dataRumah.tipe);
		if(strcasecmp(dataRumah.tipe,"sewa")==0){
			printf("Lama sewa\t: %s \n", dataRumah.waktu);
		}
		i++;
	}
	fclose(fr);
}

void MenghapusListRumah(){
	int hapus = 0;
	char pilihan[50];
	LihatListRumah();
	printf("Masukkan lokasi rumah yang ingin dihapus: ");
		gets(pilihan);
	fr = fopen(listRumah, "rb");
	fp2 = fopen(tempFile, "wb");
	
	while(freadRumah == 1){
		if(strcmp(dataRumah.lokasi,pilihan)){
			fwriteRumah2;
		}
		else { 
			printf("Rumah berlokai di %s akan dihapus dari list!\n", dataRumah.lokasi);
			hapus = 1;
		}
	}
	fclose(fr);
	fclose(fp2);
	
	remove(listRumah);
	rename(tempFile, listRumah);
	if(!hapus){
		printf("Rumah berlokasi di %s tidak ditemukan !\n", pilihan);
	}
}

void LihatListRumahJual(){
	int max = SortDataListRumahJual();
	for(int i = 0 ; i < max ; i++){
		printf("\nData ke %d\n", i+1);
		printf("Besar Bangunan\t: %s \n",local[i].besarbangunan);
		printf("Lokasi\t\t: %s \n", local[i].lokasi);
		printf("Harga\t\t: %s \n",local[i].harga);
		printf("sewa/jual\t: %s \n",local[i].tipe);
	}
}

void LihatListRumahSewa(){
	int max = SortDataListRumahSewa();
	for(int i = 0 ; i < max ; i++){
		printf("\nData ke %d\n", i+1);
		printf("Besar Bangunan\t: %s \n",local4[i].besarbangunan);
		printf("Lokasi\t\t: %s \n", local4[i].lokasi);
		printf("Harga\t\t: %s \n",local4[i].harga);
		printf("sewa/jual\t: %s \n",local4[i].tipe);
		printf("Lama sewa\t: %s \n",local4[i].waktu);
	}
}

void InputListApartment(){
	TitleInputListApartment();
	fr2 = fopen(listApartment,"ab");
	printf("Besar Apartment\t: ");
		gets(dataApartment.besarbangunan);
	printf("Lokasi\t\t: ");
		gets(dataApartment.lokasi);
	printf("Harga\t\t: ");
		gets(dataApartment.harga);
	printf("sewa/jual\t: ");
		gets(dataApartment.tipe);
	if(strcmp(dataApartment.tipe,"jual")){
		printf("Lama sewa\t: ");
			gets(dataApartment.waktu);
	}
	fwriteApartment;
	fclose(fr2);
}

void LihatListApartment(){
	int i = 1;
	fr2 = fopen(listApartment,"rb");
	while(freadApartment == 1){
		printf("\nData ke %d \n", i);
		printf("Besar Apartment\t: %s \n",dataApartment.besarbangunan);
		printf("Lokasi\t\t: %s \n",dataApartment.lokasi);
		printf("Harga\t\t: %s \n",dataApartment.harga);
		printf("sewa/jual\t: %s \n",dataApartment.tipe);
		if(strcasecmp(dataApartment.tipe,"sewa")==0){
			printf("Lama sewa\t: %s \n", dataApartment.waktu);
		}
		i++;
	}
	fclose(fr2);
}

void MenghapusListApartment(){
	int hapus = 0;
	char pilihan[50];
	LihatListApartment();
	printf("Masukkan lokasi Apartment yang ingin dihapus: ");
		gets(pilihan);
	fr2 = fopen(listApartment, "rb");
	fp2 = fopen(tempFile, "wb");
	
	while(freadApartment == 1){
		if(strcmp(dataApartment.lokasi,pilihan)){
			fwriteApartment2;
		}
		else { 
			printf("Apartment berlokai di %s akan dihapus dari list!\n", dataApartment.lokasi);
			hapus = 1;
		}
	}
	fclose(fr2);
	fclose(fp2);
	
	remove(listApartment);
	rename(tempFile, listApartment);
	if(!hapus){
		printf("Apartment berlokasi di %s tidak ditemukan !\n", pilihan);
	}
}

void LihatListApartmentJual(){
	int max = SortDataListApartmentJual();
	for(int i = 0 ; i < max ; i++){
		printf("\nData ke %d\n", i+1);
		printf("Besar Apartment\t: %s \n",local2[i].besarbangunan);
		printf("Lokasi\t\t: %s \n", local2[i].lokasi);
		printf("Harga\t\t: %s \n",local2[i].harga);
		printf("sewa/jual\t: %s \n",local2[i].tipe);
	}
}

void LihatListApartmentSewa(){
	int max = SortDataListApartmentSewa();
	for(int i = 0 ; i < max ; i++){
		printf("\nData ke %d\n", i+1);
		printf("Besar Apartment\t: %s \n",local3[i].besarbangunan);
		printf("Lokasi\t\t: %s \n", local3[i].lokasi);
		printf("Harga\t\t: %s \n", local3[i].harga);
		printf("sewa/jual\t: %s \n", local3[i].tipe);
		printf("Lama sewa\t: %s \n", local3[i].waktu);
	}
}


//FUNGSI USER

void UserMenu(){
	printf("Test \n");
}




//FUNGSI REGISTER USER
void RegisterUser(){
	int pilihan;
	TitleRegist();
	fp = fopen(userBiodata,"ab");

	printf("Username\t: ");
		gets(dataUser.username);
	printf("Password\t: ");
		gets(dataUser.password);
	printf("\n====== Input Biodata ======\n");
	printf("Nama\t\t: ");
		gets(dataUser.nama);
	printf("Tanggal Lahir\t: ");
		gets(dataUser.tanggallahir);
	printf("Umur\t\t: ");
		scanf("%d", &dataUser.umur);getchar();
	printf("Kewarganegaraan (WNA/WNI): ");
		gets(dataUser.kewarganegaraan);
	if(strcasecmp(dataUser.kewarganegaraan,"WNA")==0){
		printf("No Passport\t: ");
		gets(dataUser.passport);
	}else strcpy(dataUser.passport, " - ");
	fwriteUser;
	fclose(fp);
	do{
	printf("\n====== Pilihan ======\n");
	printf("|   1. Menu User       |\n");
	printf("|   2. Main Menu       |\n");
	printf("Input Pilihan: ");
		scanf("%d", &pilihan);getchar();
	switch(pilihan){
		case 1 : 
				printf("Menuju menu USER !! \n");
	            cls();
	            UserMenu();
	            break;
	    case 2 :
				printf("Kembali ke Main menu !!\n");
	    		cls();
	    		main();
	    		break;
	    	}
	system("cls");
	}while(pilihan != 2);
}

