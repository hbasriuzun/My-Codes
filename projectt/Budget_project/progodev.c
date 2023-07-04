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

void Menu(Budget *budget , Name *name );
void save_in_budget(Budget *budget, Name *name);
void printfbudget(Budget *budget);
void printfname(Name *name);
void listofgenres(Name *name,Budget *budget);
void listofyear(Budget *budget);
int compareByYear(const void* a, const void* b);
int compareByScore(const void* a, const void* b);
void filmlistbyscore(Name *name);
void sortByScore(Name* name, int size);
void sortByYear(Budget* budget, int size);
void onefilm(Budget *budget, Name *name);
void frequencygenres(Name *name);

int main() {
    Budget *budget = (Budget*)malloc(sizeof(Budget)*4000);
    Name *name = (Name*)malloc(sizeof(Name)*4000);    
    save_in_budget(budget,name);
    Menu(budget,name);
    
    
     
}

void Menu(Budget *budget , Name *name){
    
    printf("MENU\n1.Budget dizisinin listesi\n2.Name dizisinin listesi\n3.Genre(turlerin) listesi\n4.Yillara gore Movie (Filmlerin) Listesi\n5.Skorlara(score) gore Filmlerin Listesi\n6.Tek Bir Filmin Tum Bilgileri\n7.Turlerin frekansi\n8.cikis");
    int istek;
    
    printf("\n\nLutfen bir secenek secin:\n");
    scanf("%d",&istek);
   
    if(istek == 1) {sortByYear(budget,movie);printfbudget(budget);}
    else if (istek == 2) printfname(name);
    else if (istek == 3) listofgenres(name,budget);
    else if (istek == 4) {sortByYear(budget,movie);listofyear(budget);}
    else if (istek == 5) {sortByScore(name,movie);filmlistbyscore(name);}//
    else if (istek == 6) onefilm(budget,name);
    else if (istek == 7) frequencygenres(name);
    else if (istek == 8) {
        printf("\nprogram sonlandirildi.");
        exit (1);}
    
        Menu(budget,name);


}

void save_in_budget(Budget *budget, Name *name){
    FILE *dosya;
    char dosyaAdi[10];
    char cumle[250];
    char *kelime;
    
    char *kelimeArray[kelime_sayisi];
    int kelimeSayisi = 0;


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
        
        if(i == movie) break;  
    }
      
}

void printfbudget(Budget *budget){
    
    int i= 0;
    for(i = 0; i < movie; i++){
        printf("%d\n", budget[i].budget);
        printf("%s\n", budget[i].title);
        printf("%s\n", budget[i].titletype);
        printf("%d\n", budget[i].year);
        printf("%s\n", budget[i].top250);
        printf("\n");
    }
}

void printfname(Name *name){
    int i = 0, slm = 0;
    for(i = 0; i < movie; i++){
        printf("Title: %s\n", name[i].title);
        printf("Must see number: %s\n", name[i].mustsee);
        printf("Rating: %lf\n", name[i].rating);
        printf("Runtime: %lf\n", name[i].runtime);
        printf("Votes: %lf\n", name[i].votes);
        printf("Url: %s", name[i].url);
        printf("Directors: ");
        for(int slm = 0; name[i].directors[slm] != NULL; slm++){
            printf("%s,", name[i].directors[slm]);
        }
        printf("\n");
        printf("Genre: ");
        for(slm = 0; name[i].genre[slm] != NULL; slm++){
            printf("%s,", name[i].genre[slm]);
        }
        printf("\n\n");
    }
}

void listofgenres(Name *name,Budget *budget){
    
    int i ;
    for( i=0 ; i< movie; i++){
        printf("Name : %s\nGenres:",budget[i].title);
        for(int slm = 0; name[i].genre[slm] != NULL; slm++){
            printf("%s,", name[i].genre[slm]);
        }
        printf("\n\n");
    }
    
}

int compareByYear(const void* a, const void* b) {
    const Budget* budgetA = (const Budget*)a;
    const Budget* budgetB = (const Budget*)b;

    
    if (budgetA->year < budgetB->year)
        return 1;
    else if (budgetA->year > budgetB->year)
        return -1;
    else
        return 0;
}

void sortByYear(Budget* budget, int size) {
    
    qsort(budget, size, sizeof(Budget), compareByYear);
}

void listofyear(Budget *budget){
    int i ;
    for( i=0 ; i < movie; i++){
        printf("Name : %s\nyear : %d",budget[i].title,budget[i].year);
        printf("\n\n");
    }
}

int compareByScore(const void* a, const void* b) {
    const Name* nameA = (const Name*)a;
    const Name* nameB = (const Name*)b;

 
    if (nameA->score < nameB->score)
        return 1;
    else if (nameA->score > nameB->score)
        return -1;
    else
        return 0;
}

void sortByScore(Name* name, int size) {
    qsort(name, size, sizeof(Name), compareByScore);
}

void filmlistbyscore(Name *name){
    int i = 0;
    for(i = 0; i < movie; i++){
        printf("Title: %s  ", name[i].title);
        printf("Rating: %lf\n", name[i].rating);
        
    }
}

void onefilm(Budget* budget, Name* name) {
    int i, slm = 0;
    char which[100];
    printf("\nPlease enter the film name:(filmin ismi txt dosyasinda neyse onu giriniz!) \n");
    scanf("%s", which);
    for (i = 0; i < movie; i++) {
        if (strcmp(budget[i].title, which) == 0) { // strcmp ile karşılaştır
            printf("Budget: %d\n", budget[i].budget);
            printf("Title: %s\n", budget[i].title);
            printf("Title Type: %s\n", budget[i].titletype);
            printf("Year: %d\n", budget[i].year);
            printf("Top 250: %s\n", budget[i].top250);
            printf("Must see number: %s\n", name[i].mustsee);
            printf("Rating: %lf\n", name[i].rating);
            printf("Runtime: %lf\n", name[i].runtime);
            printf("Votes: %lf\n", name[i].votes);
            printf("Url: %s", name[i].url);
            printf("Directors: ");
            for (int slm = 0; name[i].directors[slm] != NULL; slm++) {
                printf("%s,", name[i].directors[slm]);
            }
            printf("\n");
            printf("Genre: ");
            for (slm = 0; name[i].genre[slm] != NULL; slm++) {
                printf("%s,", name[i].genre[slm]);
            }
            printf("\n\n");
            printf("\n");
        }
    }
}

void frequencygenres(Name *name){
    int i, j, count;
    char **genres = (char**)malloc(sizeof(char*) * 100);
    int *frequency = (int*)malloc(sizeof(int) * 100);
    int totalGenres = 0;

    
    for (i = 0; i < movie; i++) {
        for (j = 0; name[i].genre[j] != NULL; j++) {
            int found = 0;
           
            for (int k = 0; k < totalGenres; k++) {
                if (strcmp(genres[k], name[i].genre[j]) == 0) {
                    frequency[k]++; 
                    found = 1;
                    break;
                }
            }
           
            if (!found) {
                genres[totalGenres] = name[i].genre[j];
                frequency[totalGenres] = 1;
                totalGenres++;
            }
        }
    }

    
    for (i = 1; i < totalGenres; i++) {
        char* currentGenre = genres[i];
        int currentFrequency = frequency[i];
        j = i - 1;
        while (j >= 0 && frequency[j] < currentFrequency) {
            genres[j + 1] = genres[j];
            frequency[j + 1] = frequency[j];
            j--;
        }
        genres[j + 1] = currentGenre;
        frequency[j + 1] = currentFrequency;
    }

    for (i = 0; i < totalGenres; i++) {
        printf("Genre: %s, Frequency: %d\n", genres[i], frequency[i]);
    }

    free(genres);
    free(frequency);
}


