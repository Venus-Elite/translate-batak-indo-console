#include "Header006.h"
//helper prototype Translate Sentence
//implement  prototype
// void TranslateKalimatI_B(aksesIndo *ptr,aksesBatak *ptr2,char *ind)
// {
//     bacadataindo(ptr,ptr);
//     bacadatabatak(ptr2,ptr2);

// 	if(getIfile == NULL || getBfile2 == NULL)
// 	{
// 		printf("Unknown Database !!!!!\n");
// 	}
// 	else
// 	{
// 	//split kalimat
// 	char *DupInd;
// 	int z,y;
// 	//var array kalimat
// 	int indexesI = 1;
// 	char SplitKalimat[100][100];
// 	DupInd = strtok(ind,"\n");
// 	while(DupInd != NULL)
// 	{
// 		strcpy(SplitKalimat[indexesI],DupInd);
// 		DupInd = strtok(NULL,"\n");
// 		indexesI++;
// 	}
// 	//end split kalimat
	
// 	//tmp 
// 	char temprory[10000][100];
// 	char temprory2[10000][100];
// 	//Tmp String kalimat
// 	char MainTemprory[10000];
// 	char *brankas;
// 	char *token;
// 	int loop;
// 	int index = 1;
// 	int keyword = 1;
// 	while(!feof(getIfile) && !feof(getBfile2))
// 	{
// 	   fgets(getIvar,sizeof(temprory),getIfile);  //untuk database indo
// 	   fgets(getBvar2,sizeof(temprory2),getBfile2); //untuk database batak //aku suka kamu
// 	   strcpy(temprory[index],getIvar);
// 	   strcpy(temprory2[index],getBvar2);
// 	   index++;
// 	}
// 	int unique;
// 		char *splitter;
// 		char *tokensplit;
// 		char kalimatbatak[100];
// 		char kalimatindo[100];
// 	for(z=1;z<=indexesI;z++){
// 	for(loop=1;loop<10000;loop++){
		
// 		if(strcmp(SplitKalimat[z],temprory[loop])==0)
// 		{
// 			// strcpy(MainTemprory,temprory2[loop]);
// 			printf("Kata Indo :");
// 			printf("%s ",ind);
// 			printf("Translate batak :");
// 			printf("%s ",temprory2[loop]);
// 			printf("\n");
// 			unique = loop;
// 			printf("Unique = %d\n",unique);
// 			++z;
// 			break;
// 		}
// 		else{
// 			keyword++;
// 		}
// 	}
// 	}
// 	//if Word Not in Database
// 	if(keyword == 10000){
// 				printf("Tidak ada kata yang cocok :(!!!\n");
// 			}

// 	fclose(getIfile);
// 	fclose(getBfile2);

// 	}

// }

void RecordKalimatI_B(Indo *ptr,Batak *ptr2,char *ind,Record *rec){
	FILE *header;
	header = fopen("Hasil_Translasi/Kalimat_indonesia_ke_batak.txt","r");
	//fill into text in header of file
	if(header == NULL){
		rec->Kindobatak = fopen("Hasil_Translasi/Kalimat_indonesia_ke_batak.txt","a+"); 
		fprintf(rec->Kindobatak,"------------------------------------\n");
		fprintf(rec->Kindobatak,"INDO|BATAK|UniqueKey\n");
		fprintf(rec->Kindobatak,"------------------------------------\n");
	}
	else{
		rec->Kindobatak = fopen("Hasil_Translasi/Kalimat_indonesia_ke_batak.txt","a+"); //a+ to add data in end of file
		bacadataindo(ptr,ptr);
		bacadatabatak(ptr2,ptr2);
		if(getIfile == NULL || getBfile2 == NULL)
		{
			printf("Unknown Database !!!!!\n");
		}
		else{
			char *DupInd;
	int z,y;
	//var array kalimat
	int indexesI = 1;
	char SplitKalimat[100][100];
	DupInd = strtok(ind," ");
	while(DupInd != NULL)
	{
		strcpy(SplitKalimat[indexesI],DupInd);
		DupInd = strtok(NULL," ");
		indexesI++;
	}
	//end split kalimat
	
	//tmp 
	char temprory[10000][100];
	char temprory2[10000][100];
	//Tmp String kalimat
	char *MainTemprory;
	MainTemprory = (char*)malloc(sizeof(char)*10000);
	char *brankas;
	char *token;
	int loop;
	int index = 1;
	int keyword = 1;
	while(!feof(getIfile) && !feof(getBfile2))
	{
	   fgets(getIvar,sizeof(temprory),getIfile);  //untuk database indo
	   fgets(getBvar2,sizeof(temprory2),getBfile2); //untuk database batak
	   strcpy(temprory[index],getIvar);
	   strcpy(temprory2[index],getBvar2);
	   index++;
	}
	int unique;
		char *splitter;
		char *tokensplit;
	for(z=1;z<=indexesI;z++){
	for(loop=1;loop<10000;loop++){
		
		if(strcmp(ind,temprory[loop])==0)
		{
			// strcpy(MainTemprory,temprory2[loop]);
			fprintf(rec->Kindobatak,"%s ",SplitKalimat[y]);
			fprintf(rec->Kindobatak,"\t%s",temprory2[y]);
			unique = loop;
			fprintf(rec->Kindobatak,"\t%d",unique);
			break;
		}
		
		else{
			keyword++;
		}
	
	}
	}
	//if Word Not in Database
	if(keyword == 10000){
				printf("Tidak ada kata yang cocok :(!!!\n");
			}

	fclose(getIfile);
	fclose(getBfile2);

	}
		}
	}


	//Revisi
void TranslateKI_B(KALIMAT *sentence,KALIMAT *sentence2,Record *rec, char *ind){
	bacadataKindo(sentence,sentence2);
	FILE *header;
	header = fopen("Hasil_Translasi/Kalimat_indonesia_ke_batak.txt","r");
	//fill into text in header of file
	if(header == NULL){
		rec->Kindobatak = fopen("Hasil_Translasi/Kalimat_indonesia_ke_batak.txt","a+"); 
		fprintf(rec->Kindobatak,"------------------------------------\n");
		fprintf(rec->Kindobatak,"Data Translasi Kalimat\n");
		fprintf(rec->Kindobatak,"------------------------------------\n");
	}
	if(getSIfile == NULL || getSBfile == NULL)
	{
		printf("Unknown Database !!!!!\n");
	}
	else
	{
	rec->Kindobatak = fopen("Hasil_Translasi/Kalimat_indonesia_ke_batak.txt","a+");
	//split kalimat
	int z,y;
	
	
	//tmp 
	char temprory[10000][100];
	char temprory2[10000][100];
	//Tmp String kalimat
	char MainTemprory[10000];
	char *brankas;
	char *token;
	int loop;
	int index = 1;
	int keyword = 1;
	while(!feof(getSIfile) && !feof(getSBfile))
	{
	   fgets(getSIvar,sizeof(temprory),getSIfile);  //untuk database indo
	   fgets(getSBvar,sizeof(temprory2),getSBfile); //untuk database batak
	   strcpy(temprory[index],getSIvar);
	   strcpy(temprory2[index],getSBvar);
	   index++;
	}
	int unique;
		char *splitter;
		char *tokensplit;
		char kalimatbatak[100];
		char kalimatindo[100];
	for(loop=1;loop<10000;loop++){
		
		if(strcmp(ind,temprory[loop])==0)
		{
			// strcpy(MainTemprory,temprory2[loop]);
			char optionr;
			printf("Kata Indo :");
			printf("%s ",ind);
			printf("Translate batak :");
			printf("%s ",temprory2[loop]);
			printf("\n");
			unique = loop;
			printf("Unique = %d\n",unique);
			printf("\nRecord Data [Y/N]? =>");
			scanf("%s",&optionr);
			if(optionr == 'y' || optionr == 'Y'){
				fprintf(rec->Kindobatak,"INDO : %s",ind);
				fprintf(rec->Kindobatak,"BATAK : %s\n",temprory2[loop]);
				fprintf(rec->Kindobatak,"UNIQUE : %d\n",loop);
				fprintf(rec->Kindobatak,"-----------------------------------------------\n\n");
			}
			else
			break;
		}
		else{
			keyword++;
		}
	}
	//if Word Not in Database
	if(keyword == 10000){
				printf("Tidak ada kata yang cocok :(!!!\n");
			}

	fclose(getSIfile);
	fclose(getSBfile);

	}

	}