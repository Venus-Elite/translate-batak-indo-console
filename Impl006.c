#include "Header006.h"

//path data content
//path indo
char *pathDataIndo()
{
    char *pathIndo = (char*)malloc(sizeof(char)*100);
    pathIndo = "data_kelompok_006/kata_indonesia.txt";
    return pathIndo;
}
//end path indo

//path batak
char *pathDataBatak()
{
    char *pathBatak = (char*)malloc(sizeof(char)*100);
    pathBatak = "data_kelompok_006/kata_batak.txt";

    return pathBatak;
}
//end path batak

//impl revisi
//path data kalimat indo
char *pathKIndo(){
	char *pi = (char*)malloc(sizeof(char)*100);
	pi = "data_kelompok_006/Content_Kalimat/kalimat_indonesia.txt";
	 return pi;
}

char *pathKBatak(){
	char *pb = (char*)malloc(sizeof(char)*100);
	pb = "data_kelompok_006/Content_Kalimat/kalimat_batak.txt";
	return pb;
}
//end path data
//baca data
void *bacadataKindo(KALIMAT *sentence,KALIMAT *sentence2){
	getSIfile = fopen(pathKIndo(),"r");
	getSIvar = (char*)malloc(sizeof(char)*10000);
	getSBfile = fopen(pathKBatak(),"r");
	getSBvar = (char*)malloc(sizeof(char)*10000);
}
//end baca data
//end Revisi

void *bacadataindo(Indo *ptr,Indo *ptr2){
	if(ptr)
	{
		getIfile = fopen(pathDataIndo(),"r");
		getIvar = (char*)malloc(sizeof(char)*10000);
	}
	else if(ptr2){
		getIfile2 = fopen(pathDataIndo(),"r");
		getIvar2 = (char*)malloc(sizeof(char)*10000);
	}
	
}

void *bacadatabatak(Batak *ptr,Batak *ptr2)
{
	if(ptr){
		getBfile = fopen(pathDataBatak(),"r");
		getBvar = (char*)malloc(sizeof(char)*10000);
	}
	else if(ptr2){
		getBfile2 = fopen(pathDataBatak(),"r");
		getBvar2 = (char*)malloc(sizeof(char)*10000);
	}
	
}

// //Check Total Baris (Scan data menggunakan fgets)
// //total baris Indo
// int Total_Rows_Indo(Indo * ptr){
// 	unsigned int number_of_lines = 0;
// 	unsigned int ch;
// 	bacadataindo(ptr,ptr);
// 	while(EOF != (ch=getc(getIfile)))
// 		if('\n' == ch)
// 			++number_of_lines;
// 	unsigned int jlh_baris = number_of_lines;

// 	return jlh_baris;
// }

// int Total_Rows_CIndo(Indo * ptr){
// 	unsigned int number_of_lines = 0;
// 	unsigned int ch;
// 	bacadataCindo(ptr,ptr);
// 	while(EOF != (ch=getc(getIfile)))
// 		if('\n' == ch)
// 			++number_of_lines;
// 	unsigned int jlh_baris = number_of_lines;

// 	return jlh_baris;
// }

// //Total Baris Batak
// int Total_Rows_Batak(Batak * ptr){
// 	unsigned int number_of_lines = 0;
// 	int ch;
// 	bacadatabatak(ptr,ptr);
// 	while(EOF!=(ch=getc(getBfile)))
// 		if('\n' == ch)
// 			++number_of_lines;
// 	unsigned int jlh_baris = number_of_lines;
// 	return jlh_baris;
// }
// //End Check Total_Rows

//Content Story Indo
void ShowContentI(Indo *ptr){
	getIfile = fopen("data_kelompok_006/Content_Story/028_Vicktor_indo.txt","r");
	getIvar = (char*)malloc(sizeof(char)*10000);
	if(getIfile == NULL){
		printf("Database unknown!!!!!\n");
	}
	else{

	char *original;
	char *token;
	while(!feof(getIfile))
	{
		fgets(getIvar,10000,getIfile);
		original = strdup(getIvar);
		token = strtok(original," ");
		while(token != NULL)
		{
			printf("%s ",token);   //key unik of word list is #
			token = strtok(NULL," ");
		}
	}
	fclose(getIfile);
	}

	free(getIvar);
}

//Content Story Batak
void ShowContentB(Batak *ptr){
	getBfile = fopen("data_kelompok_006/Content_Story/028_Vicktor_Batak.txt","r");
	getBvar = (char*)malloc(sizeof(char)*10000);
	if(getBfile == NULL){
		printf("Database unknown!!!!!\n");
	}
	else{

	char *original;
	char *token;
	while(!feof(getBfile))
	{
		fgets(getBvar,10000,getBfile);
		original = strdup(getBvar);
		token = strtok(original," ");
		while(token != NULL)
		{
			printf("%s ",token);   //key unik of word list is #
			token = strtok(NULL," ");
		}
	}
	fclose(getBfile);
	}

	free(getBvar);
}

void TampilBatak(aksesBatak * ptr)
{
	//parse use strdup + strtok
	getBvar = (char*)malloc(sizeof(char)*10000);
	getBfile = fopen("data_kelompok_006/kata_batak.txt","r");
	if(getBfile == NULL)
	{
		printf("Database unknown!!!!!\n");
	}
	else{

	char *original;
	char *token;
	while(!feof(getBfile))
	{
		fgets(getBvar,10000,getBfile);
		original = strdup(getBvar);
		token = strtok(original,"\n");
		while(token != NULL)
		{
			printf("%s\n",token);   //key unik of word list is #
			token = strtok(NULL,"\n");
		}
	}
	fclose(getBfile);
	}

	free(getBvar);
}

void TampilIndo(aksesIndo * ptr)
{
	//parse use strdup + strtok_r
	getIvar = (char*)malloc(sizeof(char)*10000);
	getIfile = fopen("data_kelompok_006/kata_indonesia.txt","r");
	if(getIfile == NULL){
		printf("Database unknown!!!!!\n");
	}
	else{
	char *brankasI;
	char *token,*newBrankas;
	while(!feof(getIfile))
	{
		fgets(getIvar,10000,getIfile);
		brankasI = strdup(getIvar);
		newBrankas = brankasI;
		while(token = strtok_r(newBrankas,"\n",&newBrankas))
		{
			printf("%s\n",token);
		}
	}
	fclose(getIfile);
	}
	free(getIvar);
}

void IndoBatak(aksesIndo *ptr,aksesBatak *ptr2)
{
	getIvar = (char*)malloc(sizeof(char)*10000);
	getBvar2 = (char*)malloc(sizeof(char)*10000);
	
	getBfile2 = fopen("data_kelompok_006/kata_batak.txt","r");
	getIfile = fopen("data_kelompok_006/kata_indonesia.txt","r");
	if((getBfile2 == NULL || getIfile ==NULL))
	{
		printf("Database unknown!!!!!\n");
	}
	else
	{
	printf("-----------Indo-Batak------------\n");
	while(!feof(getIfile) && !feof(getBfile2))
	{
		fgets(getBvar2,10000,getBfile2);
		fgets(getIvar,10000,getIfile);
		strtok(getIvar,"\n");
		strcat(getIvar,"\t\t\t");
		strtok(getBvar2,"\n");
		// strcat(getBvar2,"\t");
		printf("%s==>%s\n",getIvar,getBvar2);

	}
	fclose(getBfile2);
	fclose(getIfile);
	}
	free(getIvar);
	free(getBvar2);

}

void BatakIndo(aksesBatak *ptr,aksesIndo *ptr2)
{
	getBfile = fopen("data_kelompok_006/kata_batak.txt","r");
	getIfile2 = fopen("data_kelompok_006/kata_indonesia.txt","r");
	getIvar2 = (char*)malloc(sizeof(char)*10000);
	getBvar = (char*)malloc(sizeof(char)*10000);
	if(getBfile == NULL || getIfile2 == NULL)
	{
		printf("Database Unknown!!!!\n");
	}
	else
	{

	while(!feof(getBfile) && !feof(getIfile2))
	{
		fgets(getBvar,10000,getBfile);
		fgets(getIvar2,10000,getIfile2);
		strtok(getBvar,"\n");
		strcat(getBvar,"\t\t\t");
		strtok(getIvar2	,"\n");
		printf("%s==>%s\n",getBvar,getIvar2);
	}
	fclose(getIfile2);
	fclose(getBfile);
	}

	free(getIvar2);
	free(getBvar);
}