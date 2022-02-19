/*
	Nama	:- Leonardo Siagian			(11319017)
			 - Evan Richardo Sianipar	(11319019)
			 - Alex Sander Hutapea		(11319014)
	Kelas	: 31TI1
*/
#include "header.h"
void judulProyek(){
	system("cls");
	puts("*=======================================================================*");
	puts("*=======================================================================*");
	puts("*==== Selamata Datang di Program Terjemahan Kata Indonesia ke Batak ====*");
	puts("*=======================================================================*");
	puts("*=======================================================================*");	
}

void PilihanProgramUser(){
	puts("\n\n1. Translate Kata Indonesia ke Batak");
	puts("2. Translate Kata Batak ke Indonesia");
	puts("3. List Daftar Isi Kamus Indonesia ke Batak");
	puts("4. List Daftar Isi Kamus Batak ke Indonesia");
	puts("5. Cerita Bahasa Indonesia ke Batak");
	puts("6. Cerita Bahasa Batak ke Indonesia");
	puts("7. Keluar Program");
	printf("Pilihan			: ");
}

void messageNotFindWord(){
	puts("\n\n\n-*-*-*-*-*-*-*-*-*-*-*-*");
	puts("Maaf kata belum tersedia");
	puts("-*-*-*-*-*-*-*-*-*-*-*-*");
}

void menu1(x * all){
	char input[100];
	all->INDO = fopen("perkata/kata_indonesia.txt", "r");
	all->BATAK = fopen("perkata/kata_batak.txt", "r");
	all->SIMPAN = fopen("output/indonesia_ke_batak.txt", "a");
	all->kata_indo = (char*)calloc(100000, sizeof(char));
	all->kata_batak = (char*)calloc(100000, sizeof(char));
	printf("Masukkan kata		: ");
	scanf(" %[^\n]*c", input);
	strlwr(input);
	int find = 1;
	while( !feof(all->INDO) && !feof(all->BATAK)){
		fgets(all->kata_indo, 100000, all->INDO);
		fgets(all->kata_batak, 100000, all->BATAK);
		strtok(all->kata_indo, "\n");
		if(strcmp(all->kata_indo, input) == 0 ){
			fprintf(all->SIMPAN, "%s = %s", all->kata_indo, all->kata_batak);
			puts("\n\n\n-*-*-*-*-*-*-*-*-*-*-*-*");
			printf("Terjemahan		: %s\nJumlah Huruf		: %d\n", all->kata_batak, strlen(all->kata_batak)-1);
			puts("-*-*-*-*-*-*-*-*-*-*-*-*");
			find=0;
		}
	}
	if(find) messageNotFindWord();
}

void menu2(x * all){
	char input[100];
	all->INDO = fopen("perkata/kata_indonesia.txt", "r");
	all->BATAK = fopen("perkata/kata_batak.txt", "r");
	all->SIMPAN = fopen("output/batak_ke_indonesia.txt", "a");
	all->kata_indo = (char*)calloc(100000, sizeof(char));
	all->kata_batak = (char*)calloc(100000, sizeof(char));
	printf("Masukkan kata		: ");
	scanf(" %[^\n]*c", input);
	strlwr(input);
	int find = 1;
	while( !feof(all->INDO) && !feof(all->BATAK)){
		fgets(all->kata_indo, 100000, all->INDO);
		fgets(all->kata_batak, 100000, all->BATAK);
		strtok(all->kata_batak, "\n");
		if(strcmp(all->kata_batak, input) == 0 ){
			fprintf(all->SIMPAN, "%s = %s", all->kata_batak, all->kata_indo);
			puts("\n\n\n-*-*-*-*-*-*-*-*-*-*-*-*");
			printf("Terjemahan		: %s\nJumlah Huruf		: %d\n", all->kata_indo, strlen(all->kata_indo)-1);
			puts("-*-*-*-*-*-*-*-*-*-*-*-*");
			find=0;
		}
	}
	if(find) messageNotFindWord();
}

void menu3(x * all){
	int i, loop = 0;
	all->INDO = fopen("perkata/kata_indonesia.txt", "r");
	all->BATAK = fopen("perkata/kata_batak.txt", "r");
	all->kata_indo = (char*)calloc(100000, sizeof(char));
	all->kata_batak = (char*)calloc(100000, sizeof(char));
	puts("\n\n~|~|~|~|~|~|~|~|~|~|~|~|~|~|~");
		while( !feof(all->INDO) && !feof(all->BATAK)){
			fgets(all->kata_indo, 100000, all->INDO);
			fgets(all->kata_batak, 100000, all->BATAK);
			strtok(all->kata_indo, "\n");
			printf("%d. %s ---> %s", i+1, all->kata_indo, all->kata_batak);
			i++;
		}
		puts("\n~|~|~|~|~|~|~|~|~|~|~|~|~|~|~");
}

void menu4(x * all){
	int i, loop = 0;
	all->INDO = fopen("perkata/kata_indonesia.txt", "r");
	all->BATAK = fopen("perkata/kata_batak.txt", "r");
	all->kata_indo = (char*)calloc(100000, sizeof(char));
	all->kata_batak = (char*)calloc(100000, sizeof(char));
	puts("\n\n~|~|~|~|~|~|~|~|~|~|~|~|~|~|~");
		while( !feof(all->INDO) && !feof(all->BATAK)){
			fgets(all->kata_indo, 100000, all->INDO);
			fgets(all->kata_batak, 100000, all->BATAK);
			strtok(all->kata_batak, "\n");
			printf("%d. %s ---> %s", i+1, all->kata_batak, all->kata_indo);
			i++;
		}
		puts("\n~|~|~|~|~|~|~|~|~|~|~|~|~|~|~");
}

void menu5(x * all){
	all->INDO = fopen("paragraf/kalimat_indo.txt", "r");
	all->BATAK = fopen("paragraf/kalimat_batak.txt", "r");
	all->kata_indo = (char*)calloc(100000, sizeof(char));
	all->kata_batak = (char*)calloc(100000, sizeof(char));
	int i = 0, loop = 0;
	char input[100];
	system("cls");
	puts("\n\t\t\t\t\t\t\t\t\tKINGPIN\n");
	while(!feof(all->INDO)){
		fgets(all->kata_indo, 100000, all->INDO);
		strtok(all->kata_indo, "\n");
		printf("%s ", all->kata_indo);
		i += (strlen(all->kata_indo)+1);
		loop++;
	}
	printf("\nJumlah Array	: %d", loop);
	printf("\nJumlah Character: %d", i);
	puts("\n\n\n==============================================================================================================================================================");
	puts("Terjemahkan ke Batak? (ya) | (tidak)");
	printf("Pilihan			: ");
	scanf(" %[^\n]*c", input);
	if(strcmp(input, "ya") == 0){
		puts("\n\t\t\t\t\t\t\t\t\tKINGPIN\n");
		while(!feof(all->BATAK)){
			fgets(all->kata_batak, 100000, all->BATAK);
			strtok(all->kata_batak, "\n");
			printf("%s ", all->kata_batak);
			i += (strlen(all->kata_batak)+1);
			loop++;
		}
		printf("\nJumlah Array	: %d", loop);
		printf("\nJumlah Character: %d", i);
		puts("\n\n\n==============================================================================================================================================================");
	}
	else if(strcmp(input, "tidak") == 0){
	}
	else{
		puts("Masukan salah!!!");
	}
}

void menu6(x * all){
	all->INDO = fopen("paragraf/kalimat_indo.txt", "r");
	all->BATAK = fopen("paragraf/kalimat_batak.txt", "r");
	all->kata_indo = (char*)calloc(100000, sizeof(char));
	all->kata_batak = (char*)calloc(100000, sizeof(char));
	int i = 0, loop = 0;
	char input[100];
	system("cls");
	puts("\n\t\t\t\t\t\t\t\t\tKINGPIN\n");
	while(!feof(all->BATAK)){
		fgets(all->kata_batak, 100000, all->BATAK);
		strtok(all->kata_batak, "\n");
		printf("%s ", all->kata_batak);
		i += (strlen(all->kata_batak)+1);
		loop++;
	}
	printf("\nJumlah Array	: %d", loop);
	printf("\nJumlah Character: %d", i);
	puts("\n\n\n==============================================================================================================================================================");
	puts("Terjemahkan ke Indonesia? (ya) | (tidak)");
	printf("Pilihan			: ");
	scanf(" %[^\n]*c", input);
	if(strcmp(input, "ya") == 0){
		puts("\n\t\t\t\t\t\t\t\t\tKINGPIN\n");
		while(!feof(all->INDO)){
			fgets(all->kata_indo, 100000, all->INDO);
			strtok(all->kata_indo, "\n");
			printf("%s ", all->kata_indo);
			i += (strlen(all->kata_indo)+1);
			loop++;
		}
		printf("\nJumlah Array	: %d", loop);
		printf("\nJumlah Character: %d", i);
		puts("\n\n\n==============================================================================================================================================================");
	}
	else if(strcmp(input, "tidak") == 0){
	}
	else{
		puts("Masukan salah!!!");
	}
}
