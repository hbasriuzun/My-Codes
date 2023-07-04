#include <iostream>

using namespace std;

class num
{
    public:
    int num1;
    int num2;

    num(){
        num1 = 0;
        num2 = 0;
    }
};


int main(int argc, char const *argv[])
{
    int c,b,k = 0;
    cin >> c;
    num * nu;
    nu = new num[c];



    for (size_t i = 0; i < c; i++)
    {
        cin >>  b;
        for (size_t p = 0; p < k; p++)
        {
            if(b == nu[k].num1){
            nu[k].num2 ++;
            k++;
            }else{
            
        }
        }
        

    }
    
    for (size_t i = 0; i < c; i++)
    {
        for (size_t i = 0; i < count; i++)
        {
            /* code */
        }
        
        cin >> nu[i].num1;
        nu[i].num2 ++ ;
    }
    
    for (size_t i = 0; i < c; i++)
    {
        
        cout << nu[i].num1 << "\t" << nu[i].num2 << endl;
    } 
    
    return 0;
}
