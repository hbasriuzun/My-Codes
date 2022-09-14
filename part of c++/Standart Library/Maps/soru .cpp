#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char * argv[]) {
    int N,toplam=0,count=0,a,b,c,d;
        cin>>N;
        
        int mat[N][3];
        
        for(int i=0;i<N;i++){
            for(int j=0;j<3;j++){
                cin>>mat[i][j];
            }
        }
        int max=mat[0][0];
        
        for(int i=0;i<N;i++){
            for(int j=0;j<3;j++){
                if(mat[i][j]>max){
                    max=mat[i][j];
                    a=i;
                    b=j;
                }
            }
        }
          
        
        toplam+=max;
    
        int mat1[N-1][2];
    for(int i=0;i<N-1;i++){
        for(int j=0;j<2;j++){
            if(i==a || j==b){
                continue;
            }
            else{
                mat1[i][j]=mat[i][j];
            }
        }
    }
    
    int max1=mat1[0][0];
    for(int i=0;i<N-1;i++){
        for(int j=0;j<2;j++){
            if(mat1[i][j]>max1){
                max1=mat1[i][j];
                c=i;
                d=j;
            }
        }
    }
    toplam+=max1;
    
    int mat2[N-2][1];
for(int i=0;i<N-2;i++){
    for(int j=0;j<1;j++){
        if(i==c || j==d){
            continue;
        }
        else{
            mat2[i][j]=mat1[i][j];
        }
    }
}
    
        
        int max2=mat2[0][0];
    for(int i=0;i<N-2;i++){
        for(int j=0;j<1;j++){
            if(mat2[i][j]>max1){
                max2=mat2[i][j];
            }
        }
    }
         
        
        
        toplam+=max2;
        
        cout<<toplam;
        
   
    return 0;
}