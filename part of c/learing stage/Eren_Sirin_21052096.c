#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int **create2DArray(int n, int m);
void fillRandomNumbers(int** adrr2D,int n, int m);
int *create1DArray(int m);
void addColumn(int **arr2D,int *arr1D, int n,int m);
void print2DArray(int **arr2D,int n,int m);

int i,j;
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    int ** arr2D;
    arr2D = create2DArray(n,m);
    int *arr1D=create1DArray(n*m);
    fillRandomNumbers(arr2D,n,m);
    addColumn(arr2D,arr1D,n,m);
    for(i = 0; i < n; i++){
        printf("%d ",arr1D[i]);
    }
    //in main. Write all elemnts of arr1D to a file named “data.txt”. All line must contain 1 integer in the file.
    FILE *fp;
    fp = fopen("data.txt", "w");
    if (fp == NULL) {
        printf("Dosya acilamadi.\n");
        return 1;
    }
    for(i = 0; i < n; i++){
        fprintf(fp,"%d\n",arr1D[i]);
    }

    fclose(fp);

    return 0;
}

int **create2DArray(int n, int m){
    int **arr = (int **)malloc(n * sizeof(int *));
    for( i = 0; i < n; i++){
        arr[i] = (int *)malloc(m * sizeof(int));
    }
    return arr;
}

void fillRandomNumbers(int** arr2D,int n, int m){
    srand(time(NULL));
    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            arr2D[i][j] = rand() % 100 + 1;
        }
    }
}

int *create1DArray(int m){
    int *arr = (int *)malloc(m * sizeof(int));
    return arr;
}

void addColumn(int **arr2D, int *arr1D, int n, int m) {
    for (j = 0; j < m; j++) {
        int sum = 0;
        for (i = 0; i < n; i++) {
            sum += arr2D[i][j];
        }
        arr1D[j] = sum;
    }
}

void print2DArray(int **arr2D,int n,int m){
    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            printf("%d ",arr2D[i][j]);
        }
        printf("\n");
    }
}