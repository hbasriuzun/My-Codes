#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE_OF_FILE 3450
#define LENGTH 1000

//budget;title;title type;directors;rating;runtinme;year;genres;votes;top250;1001 must see;url

const char *filename = "movie.txt";

struct Budget{
      int budget;
      int year;
      char *title;
      char *titletype;
      char *top250;
};
struct Name{
    char **genre;
    char *title;
    char **directors;
    char *mustsee;
    double rating;
    int runtime;
    int votes;
    char *url;
};
struct Name movieName[SIZE_OF_FILE];
struct Budget movieBudget[SIZE_OF_FILE];


void program();
void sort_year(struct Budget *budget, struct Name *name);
void sort_votes(struct Budget *budget, struct Name *name);
void print_genres(struct Name *name);
void count_genres(struct Name *name);
void print_budget(struct Budget *budget);
void print_name(struct Name *name);
void information_of_movie(struct Budget *budget,struct Name *name);
void print_movie_information(struct Budget *budget,struct Name *name,int index);

int main(int argc, char const *argv[]){
    program();
    return 0;
}
void program(){
    FILE *file = fopen(filename,"r");
    if(file == NULL){
        printf("File not Found!\nExit..\n");
        exit(1);
    }
    int select,lineIndex = 0;
    const char *delp;
    char *word = (char*)malloc(sizeof(char)*LENGTH);
    while(fgets(word,LENGTH,file) != NULL){

        movieBudget[lineIndex].budget = atoi(strtok(word,";"));
        
        movieBudget[lineIndex].title = (char*)malloc(sizeof(char)*LENGTH);
        strcpy(movieBudget[lineIndex].title,strtok(NULL,";"));

        movieName[lineIndex].title = (char*)malloc(sizeof(char)*LENGTH);
        strcpy(movieName[lineIndex].title,movieBudget[lineIndex].title);

        movieBudget[lineIndex].titletype = (char*)malloc(sizeof(char)*LENGTH);
        strcpy(movieBudget[lineIndex].titletype,strtok(NULL,";"));

        char *temp2 = (char*)malloc(sizeof(char)*LENGTH);
        strcpy(temp2,strtok(NULL,";"));

        movieName[lineIndex].directors = (char**)malloc(sizeof(char*)*LENGTH);
        strcpy(movieName[lineIndex].directors[0],temp2);

        movieName[lineIndex].rating = atof(strtok(NULL,";"));

        movieName[lineIndex].runtime = atoi(strtok(NULL,";"));

        movieBudget[lineIndex].year = atoi(strtok(NULL,";"));

        char *temp3 = (char*)malloc(sizeof(char)*LENGTH);
        strcpy(temp3,strtok(NULL,";"));

        movieName[lineIndex].votes = atoi(strtok(NULL,";"));

        movieBudget[lineIndex].top250 = (char*)malloc(sizeof(char)*LENGTH);
        strcpy(movieBudget[lineIndex].top250,strtok(NULL,";"));

        movieName[lineIndex].mustsee = (char*)malloc(sizeof(char)*LENGTH);
        strcpy(movieName[lineIndex].mustsee,strtok(NULL,";"));

        movieName[lineIndex].url = (char*)malloc(sizeof(char)*LENGTH);
        strcpy(movieName[lineIndex].url,strtok(NULL,";"));
        
        
        
        int i=0;
        const char *delp=strtok(temp3,",");
        movieName[lineIndex].genre = (char**)malloc(sizeof(char*)*LENGTH);
        while(delp != NULL){
            movieName[lineIndex].genre[i] = (char*)malloc(sizeof(char)*LENGTH);
            strcpy(movieName[lineIndex].genre[i],delp);
            delp=strtok(NULL,",");
            i++;
        }//puts("");
        
        
        lineIndex++;
    }
    
    sort_year(movieBudget,movieName);
    while(1){
        printf("\n1-List of budget array\n2-List of name array\n3-List of genres\n4-List of the Movie Through the Years\n5-List of the Movie Through the Scores\n6-All Information of a Single Movie\n7-Frequecy of the Genres\n8-Exit.\n");
        printf("Select your process : ");
        scanf("%d",&select);
        switch (select){
        case 1:
            print_budget(movieBudget);
            break;
        case 2:
            print_name(movieName);
            break;
        case 3:
            print_genres(movieName);
            break;
        case 4:
            for(int i=0; i<SIZE_OF_FILE ; i++){
                if(movieBudget[i].year == 0)continue;
                printf("%s : %d\n",movieBudget[i].title,movieBudget[i].year);
            }
            break;
        case 5:
            sort_votes(movieBudget,movieName);
            break;
        case 6:
            information_of_movie(movieBudget,movieName);
            break;
        case 7:
            count_genres(movieName);
            break;
        case 8:
            printf("Exiting...\n");
            exit(1);
            break;
        default:
            printf("Error!\nExiting...");
            exit(1);
            break;
        }
    }
}
void print_budget(struct Budget *budget){
    int index=0;
    while(index < SIZE_OF_FILE){
        printf("%s : %d\n",budget[index].title,budget[index].budget);
        index++;
    }
}
void print_name(struct Name *name){
    int index=0;
    while(index < SIZE_OF_FILE){
        if(index%10==0)puts("");
        printf("%s  ",name[index].title);
        index++;
    }
}
void information_of_movie(struct Budget *budget,struct Name *name){
    char nameOfMovie[100];
    printf("\nEnter movie name : ");
    scanf("%s",nameOfMovie);
    int index;
    for(index=0;index<SIZE_OF_FILE;index++){
        if(strcmp(nameOfMovie,name[index].title)==0){
            print_movie_information(budget,name,index);
            break;
        }
    }if(index==3450)printf("Movie not found.");

}
void print_movie_information(struct Budget *budget,struct Name *name,int index){
    int i=0;
    printf("\nTitle : %s\n",name[index].title);
    printf("Type : %s\n",budget[index].titletype);
    printf("Genres : ");
    while(name[index].genre[i]!='\0'){
        printf("%s ",name[index].genre[i]);
        i++;}
    printf("\nDirector : %s\n",name[index].directors);
    printf("IMDB Rating : %.1lf (%d Votes) | IMDB Rank : %s\n",name[index].rating,name[index].votes,budget[index].top250);
    printf("Year : %d\n",budget[index].year);
    printf("Budget : %d\n",budget[index].budget);
    printf("Runtime : %d\n",name[index].runtime);
    printf("1001 Must See : %s\n",name[index].mustsee);
    printf("URL : %s",name[index].url);
}

void sort_year(struct Budget *budget, struct Name *name) {
    int i, j, max_year, max_index;

    for (i = 0; i < SIZE_OF_FILE; i++) {
        max_year = budget[i].year;
        max_index = i;

        for (j = i + 1; j < SIZE_OF_FILE; j++) {
            if (budget[j].year > max_year) {
                max_year = budget[j].year;
                max_index = j;
            }
        }

        struct Budget tempBudget = budget[i];
        struct Name tempName = name[i];

        budget[i] = budget[max_index];
        name[i] = name[max_index];

        budget[max_index] = tempBudget;
        name[max_index] = tempName;
    }
}
void sort_votes(struct Budget *budget, struct Name *name) {
    int i, j, max_votes, max_index;

    struct Name sortedByName[SIZE_OF_FILE];
    struct Budget sortedByBudget[SIZE_OF_FILE];

    for (i = 0; i < SIZE_OF_FILE; i++) {
        sortedByName[i] = name[i];
        sortedByBudget[i] = budget[i];
    }

    for (i = 0; i < SIZE_OF_FILE; i++) {
        max_votes = sortedByName[i].votes;
        max_index = i;

        for (j = i + 1; j < SIZE_OF_FILE; j++) {
            if (sortedByName[j].votes > max_votes) {
                max_votes = sortedByName[j].votes;
                max_index = j;
            }
        }


        struct Name tempName = sortedByName[i];
        struct Budget tempBudget = sortedByBudget[i];

        sortedByName[i] = sortedByName[max_index];
        sortedByBudget[i] = sortedByBudget[max_index];

        sortedByName[max_index] = tempName;
        sortedByBudget[max_index] = tempBudget;
    }
    for(i = 0; i<SIZE_OF_FILE ; i++){
        if(sortedByName[i].votes == 0)continue;
        printf("%s : %d (votes)\n",sortedByName[i].title,sortedByName[i].votes);
    }
}

void print_genres(struct Name *name) {
    int i, j;
    int genreCount = 0;
    char **uniqueGenres = (char **)malloc(SIZE_OF_FILE * sizeof(char *));

    for (i = 0; i < SIZE_OF_FILE; i++) {
        uniqueGenres[i] = NULL;
    }

    for (i = 0; i < SIZE_OF_FILE; i++) {
        int genreIndex = 0;
        char **genres = name[i].genre;

        while (genres[genreIndex] != NULL) {
            int isUnique = 1;

            for (j = 0; j < genreCount; j++) {
                if (uniqueGenres[j] != NULL && strcmp(uniqueGenres[j], genres[genreIndex]) == 0) {
                    isUnique = 0;
                    break;
                }
            }

            if (isUnique) {
                uniqueGenres[genreCount] = (char *)malloc((strlen(genres[genreIndex]) + 1) * sizeof(char));
                strcpy(uniqueGenres[genreCount], genres[genreIndex]);
                genreCount++;
            }

            genreIndex++;
        }
    }

    printf("Unique Genres:\n");
    for (i = 0; i < genreCount; i++) {
        printf("%s\n", uniqueGenres[i]);
    }

    for (i = 0; i < genreCount; i++) {
        free(uniqueGenres[i]);
    }
    free(uniqueGenres);
}
void count_genres(struct Name *name){
    int i, j;
    int genreCount = 0;
    int *genreFrequency = (int *)malloc(SIZE_OF_FILE * sizeof(int));
    char **uniqueGenres = (char **)malloc(SIZE_OF_FILE * sizeof(char *));

    for (i = 0; i < SIZE_OF_FILE; i++) {
        uniqueGenres[i] = NULL;
        genreFrequency[i] = 0;
    }

    for (i = 0; i < SIZE_OF_FILE; i++) {
        int genreIndex = 0;
        char **genres = name[i].genre;

        while (genres[genreIndex] != NULL) {
            int isUnique = 1;

            for (j = 0; j < genreCount; j++) {
                if (uniqueGenres[j] != NULL && strcmp(uniqueGenres[j], genres[genreIndex]) == 0) {
                    isUnique = 0;
                    break;
                }
            }

            if (isUnique) {
                uniqueGenres[genreCount] = (char *)malloc((strlen(genres[genreIndex]) + 1) * sizeof(char));
                strcpy(uniqueGenres[genreCount], genres[genreIndex]);
                genreCount++;
            }

            for (j = 0; j < genreCount; j++) {
                if (strcmp(uniqueGenres[j], genres[genreIndex]) == 0) {
                    genreFrequency[j]++;
                    break;
                }
            }

            genreIndex++;
        }
    }

    printf("Genre Frequency:\n");
    for (i = 0; i < genreCount; i++) {
        printf("%s: %d\n", uniqueGenres[i], genreFrequency[i]);
    }

    for (i = 0; i < genreCount; i++) {
        free(uniqueGenres[i]);
    }
    free(uniqueGenres);
    free(genreFrequency);
}