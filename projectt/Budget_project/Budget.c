#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define NUMBER_OF_MOVIES 3450

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

typedef struct Genre
{
    char *genre;
    int frequency;
}Genre;

void save(Budget *budget, Name *name, FILE *fp);
void open_memory(Budget *budget, Name *name, FILE *fp);
void print_budget(Budget *budget);
void print_name(Name *name);
void sort_year(Budget *budget, Name *name);
void sort_rating(Budget *budget,Name *name);
void All_information_single_movie(Budget *budget, Name *name);
void Frequecy_of_the_Genres(Name *name);
void List_of_genres(Name *name);
void Swap_Budged(Budget *budget1, Budget *budget2);
void Swap_Name(Name *name1, Name *name2);
void Print_title_and_year(Budget *budget, Name *name);
void Print_title_and_rating(Budget *budget, Name *name);

int main(int argc, char *argv[]){
    Budget *budget = (Budget*)malloc(sizeof(Budget)*4000);
    Name *name = (Name*)malloc(sizeof(Name)*4000);
    FILE *fp;

    fp = fopen("movie.txt", "r");
    if(fp == NULL){
        printf("Error opening file\n");
        exit(1);
    }
    save(budget, name, fp);
    while(1){
        printf("Select Operations:\n1.	List of budget array\n2.	List of name array\n3.	List of genres\n4.	List of the Movie Through the Years\n5.	List of the Movie Through the Scores\n6.	All Information of a Single Movie\n7.	Frequecy of the Genres\n8.	Exit\n");
        int choice;
        scanf("%d", &choice);
        switch (choice){
        case 1:
            print_budget(budget);
            break;
        case 2:
            print_name(name);
            break;
        case 3:
            List_of_genres(name);
            break;
        case 4:
            sort_year(budget, name);
            Print_title_and_year(budget, name);
            break;
        case 5:
            sort_rating(budget, name);
            Print_title_and_rating(budget, name);
            break;
        case 6:
            All_information_single_movie(budget, name);
            break;
        case 7:
            Frequecy_of_the_Genres(name);
            break;
        case 8:
            exit(1);
            break;
        }
    }
    fclose(fp);
    return 0;
}

void save(Budget *budget, Name *name, FILE *fp){
    char *line = NULL,*tmp2 , *tmp3 ;
    tmp2 = (char*)malloc(sizeof(char)*100);
    tmp3 = (char*)malloc(sizeof(char)*100);
    double tmp;
    int i = 0,j = 0,k=0,index = 0;

    line = (char*)malloc(sizeof(char)*1000);
    //fgets(line, 1000, fp);
    while(fgets(line, 1000, fp) != NULL){
        tmp = atof(strtok(line, ";"));
        budget[index].budget = tmp;

        budget[index].title = (char*)malloc(sizeof(char) * 100);
        strcpy(budget[index].title, strtok(NULL, ";"));

        name[index].title = (char*)malloc(sizeof(char) * 100);
        strcpy(name[index].title, budget[index].title);

        budget[index].titletype = (char*)malloc(sizeof(char)*100);
        strcpy(budget[index].titletype, strtok(NULL, ";"));

        strcpy(tmp2, strtok(NULL, ";"));

        name[index].rating = atof(strtok(NULL, ";"));

        name[index].runtime = atof(strtok(NULL, ";"));

        budget[index].year = atoi(strtok(NULL, ";"));

        strcpy(tmp3, strtok(NULL, ";"));

        name[index].votes = atof(strtok(NULL, ";"));

        budget[index].top250 = (char*)malloc(sizeof(char)*100);
        strcpy(budget[index].top250, strtok(NULL, ";"));

        name[index].mustsee = (char*)malloc(sizeof(char)*100);
        strcpy(name[index].mustsee, strtok(NULL, ";"));

        name[index].url = (char*)malloc(sizeof(char)*1000);
        strcpy(name[index].url, strtok(NULL, "\0"));

        name[index].genre = (char**)malloc(sizeof(char*)*100);
        i = 0; j = 0; k = 0;
        while(tmp3[j] != '\0'){
            name[index].genre[i] = (char*)malloc(sizeof(char)*100);
            k=0;
            while(tmp3[j] != ','){
                if(tmp3[j] == '\0'){
                    k++;
                    break;
                }
                name[index].genre[i][k] = tmp3[j];
                j++;
                k++;
            }
            name[index].genre[i][k] = '\0';
            
           // printf("%s\n", name[index].genre[i]);
            if(tmp3[j] == '\0'){
                name[index].genre[i+1] = NULL;
                break;
            }
            j++;
            i++;
        }
    /*  name[index].genre[0] = (char*)malloc(sizeof(char)*100);
        char* token = strtok(tmp3, ",");
        for(i = 0;token != NULL;){
            strcpy(name[index].genre[i++], token);
            name[index].genre[i] = (char*)malloc(sizeof(char)*100);
            token = strtok(tmp3, ",");
            printf("%s\n",token);
        } */
        j = 0; i = 0; k = 0;
        name[index].directors = (char**)malloc(sizeof(char*)*100);
        while(tmp2[j-1] != '\0'){
            name[index].directors[i] = (char*)malloc(sizeof(char)*100);
            k=0;
            while(tmp2[j] != ','){
                if(tmp2[j] == '\0'){
                    
                    break;
                }
                name[index].directors[i][k] = tmp2[j];
                j++;
                k++;
            }
            name[index].directors[i][k] = '\0';
        //    printf("%s\n", name[index].directors[i]);
            if(tmp2[j] == '\0'){
                name[index].directors[i+1] = NULL;
            }
            j++;
            i++;
        }

    /*  name[index].directors[0] = (char*)malloc(sizeof(char)*100);
        strcpy(name[index].directors[0], strtok(tmp2, ","));
        for(i = 0; i < 5; i++){
            if(strtok(NULL, ",") == NULL)
                break;
            name[index].directors[i] = (char*)malloc(sizeof(char)*100);
            strcpy(name[index].directors[i], strtok(NULL, ","));
        } */

        index++;
    }

}

void open_memory(Budget *budget, Name *name){

    budget->title = (char*)malloc(sizeof(char)*100);
    budget->titletype = (char*)malloc(sizeof(char)*100);
    budget->top250 = (char*)malloc(sizeof(char)*100);

    name->genre = (char**)malloc(sizeof(char*)*100);
    for (size_t i = 0; i < 5; i++)
    {
        
    }
}

void Print_title_and_year(Budget *budget, Name *name){
    int i = 0;
    for(i = 0; i < NUMBER_OF_MOVIES; i++){
        printf("Title: %s\n", name[i].title);
        printf("Year: %d\n\n", budget[i].year);
    }
}

void Print_title_and_rating(Budget *budget, Name *name){
    int i = 0;
    for(i = 0; i < NUMBER_OF_MOVIES; i++){
        printf("Title: %s\n", name[i].title);
        printf("Rating: %lf\n\n", name[i].rating);
    }
}

void print_budget(Budget *budget){
    int i= 0;
    for(i = 0; i < NUMBER_OF_MOVIES ; i++){
        printf("Budget: %d\n", budget[i].budget);
        printf("Title: %s\n", budget[i].title);
        printf("Titletype: %s\n", budget[i].titletype);
        printf("Top250: %s\n", budget[i].top250);
        printf("Year: %d\n\n", budget[i].year);
    }
}

void print_name(Name *name){
    int i = 0, j = 0;
    for(i = 0; i < NUMBER_OF_MOVIES; i++){
        printf("Title: %s\n", name[i].title);
        printf("Must see number: %s\n", name[i].mustsee);
        printf("Rating: %lf\n", name[i].rating);
        printf("Runtime: %lf\n", name[i].runtime);
        printf("Votes: %lf\n", name[i].votes);
        printf("Url: %s", name[i].url);
        printf("Genre: ");
        for(j = 0; name[i].genre[j+1][0] != '\0'; j++){
            printf("%s,", name[i].genre[j]);
        }
        printf("\n");
        printf("Directors: ");
        for(j = 0; name[i].directors[j+1][0] != '\0'; j++){
            printf("%s,", name[i].directors[j]);
        }
        printf("\n\n");
    }
}

void Swap_Budged(Budget *budget1, Budget *budget2){
    Budget temp = *budget1;
    *budget1 = *budget2;
    *budget2 = temp;
}

void Swap_Name(Name *name1, Name *name2){
    Name temp = *name1;
    *name1 = *name2;
    *name2 = temp;
}

void sort_year(Budget *budget, Name *name){
    int i, j, min_idx;
    for (i = 0; i < NUMBER_OF_MOVIES-1; i++){
        min_idx = i;
        for (j = i+1; j < NUMBER_OF_MOVIES; j++){
            if (budget[j].year < budget[min_idx].year){
                min_idx = j;
            }
        }
        Swap_Budged(&budget[min_idx], &budget[i]);
        Swap_Name(&name[min_idx], &name[i]);
    }
}

void sort_rating(Budget *budget,Name *name){
    int i, j, min_idx;
    for (i = 0; i < NUMBER_OF_MOVIES-1; i++){
        min_idx = i;
        for (j = i+1; j < NUMBER_OF_MOVIES; j++){
            if (name[j].rating < name[min_idx].rating){
                min_idx = j;
            }
        }
        Swap_Budged(&budget[min_idx], &budget[i]);
        Swap_Name(&name[min_idx], &name[i]);
    }
}

void All_information_single_movie(Budget *budget, Name *name){
    int i = 0, j = 0;
    char *movie_name = (char*)malloc(sizeof(char)*100);
    printf("Enter the movie name: ");
    scanf(" %[^\n]", movie_name);
    for(i = 0; i < NUMBER_OF_MOVIES; i++){
        if(strcmp(name[i].title, movie_name) == 0){
            printf("Title: %s\n", name[i].title);
            printf("Must see number: %s\n", name[i].mustsee);
            printf("Rating: %lf\n", name[i].rating);
            printf("Runtime: %lf\n", name[i].runtime);
            printf("Votes: %lf\n", name[i].votes);
            printf("Url: %s", name[i].url);
            printf("Genre: ");
            for(j = 0; ;){
                printf("%s,", name[i].genre[j++]);
                if(name[i].genre[j] == NULL)
                    break;
            }
            printf("\n");
            printf("Directors: ");
            for(j = 0; name[i].directors[j] != NULL; j++){
                printf("%s,", name[i].directors[j]);
            }
            printf("\n\n");
        }
    }
}

void Frequecy_of_the_Genres(Name *name){
    int i = 0, j = 0, k = 0, index = 0;
    Genre *genre = (Genre*)malloc(sizeof(Genre)*100);
    for(i = 0; i < NUMBER_OF_MOVIES; i++){
        for(j = 0; name[i].genre[j+1] != NULL; j++){
            for(k = 0; k < index; k++){
                if(strcmp(genre[k].genre, name[i].genre[j]) == 0){
                    genre[k].frequency++;
                    break;
                }
            }
            if(k == index){
                genre[index].genre = (char*)malloc(sizeof(char)*100);
                strcpy(genre[index].genre, name[i].genre[j]);
                genre[index].frequency = 1;
                index++;
            }
        }
    }
    for(i = 0; i < index; i++){
        printf("%s: %d\n", genre[i].genre, genre[i].frequency);
    }
}


void List_of_genres(Name *name){
    int i = 0, j = 0, k = 0, index = 0;
    char **genre = (char**)malloc(sizeof(char*)*100);
    for(i = 0; i < NUMBER_OF_MOVIES; i++){
        for(j = 0; name[i].genre[j+1] != NULL; j++){
            for(k = 0; k < index; k++){
                if(strcmp(genre[k], name[i].genre[j]) == 0){
                    break;
                }
            }
            if(k == index){
                genre[index] = (char*)malloc(sizeof(char)*100);
                strcpy(genre[index], name[i].genre[j]);
                index++;
            }
        }
    }
    for(i = 0; i < index; i++){
        printf("%s\n", genre[i]);
    }
}