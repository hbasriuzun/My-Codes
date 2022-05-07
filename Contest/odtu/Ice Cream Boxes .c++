#include <iostream>
#include <stdlib.h>

using namespace std;

typedef struct
{             
    int num1; 
    int bol; 
}numbers;

bool isPrime(int num){
    bool flag=true;
    for(int i = 2; i <= num / 2; i++) {
       if(num % i == 0) {
          flag = false;
          break;
       }
    }
    return flag;
}

int find_bolum(int num)
{
    for (int i = 2; i < num; i++)
    {
        if (num % i == 0 && isPrime(i) == true)
        {
            
        } 
    }
    
}

int main()
{
    int box,num;
    cin >> box;
    numbers nums[10];


    for (int j = 0; j < box; j++)
    {
        cin >> num;
        for (int i = 2; i < num; i++)
            {   
                if (num % i == 0 && isPrime(i) == true)
                {
                    nums[0].num1 = 0 ;
                } 
            }
    
    }
    
}