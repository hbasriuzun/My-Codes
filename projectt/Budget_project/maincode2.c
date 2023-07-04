#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define kelime_sayisi 41422
#define movie 3449
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
    printf_in_array();


    
    
}

void printf_in_array(){
    FILE *dosya;
    char dosyaAdi[10];
    char cumle[250];
    char *kelime;
    
    
    char *kelimeArray[kelime_sayisi];
    int kelimeSayisi = 0;

    //printf("Dosya adini girin: ");
    //scanf("%s", dosyaAdi);

    dosya = fopen("movie.txt", "r");
    if (dosya == NULL) {
        printf("Dosya acilamadi.\n");
        exit(1);
    }

    while (fgets(cumle, sizeof(cumle), dosya) != NULL) {
        kelime = strtok(cumle, ";"); 

        while (kelime != NULL && kelimeSayisi < kelime_sayisi) {
            kelimeArray[kelimeSayisi] = (char*)malloc(strlen(kelime) + 1); 
            strcpy(kelimeArray[kelimeSayisi], kelime); 
            kelimeSayisi++;

            kelime = strtok(NULL,";");
        }
    }
    

    fclose(dosya);
    
    
    Budget *budget = (Budget*)malloc(sizeof(Budget)*4000);
    Name *name = (Name*)malloc(sizeof(Name)*4000);

    int i=0,j=6,m=2,l=1,y=9,z=10,n=4,p=5,u=8,h=11,d=3,g=7;
    
    while (1){
       
        budget[i].budget = atoi(kelimeArray[i*12]);
        budget[i].year = atoi(kelimeArray[j]);
        budget[i].titletype = kelimeArray[m];
        budget[i].title = kelimeArray[l];
        budget[i].top250 = kelimeArray[y];
        name[i].title = kelimeArray[l];
        name[i].mustsee = kelimeArray[z];
        name[i].rating = atof(kelimeArray[n]);
        name[i].runtime = atof(kelimeArray[p]);
        name[i].votes = atof(kelimeArray[u]);
        name[i].url = kelimeArray[h];
    
        name[i].genre = (char**)malloc(sizeof(char*)*100);
        int genre_first = 0,ikinci = 0, k = 0;
        while(kelimeArray[g][ikinci] != '\0'){
            name[i].genre[genre_first] = (char*)malloc(sizeof(char)*100);
            k=0;
            while(kelimeArray[g][ikinci] != ','){
                if(kelimeArray[g][ikinci] == '\0')
                    break;
                name[i].genre[genre_first][k] = kelimeArray[g][ikinci];
                ikinci++;
                k++;
            }
            name[i].genre[genre_first][k] = '\0';
            
           // printf("%s\n", name[i].genre[i]);
            if(kelimeArray[g][ikinci] == '\0'){
                name[i].genre[genre_first+1] = NULL;
                break;
            }
            ikinci++;
            genre_first++;
        }
        
        name[i].directors = (char**)malloc(sizeof(char*)*100);
        int directors_first = 0;
        ikinci = 0; k = 0;

        while(kelimeArray[d][ikinci] != '\0'){
            name[i].directors[directors_first] = (char*)malloc(sizeof(char)*100);
            k=0;
            while(kelimeArray[d][ikinci] != ','){
                if(kelimeArray[d][ikinci] == '\0')
                    break;
                name[i].directors[directors_first][k] = kelimeArray[d][ikinci];
                ikinci++;
                k++;
            }
            name[i].directors[directors_first][k] = '\0';
            
            if(kelimeArray[d][ikinci] == '\0'){
                name[i].directors[directors_first+1] = NULL;
                break;
            }
            ikinci++;
            directors_first++;
        }

        int slm = 0;
        printf("Directors: ");
        for(int slm = 0; name[i].directors[slm] != NULL; slm++){
            printf("%s,", name[i].directors[slm]);
        }
        printf("\n");
        printf("Genre: ");
        for(slm = 0; name[i].genre[slm] != NULL; slm++){
            printf("%s,", name[i].genre[slm]);
        }
        printf("\n");
        printf("%d. %d ",i,budget[i].budget);
        printf(" %d ",budget[i].year);
        printf(" %s ",budget[i].title);
        printf(" %s ",budget[i].titletype);
        printf("%d %s ",i,budget[i].top250);
        puts("\n");
        j+=12;
        m+=12;
        l+=12;
        y+=12;
        z+=12;
        n+=12;
        p+=12;
        u+=12;
        h+=12;
        d+=12;
        g+=12;
        i++;
        
        if(i == movie) break;  //film sayisini tamamlayinca duruyor.
    }
    


    
    

    
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