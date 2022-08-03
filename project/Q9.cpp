#include <iostream>
#include <cstdlib>
#include <ctime>

#define count 10000
using namespace std;

int make_random();
int check_win(int dice);

int main(int argc, char const *argv[])
{
    int  dice,sum =0;
    srand(time(0));
       

    for (size_t i = 0; i < count; i++)
    {
        dice = make_random();
        sum += check_win(dice);
        cout << i << endl;
    }
    cout << sum << endl; 
}

int make_random(){
    return (rand() % 11) + 2;
}

int check_win(int dice){
    if (dice == 7 || dice == 11)
    {
        return 1;
    }else if (dice == 2 || dice == 3 || dice == 12)
    {
        return 0;
    }else{
        while (1)
        {
            int dice1 = make_random();
            //cout << dice1 << endl;
            if (dice1 == 7)
            {
                return 0;
            }else if (dice == dice1)
            {
                return 1;
            }
    }}}