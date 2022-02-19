/*
	Nama	:- Leonardo Siagian			(11319017)
			 - Evan Richardo Sianipar	(11319019)
			 - Alex Sander Hutapea		(11319014)
	Kelas	: 31TI1
*/
#include "stdio.h"
#include "string.h"
#include "stdlib.h"
typedef struct temp x;
struct temp{
	FILE * INDO;
	FILE * BATAK;
	FILE * SIMPAN;
	char *kata_indo;
	char *kata_batak;
};
void judulProyek();
void PilihanProgramUser();
void menu1(x * all);
void menu2(x * all);
void menu3(x * all);
void menu4(x * all);
void menu5(x * all);
void menu6(x * all);
