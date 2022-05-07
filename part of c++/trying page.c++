#include <iostream>
#include <ctime>
using namespace std;

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

int main()
{
    clock_t start_time,end_time;
	start_time = clock();
	int p;



    for (int i = 0; i < 2000; i++)
    {
        if (isPrime(i)==true)

        {
            cout << i <<",";
        }
        
    }
    

    for(p=0;p<3;++p)cout<<p;
	cout<<endl;
	end_time = clock();
	cout<<"Time Taken"<<(end_time - start_time)/CLOCKS_PER_SEC<<endl;
    return 0;
}