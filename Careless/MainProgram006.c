#include "Header006.h"
int main()
{
    int option;
    aksesBatak *dataBatak = (aksesBatak*)malloc(sizeof(aksesBatak));
    aksesIndo *dataIndo = (aksesIndo*)malloc(sizeof(aksesIndo));
    aksesBatak *dataBatak2 = (aksesBatak*)malloc(sizeof(aksesBatak));
    aksesIndo *dataIndo2 = (aksesIndo*)malloc(sizeof(aksesIndo));
    Record *tmprecord = (Record*)malloc(sizeof(Record));
    Record *tmprecord2 = (Record*)malloc(sizeof(Record));
    KALIMAT *datakalimatindo = (KALIMAT*)malloc(sizeof(KALIMAT)*1);
    KALIMAT *tmprecord3 = (KALIMAT*) calloc (sizeof(KALIMAT),sizeof(KALIMAT));
    char cariI[15];
    char cariB[15];
    while(1==1)
    {
        puts("-------------------Welcome to 006TranslateBatak.com-------------------");
        puts("1.Show Content Story");
        puts("2.Show Parse Data");
        puts("3.Parse Indo-Batak");
        puts("4.Parse Batak-Indo");
        puts("5.Translate Kata");
        puts("6.Translate Kalimat");
        puts("0.Exit Program");
        printf("=>");scanf("%d",&option);
        if(option == 1)
        {
            system("cls");
            char option;
            printf("MainProgram/Content\n");
            do{
                puts("1.Content Story Indo");
                puts("2.Content Story batak");
                puts("0.Menu Utama");
                printf("=>");scanf("%s",&option);
                
                if(option == '1'){
                        printf("MainProgram/Content/D_Indo\n");
                        ShowContentI(dataIndo);
                        printf("\n\n");
                }
                else if(option == '2'){
                        printf("MainProgram/Content/D_Batak\n");
                        ShowContentB(dataBatak);
                        printf("\n\n");
                }
                else{
                    system("cls");
                }
               
            }while(option!='0');
            system("cls");
        }
        else if(option == 2)
        {
            system("cls");
            printf("MainProgram/Parse\n");
            char option;
            do{
                puts("1.Parse Data Indo");
                puts("2.parse Data Batak");
                puts("0.Menu Utama");
                printf("Enter => ");scanf("%s",&option);
                switch (option)
                {
                case '1':
                        printf("MainProgram/Parse/D_Indo\n");
                        TampilIndo(dataIndo);
                        printf("\n\n");
                        break;
                case '2':
                        printf("MainProgram/Parse/D_Batak\n");
                        TampilBatak(dataBatak);
                        printf("\n\n");
                        break;
                default:
                    system("cls");
                    break;
                system("cls");
                }
            }while(option != '0');
            system("cls");
        }
        else if(option == 3)
        {
            system("cls");
            printf("MainProgram/all_I-B\n");
            IndoBatak(dataIndo,dataBatak);
            printf("\n\n");
        }
        else if(option == 4)
        {
            system("cls");
            printf("MainProgram/all_B-I\n");
            BatakIndo(dataBatak,dataIndo);
            printf("\n\n");
        }
        else if(option == 5)
        {
            system("cls");
            printf("MainProgram/Translate\n");
            int choose;
            puts("1.Indo - Batak");
            puts("2.Batak - Indo");
            printf("=>");scanf("%d",&choose);
            if(choose == 1)
            {
                char option;
                printf("MainProgram/Translate/T_I-B\n");
                puts("----------------006translate.com--------------");
                puts("Horas!!!!Rade do fitur translate ibaen nami\n");
                do{
                puts("~Indo-Batak~");
                printf("Masukan kata :");
                scanf(" %[^\n]s",cariI);
                strcat(cariI,"\n");
                TranslateI_B(dataIndo,dataBatak,cariI);
                printf("\n\n------Tekan 0 untuk kembali ke menu utama-------------");
                printf("\n\n------Tekan 9 untuk record hasil translasi-------------");
                printf("\n\n------Tekan apasaja untuk Tetap translate-------------");
                printf("\nEnter =>");
                scanf("%s",&option);
                if(option == '9'){
                    RecordDataI_B(dataIndo,dataBatak,cariI,tmprecord);
                }
                system("cls");
                }while(option!='0');
                system("cls");
            }
            else if(choose == 2)
            {
                char option;
                printf("MainProgram/Translate/T_B-I\n");
                puts("----------------006translate.com--------------");
                puts("Horas!!!!Rade do fitur translate ibaen nami\n");
                do{
                    puts("~batak-indo~");
                    printf("Masukan kata :");
                    scanf(" %[^\n]s",cariB);
                    TranslateB_I(dataBatak,dataIndo2,cariB);
                    printf("\n\n------Tekan 0 untuk kembali ke menu utama-------------");
                    printf("\n\n------Tekan apasaja untuk Tetap translate-------------");
                    printf("\n\n------Tekan 9 untuk Record data-------------");
                    printf("\nEnter =>");
                    scanf("%s",&option);
                    if(option == '9'){
                        RecordDataB_I(dataBatak,dataIndo,cariB,tmprecord);
                    }
                    
                    system("cls");
                }while(option!='0');
                system("cls");
            }
            else{
                puts("WARNING!!!!Error Option!!!\n");
            }
        }
        else if(option == 6){
                system("cls");
                char option;
                char sentenceI[100];
                printf("MainProgram/TranslateKalimat/T_I-B\n");
                puts("----------------006translate.com--------------");
                puts("Horas!!!!Rade do fitur translate ibaen nami\n");
                    do{
                    puts("~Translate Kalimat Indo-Batak~");
                    printf("Masukan Kalimat :");
                    scanf(" %[^\n]s",sentenceI);
                    strcat(sentenceI,"\n");
                    // TranslateKalimatI_B(dataIndo,dataBatak,sentenceI);
                    TranslateKI_B(datakalimatindo,datakalimatindo,tmprecord,sentenceI);
                    printf("\n\n------Tekan 0 untuk kembali ke menu utama-------------");
                    printf("\n\n------Tekan apasaja untuk Tetap translate-------------");
                    printf("\nEnter =>");
                    scanf("%s",&option);
                    system("cls");
                    }while(option!='0');
                    system("cls");
                }
                
        
        else if(option == 0)
        {
            puts("Terimakasih atas kunjungannya !!");
            puts("Program Belum Sepenuhnya selesai,Karena waktu dan situasi yang tidak memadai...");
            puts("Developer akan terus mengembangkan nya");
            exit(1);
        }
    }
    return 0;
}

