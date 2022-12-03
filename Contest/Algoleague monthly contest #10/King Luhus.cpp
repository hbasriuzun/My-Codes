#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    long num1,num2,main_num,count=0,left=1,right=1000000000;
    cin >> num1 >> num2;
    vector <long> divides;
    if (num1>num2)
        main_num = num2;
    else
        main_num = num1;
    
    
    
    for (size_t i = 1; i<right ; i++)
    {
        if (main_num % i == 0)
        {
            left = i;
            right = main_num / i;
            if (right == left)
            {
                divides.push_back(right);
            }else{
                divides.push_back(right);
                divides.push_back(left);
            }
        }
        
    }
    
    if (num1<num2)
        main_num = num2;
    else
        main_num = num1;

    for (size_t i = 0; i< divides.size(); i++)
    {
        if (main_num % divides[i] == 0 )
        {
            count++;
        }
     }
    //count++;
    cout << count;

    return 0;
}
