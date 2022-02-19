/*
	Nama	:- Leonardo Siagian			(11319017)
			 - Evan Richardo Sianipar	(11319019)
			 - Alex Sander Hutapea		(11319014)
	Kelas	: 31TI1
*/
#include "header.h"
int main(){
	x * data = (x*)malloc(sizeof(x));
	int pilihan;
	judulProyek();
	while(1 == 1){
		PilihanProgramUser();
		scanf("%d", &pilihan);
		if(pilihan == 1){
			menu1(data);
		}
		else if(pilihan == 2){
			menu2(data);
		}
		else if(pilihan == 3){
			menu3(data);
		}
		else if(pilihan == 4){
			menu4(data);
		}
		else if(pilihan == 5){
			menu5(data);
		}
		else if(pilihan == 6){
			menu6(data);
		}
		else if(pilihan == 7){
			exit(1);
		}
		else{
			puts("Masukan anda salah periksa ulang!!!");
		}
	}
	return 0;
}
