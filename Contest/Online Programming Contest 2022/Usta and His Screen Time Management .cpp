#include <bits/stdc++.h>
using namespace std;

bool section(int num1,int num2, int num3){
    if(num1 > num2 && num2<num3 )
        return true;
    else if(num1 < num2 && num2 > num3)
        return true;
    return false;
}

int main(int argc, char const *argv[])
{
    int n,num1,num2,count=0,num3 ;
    bool x;
    scanf("%d",&n);

    if(n<3){
        cout << count;
        return 0;
    }
   scanf("%d %d %d",&num1,&num2,&num3);
    if(n==3){
        if(num1 == num2 && num2 == num3){
            count+=2;
            cout << count;
            return 0;
        }
        if(num1==num3){
            count++;
        }else if(x==true){
            num1=num2;
            num2=num3;

        }else if(x==false){
            count++;
            num2 = num3;
        }
        cout << count;
        return 0;
    }

    n-=3;


    while (n--)
    {

        if(num1==num3){
            count++;
            scanf("%d",&num3);
            continue;
        }
        x = section(num1,num2,num3);
            if(x==true){
            num1=num2;
            num2=num3;
            scanf("%d",&num3);
            continue;

        }else if(x==false){
            count++;
            num2 = num3;
            scanf("%d",&num3);
        }
    }

        x = section(num1,num2,num3);

        if(num1==num3){
            count++;
        }else if(x==true){
            num1=num2;
            num2=num3;

        }else if(x==false){
            count++;
            num2 = num3;
        }

    printf("%d",count);
    return 0;
}
