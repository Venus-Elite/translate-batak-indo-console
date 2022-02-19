//Start Open Project ALS
#ifndef PROJECT_ALS
#define PROJECT_ALS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>

//file batak
typedef struct SBatak Batak;
typedef struct SIndo Indo;

struct SBatak
{
	FILE *BATAK;
	char *tmpBatak;
};

typedef Batak aksesBatak;

//file indo
struct SIndo{
	FILE *INDO;
	char *tmpIndo;
};

typedef Indo aksesIndo;

//Record Data
typedef struct SRecord Record;
struct SRecord{
	FILE *indobatak;
	FILE *batakindo;
	FILE *Kindobatak;
	FILE *Kbatakindo;
};

//pembaharuan
//File Kalimat Indo
typedef struct SKalimat KALIMAT;
struct SKalimat{
	FILE *SKINDO;
	char *tmpSKIndo;
	FILE *SKBATAK;
	char *tmpSKBatak;
};
//End Kalimat

//macro revisi kalimat
//if struct is sentence || sentence2
#define getSIfile sentence->SKINDO
#define getSBfile sentence2->SKBATAK
#define getSIvar sentence->tmpSKIndo
#define getSBvar sentence2->tmpSKBatak

//Macro Akses
//if struct is rec
//record data
#define recI_B rec->indobatak
#define recB_I rec->batakindo
//if Struct is ptr
#define getBfile ptr->BATAK
#define getBvar ptr->tmpBatak
#define getIfile ptr->INDO
#define getIvar ptr->tmpIndo
//if Struct is ptr2
#define getBfile2 ptr2->BATAK
#define getBvar2 ptr2->tmpBatak
#define getIfile2 ptr2->INDO
#define getIvar2 ptr2->tmpIndo

//Deklarasi Prototype
int isAvailable(Batak *akses);
void ShowContentI(Indo *ptr);
void ShowContentB(Batak *ptr);
void BatakIndo(aksesBatak *ptr,aksesIndo *ptr2);
void IndoBatak(aksesIndo *ptr,aksesBatak *ptr2);
void TampilBatak(aksesBatak * ptr);
void TampilIndo(aksesIndo * ptr);
void TranslateI_B(aksesIndo *ptr,aksesBatak *ptr2,char *ind);
void TranslateB_I(aksesBatak *ptr,aksesIndo *ptr2,char *btk);
char *pathDataIndo();
char *pathDataBatak();
void *bacadataindo(Indo *ptr,Indo *ptr2);
void *bacadatabatak(Batak *ptr,Batak *ptr2);
void *RecordDataI_B(Indo *ptr,Batak *ptr2,char *ind,Record *rec);
void *RecordDataB_I(Batak *ptr,Indo *ptr2,char *btk,Record *rec);
void TranslateKalimatI_B(aksesIndo *ptr,aksesBatak *ptr2,char *ind);
void RecordKalimatI_B(Indo *ptr,Batak *ptr2,char *ind,Record *rec);

//Prototype perbaikan translate kalimat
char *pathKIndo();
char *pathKBatak();
void *bacadataKindo(KALIMAT *sentence,KALIMAT *sentence2);
void TranslateKI_B(KALIMAT *sentence,KALIMAT *sentence2,Record *rec, char *ind);
#endif //PROJECT_ALS
