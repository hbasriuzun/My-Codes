#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Budget {
    int budget;
    int year;
    char *title;
    char *titletype;
    char *top250;
};

struct Name {
    char **genre;
    char *title;
    char **directors;
    char *mustsee;
    double rating;
    double votes;
    char *url;
};

struct Budget *budgetArray = NULL;
struct Name *nameArray = NULL;
int numMovies = 0;

void readMovieFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    char line[1024];
    while (fgets(line, sizeof(line), file)) {
        line[strcspn(line, "\r\n")] = 0;  // Remove newline characters

        char *token = strtok(line, ";");
        int budget = atoi(token);
        
        token = strtok(NULL, ";");
        char *title = strdup(token);
        
        token = strtok(NULL, ";");
        char *titletype = strdup(token);      

        token = strtok(NULL, ";");
        char *directorsToken = strdup(token);
        char *director = strtok(directorsToken, ",");

        char **directors = NULL;
        int directorCount = 0;
        while (director != NULL) {
            directors = realloc(directors, (directorCount + 1) * sizeof(char *));
            directors[directorCount] = strdup(director);
            director = strtok(NULL, ",");
            directorCount++;
        }

        token = strtok(NULL, ";");
        double rating = atof(token);


        token = strtok(NULL, ";");
        int year = atoi(token);

        token = strtok(NULL, ";");
        char *genreToken = strdup(token);
        char *genre = strtok(genreToken, ",");

        char **genres = NULL;
        int genreCount = 0;
        while (genre != NULL) {
            genres = realloc(genres, (genreCount + 1) * sizeof(char *));
            genres[genreCount] = strdup(genre);
            genre = strtok(NULL, ",");
            genreCount++;
        }

        token = strtok(NULL, ";");
        double votes = atof(token);


        token = strtok(NULL, ";");
        char *top250 = strdup(token);



        token = strtok(NULL, ";");
        char *mustsee = strdup(token);


        token = strtok(NULL, ";");
        char *url = strdup(token);

        budgetArray = realloc(budgetArray, (numMovies + 1) * sizeof(struct Budget));
        budgetArray[numMovies].budget = budget;
        budgetArray[numMovies].year = year;
        budgetArray[numMovies].title = title;
        budgetArray[numMovies].titletype = titletype;
        budgetArray[numMovies].top250 = top250;

        nameArray = realloc(nameArray, (numMovies + 1) * sizeof(struct Name));
        nameArray[numMovies].genre = genres;
        nameArray[numMovies].title = title;
        nameArray[numMovies].directors = directors;
        nameArray[numMovies].mustsee = mustsee;
        nameArray[numMovies].rating = rating;
        nameArray[numMovies].votes = votes;
        nameArray[numMovies].url = url;

        numMovies++;
    }

    fclose(file);
}

void listBudgetArray() {
    for (int i = 0; i < numMovies; i++) {
        printf("Budget: %d, Year: %d, Title: %s, Type: %s, Top 250: %s\n",
               budgetArray[i].budget, budgetArray[i].year,
               budgetArray[i].title, budgetArray[i].titletype,
               budgetArray[i].top250);
    }
}

void listNameArray() {
    for (int i = 0; i < numMovies; i++) {
        printf("Title: %s, Genre: ", nameArray[i].title);
        for (int j = 0; j < numMovies; j++) {
            printf("%s", nameArray[i].genre[j]);
            if (j != numMovies - 1) {
                printf(", ");
            }
        }
        printf(", Directors: ");
        for (int j = 0; j < numMovies; j++) {
            printf("%s", nameArray[i].directors[j]);
            if (j != numMovies - 1) {
                printf(", ");
            }
        }
        printf(", Must See: %s, Rating: %.2f, votes: %.2f, URL: %s\n",
               nameArray[i].mustsee, nameArray[i].rating, nameArray[i].votes,
               nameArray[i].url);
    }
}

void listGenres() {
    for (int i = 0; i < numMovies; i++) {
        for (int j = 0; j < numMovies; j++) {
            printf("%s", nameArray[i].genre[j]);
            if (j != numMovies - 1) {
                printf(", ");
            }
        }
    }
}

void listMoviesThroughYears() {
    for (int i = 0; i < numMovies; i++) {
        printf("Year: %d, Title: %s\n", budgetArray[i].year, budgetArray[i].title);
    }
}

void listMoviesThroughvotess() {
    for (int i = 0; i < numMovies; i++) {
        printf("votes: %.2f, Title: %s\n", nameArray[i].votes, nameArray[i].title);
    }
}

void getMovieInfo() {
    int movieIndex;
    printf("Enter the movie index: ");
    scanf("%d", &movieIndex);

    if (movieIndex < 0 || movieIndex >= numMovies) {
        printf("Invalid movie index.\n");
        return;
    }

    printf("Title: %s\n", nameArray[movieIndex].title);
    printf("Year: %d\n", budgetArray[movieIndex].year);
    printf("Budget: %d\n", budgetArray[movieIndex].budget);
    printf("Type: %s\n", budgetArray[movieIndex].titletype);
    printf("Top 250: %s\n", budgetArray[movieIndex].top250);
    printf("Genre: ");
    for (int i = 0; i < numMovies; i++) {
        printf("%s", nameArray[movieIndex].genre[i]);
        if (i != numMovies - 1) {
            printf(", ");
        }
    }
    printf("\n");
    printf("Directors: ");
    for (int i = 0; i < numMovies; i++) {
        printf("%s", nameArray[movieIndex].directors[i]);
        if (i != numMovies - 1) {
            printf(", ");
        }
    }
    printf("\n");
    printf("Must See: %s\n", nameArray[movieIndex].mustsee);
    printf("Rating: %.2f\n", nameArray[movieIndex].rating);
    printf("votes: %.2f\n", nameArray[movieIndex].votes);
    printf("URL: %s\n", nameArray[movieIndex].url);
}

void countGenres() {
    int count = 0;
    for (int i = 0; i < numMovies; i++) {
        for (int j = 0; j < numMovies; j++) {
            count++;
        }
    }
    printf("Number of genres: %d\n", count);
}

void freeArrays() {
    for (int i = 0; i < numMovies; i++) {
        free(budgetArray[i].title);
        free(budgetArray[i].titletype);
        free(budgetArray[i].top250);

        for (int j = 0; j < numMovies; j++) {
            free(nameArray[i].genre[j]);
            free(nameArray[i].directors[j]);
        }
        free(nameArray[i].genre);
        free(nameArray[i].title);
        free(nameArray[i].directors);
        free(nameArray[i].mustsee);
        free(nameArray[i].url);
    }

    free(budgetArray);
    free(nameArray);
}

int main(int argc, char *argv[]) {

    const char *filename = "movie.txt";
    readMovieFile(filename);

    int choice;

        printf("\nMenu:\n");
        printf("1. List of budget array\n");
        printf("2. List of name array\n");
        printf("3. List of genres\n");
        printf("4. List of the Movie Through the Years\n");
        printf("5. List of the Movie Through the votess\n");
        printf("6. All Information of a Single Movie\n");
        printf("7. Frequency of the Genres\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                listBudgetArray();
                break;
            case 2:
                listNameArray();
                break;
            case 3:
                listGenres();
                break;
            case 4:
                listMoviesThroughYears();
                break;
            case 5:
                listMoviesThroughvotess();
                break;
            case 6:
                getMovieInfo();
                break;
            case 7:
                countGenres();
                break;
            case 8:
                freeArrays();
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    

    return 0;
}