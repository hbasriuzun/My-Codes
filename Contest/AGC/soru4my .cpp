#include <stdio.h>
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <new>

using namespace std;

void F(int N,int main[N][N], int M,int** Operation); 
int carp(int N,int main[N][N], int M,int** Operation);

int main()
    {
    int N,M,i,j,index;

    
    std::cin >> M >> N;
    int** matrix = new int*[N];
    for (int i = 0; i < M; ++i)
    matrix[i] = new int[N];

    int main[N][N];
    float Operation[M][M];

    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            scanf("%d",main[i][j]);
        }
    }ov

    for(i=0;i<M;i++){
        for(j=0;j<M;j++){
            scanf("%f",Operation[i][j]);
        }
    }

    

    F(N,main[N][N],M,matrix);


    return 0;
}

void F(int N, int main[N][N], int M, int** Operation)
{
    int i,j,a;
    if(N%M==0 && N%2!=0 && M%2!=0){
        a=(int)M/2;
        for(i=0;i<M;i++){
            for(j=0;j<M;j++){
                main[a+i][a+j]=carp(N,main[N][N],M,Operation[M][M])/(M*M);
            }
        }
        for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            printf("%d ",main[i][j]);
        }
        printf("\n");
    }

    }
    
    else{
        printf("Bu islem gerceklestirilemez");
    }

}



int carp(int N,int main[N][N], int M,int** Operation)
{
    int i,j,a,b;
    a=(int)M/2;
    for(i=0;i<M;i++){
        for(j=0;j<M;j++){
            main[a+i][a+j]+=main[i][j]*Operation[i][j];
            return carp(N,main[N-1][N-1],M,Operation[M-1][M-1]);
            if(N==0 || M==0){
                return (main[a+i][a+j]);
        
            }
        }
    }
}