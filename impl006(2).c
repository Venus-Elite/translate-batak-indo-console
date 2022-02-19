#include "Header006.h"
void TranslateI_B(aksesIndo *ptr,aksesBatak *ptr2,char *ind)
{
    bacadataindo(ptr,ptr);
    bacadatabatak(ptr2,ptr2);
	if(getIfile == NULL || getBfile2 == NULL)
	{
		printf("Unknown Database !!!!!\n");
	}
	else
	{
	char temprory[10000][15];
	char temprory2[10000][15];
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
	//parse data jika memiliki lebih dari satu translasi
		char *splitter;
		char *tokensplit;
	while(loop != 10000){
		if(strcmp(ind,temprory[loop])==0)
		{
			printf("Kata Indo : %s\n",ind);
			printf("Translate Batak : %s\n",temprory2[loop]);
			printf("\n");
			unique = loop;
			printf("Unique = %d\n",unique);
			break;
		}
		else{
			keyword++;
		}
		loop++;
		
	}
	//if Word Not in Database
	if(keyword == 10000){
				printf("Tidak ada kata yang cocok :(!!!\n");
			}

	fclose(getIfile);
	fclose(getBfile2);

	}

}

void TranslateB_I(aksesBatak *ptr,aksesIndo *ptr2,char *btk){
	bacadataindo(ptr2,ptr2);
    bacadatabatak(ptr,ptr);
	if(getIfile2 == NULL || getBfile == NULL)
	{
		printf("Unknown Database !!!!!\n");
	}
	else
	{
	// 	while(!feof(getIfile))
	// {
	// 	fgets(getIvar,10000,getIfile);
	// 	brankasI = strdup(getIvar);
	// 	newBrankas = brankasI;
	// 	while(token = strtok_r(newBrankas,"\n",&newBrankas))
	// 	{
	// 		printf("%s#",token);
	// 	}
	// }
		char temprory[10000][15];
		char temprory2[10000][15];
		char *brankasB;
		char *newbrankasB,*tokenB;
		char *brankasI;
		char *newbrankasI,*tokenI;
		char *tokenpipe = "\n";
		int loop,unique;
		int indexB = 1;
		int indexI = 1;
		int keyword = 1;
		//gets data and redirect to var array
		while(!feof(getBfile)&&!feof(getIfile2))
		{
			fgets(getIvar2,10000,getIfile2);
			fgets(getBvar,10000,getBfile);
			brankasB = strdup(getBvar);
			brankasI = strdup(getIvar2);
			newbrankasB = brankasB;
			newbrankasI = brankasI;
			while(tokenB = strtok_r(newbrankasB,"\n",&newbrankasB)){
				strcpy(temprory[indexB],tokenB);
				indexB++;
			}
			while(tokenI = strtok_r(newbrankasI,"\n",&newbrankasI)){
				strcpy(temprory2[indexI],tokenI);
				indexI++;
			}
		}
		//output data

		for(loop=1;loop<10000;loop++){
				if(strcmp(btk,temprory[loop])==0)
				{
					printf("Kata batak = %s\n",btk);
					printf("Translate indo = -%s\n",temprory2[loop]);
					unique = loop;
					printf("Unique = %d\n",unique);
					break;
				}
				else{
					keyword++;
				}
			}
			//if word Not in Database
			if(keyword == 10000){
				printf("Dang adong dope bah :(!!!\n");
			}
			fclose(getBfile);
			fclose(getIfile2);
	}
	
}

void *RecordDataI_B(Indo *ptr,Batak *ptr2,char *ind,Record *rec)
{
	FILE *header;
	header = fopen("Hasil_Translasi/indonesia_ke_batak.txt","r");
	//fill into text in header of file
	if(header == NULL){
		rec->indobatak = fopen("Hasil_Translasi/indonesia_ke_batak.txt","a+");
		fprintf(rec->indobatak,"------------------------------------\n");
		fprintf(rec->indobatak,"INDO|BATAK|UniqueKey|PanjangKata\n");
		fprintf(rec->indobatak,"------------------------------------\n");
	}
	rec->indobatak = fopen("Hasil_Translasi/indonesia_ke_batak.txt","a+"); //a+ to add data in end of file
	bacadataindo(ptr,ptr);
    bacadatabatak(ptr2,ptr2);
	if(getIfile == NULL || getBfile2 == NULL)
	{
		printf("Unknown Database !!!!!\n");
	}
	else
	{
	char temprory[10000][15];
	char temprory2[10000][15];
	char *brankas;
	char *token;
	int loop;
	int index = 1;
	while(!feof(getIfile) && !feof(getBfile2))
	{
	   fgets(getIvar,sizeof(temprory),getIfile);  //untuk database indo
	   fgets(getBvar2,sizeof(temprory2),getBfile2); //untuk database batak
	   strcpy(temprory[index],getIvar);
	   strcpy(temprory2[index],getBvar2);
	   index++;
	}
	int unique;
	//parse data jika memiliki lebih dari satu translasi
		char *splitter;
		char *tokensplit;
		// char ind2[100];
		int len_ind;
		int len_btk;
		// fprintf(rec->indobatak,"INDO | BATAK | UniqueKey  | Panjang Kata\n");
	for(loop=1;loop<10000;loop++){
		splitter = strdup(temprory2[loop]);
		tokensplit = strtok(splitter,"\n");
		if(strcmp(ind,temprory[loop])==0)
		{
			len_ind = strlen(ind)-1;
			len_btk = strlen(temprory2[loop]);
			int i;
			printf("Panjang kata = %d\n",len_ind);
			while(tokensplit != NULL){
				//set layout
				if(len_ind<15){
					for(i=0;i<15-len_ind;i++)
					{
						strcat(ind," ");
					}
				}
				else if(len_btk<15){
					for(i=0;i<15-len_btk;i++)
					{
						strcat(tokensplit," ");
					}
				}
				//end layout
				strcat(ind,tokensplit);
				strcat(ind,"\t");
				unique = loop;
				fprintf(rec->indobatak,"%s",ind);
				fprintf(rec->indobatak,"%d\t",unique);
				fprintf(rec->indobatak,"%d\n",len_ind);
				tokensplit = strtok(NULL,"\n");
			}
			break;
		}
	 }
	 free(getIvar);
	 free(getBvar2);
	}
	fclose(recI_B);
	fclose(getIfile);
	fclose(getBfile2);
}

void *RecordDataB_I(Batak *ptr,Indo *ptr2,char *btk,Record *rec)
{
	FILE *header2;
	header2 = fopen("Hasil_Translasi/batak_ke_indo.txt","r");
	//fill into text in header of file
	if(header2 == NULL){
		rec->batakindo = fopen("Hasil_Translasi/batak_ke_indo.txt","a+");
		fprintf(rec->batakindo,"------------------------------------\n");
		fprintf(rec->batakindo,"BATAK|INDO|UniqueKey|PanjangKata\n");
		fprintf(rec->batakindo,"------------------------------------\n");
	}
	rec->batakindo = fopen("Hasil_Translasi/batak_ke_indo.txt","a+"); //a+ to add data in end of file
	bacadatabatak(ptr,ptr);
	bacadataindo(ptr2,ptr2);
	if(getBfile == NULL || getIfile2 == NULL )
	{
		printf("Unknown Database !!!!!\n");
	}
	else
	{
		char temprory[10000][15];
		char temprory2[10000][15];
		char *brankasB;
		char *newbrankasB,*tokenB;
		char *brankasI;
		char *newbrankasI,*tokenI;
		char *tokenpipe = "\n";
		int loop;
		int indexB = 1;
		int indexI = 1;
		int keyword = 1;
	while(!feof(getBfile)&&!feof(getIfile2))
		{
			fgets(getIvar2,10000,getIfile2);
			fgets(getBvar,10000,getBfile);
			brankasB = strdup(getBvar);
			brankasI = strdup(getIvar2);
			newbrankasB = brankasB;
			newbrankasI = brankasI;
			while(tokenB = strtok_r(newbrankasB,"\n",&newbrankasB)){
				strcpy(temprory[indexB],tokenB);
				indexB++;
			}
			while(tokenI = strtok_r(newbrankasI,"\n",&newbrankasI)){
				strcpy(temprory2[indexI],tokenI);
				indexI++;
			}
		}
	int unique;
	//parse data jika memiliki lebih dari satu translasi
		char *splitter2;
		char *tokensplit2;
		// char ind2[100];
		int len_ind;
		int len_btk;
		// fprintf(rec->indobatak,"INDO | BATAK | UniqueKey  | Panjang Kata\n");
	
	for(loop=1;loop<10000;loop++){
		splitter2 = strdup(temprory2[loop]);
		tokensplit2 = strtok(splitter2,"\n");
		if(strcmp(btk,temprory[loop])==0)
		{
			len_btk = strlen(btk)-1;
			len_ind = strlen(temprory2[loop]);
			while(tokensplit2 != NULL){
				//end layout
				strcat(btk,"\t");
				strcat(btk,tokensplit2);
				strcat(btk,"\t");
				unique = loop;
				fprintf(rec->batakindo,"%s",btk);
				fprintf(rec->batakindo,"%d\t",unique);
				fprintf(rec->batakindo,"%d\n",len_btk);
				tokensplit2 = strtok(NULL,"\n");
			}
			break;
		}
	 }
	 free(getIvar2);
	 free(getBvar);
	}
	fclose(rec->batakindo);
	fclose(getIfile2);
	fclose(getBfile);
}


