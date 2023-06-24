#include <iostream>
#include <vector>

using namespace std;

class dominant
{
    public:
    int num1;
    int num2;

    dominant()
    {
        num1 = 0;
        num2 = 0;
    }

    void plus()
    {
        num2++;
    }
};
int main(int argc, char const *argv[])
{
    int test_case;
    cin >> test_case;

    for (size_t i = 0; i < test_case; i++)
    {
        int arr_size;
        cin >> arr_size;
        vector <dominant> number;
        number.resize(1);
            int num;
            cin >> num;
        number[0].num1 = num;
        number[0].num2 ++;

        
        for (size_t j = 1; j < arr_size; j++)
        {
            cin >> num;
            for (size_t k = 0; k < number.size(); k++)
            {
                if (num == number[k].num1)
                {
                    number[k].plus();
                    break;
                }else{
                    number.resize(number.size()+1);
                    number[number.size()-1].num1 = num;
                    number[number.size()-1].plus();
                }
                
            }
            

        }
        
        
        int big = 0;
        for (size_t j = 0; j < arr_size; j++)
        {
            if (big < number[j].num2)
            {
                big = number[j].num2;
            }
            

        }
        
        int t=0;

        for (size_t j = 0; j < arr_size; j++)
        {
            if (big == number[j].num2)
            {
                t++;
            }
            
        }
        if (number.size() == arr_size ){
            cout << "NO" << endl;
            continue;
        }

        if (t = 1)
        {
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;

        }
        


    }
    
    return 0;
}
