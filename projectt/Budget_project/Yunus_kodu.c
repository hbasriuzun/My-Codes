#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define kelime_sayisi 41422
typedef struct Budget
{
      int budget;
      int year;
      char *title;
      char *titletype;
      char *top250;
}Budget;

typedef struct Name
{
    char **genre;
    char *title;
    char **directors;
    char *mustsee;
    double rating;
    double score;
    double runtime;
    double votes;
    char *url;

}Name;


void printf_in_array();
int find_movie_number();


int main() {
    FILE *fp;
    fp = fopen("movie.txt", "r");
    if (fp == NULL) {
        printf("Dosya acilamadi.\n");
        return 1;
    }
    printf_in_array();


    
    
}

void printf_in_array(){
    FILE *dosya;
    char dosyaAdi[10];
    char cumle[200];
    char *kelime;
    
    
    char *kelimeArray[kelime_sayisi];
    int kelimeSayisi = 0;

    printf("Dosya adini girin: ");
    scanf("%s", dosyaAdi);

    dosya = fopen(dosyaAdi, "r");
    if (dosya == NULL) {
        printf("Dosya acilamadi.\n");
        exit(1);
    }

    while (fgets(cumle, sizeof(cumle), dosya) != NULL) {
        kelime = strtok(cumle, ";,"); 

        while (kelime != NULL && kelimeSayisi < kelime_sayisi) {
            kelimeArray[kelimeSayisi] = (char*)malloc(strlen(kelime) + 1); 
            strcpy(kelimeArray[kelimeSayisi], kelime); 
            kelimeSayisi++;

            kelime = strtok(NULL,";");
        }
    }
    

    fclose(dosya);
    
    
    
/*
    printf("Dosyadaki kelimeler:\n");
    for (int i = 0; i < 24; i++) {
        printf("%s ", kelimeArray[i]);
        free(kelimeArray[i]); 
    }*/

    Budget *budget = (Budget*)malloc(sizeof(Budget)*4000);
    Name *name = (Name*)malloc(sizeof(Name)*4000);
    int i = 0,j = 0,k=0,index = 0;
    budget[index].budget = atoi(kelimeArray[index]);
    printf("%d",budget[0].budget);
   /*
    while(*kelimeArray != '\0'){
        budget[index].budget = atoi(kelimeArray[index]);
        index++;

    }*/
}

int find_movie_number(){
     FILE *dosya;
    char karakter;
    
    int filmsayisi = 0;
    dosya = fopen("movie.txt", "r"); 

    if (dosya == NULL) {
        printf("Dosya açma hatasi!");
        return 1;
    }

    while ((karakter = fgetc(dosya)) != EOF) {
        if (karakter == '\n') {
            filmsayisi++;
        }
    }

    fclose(dosya);

    return filmsayisi*12;
}