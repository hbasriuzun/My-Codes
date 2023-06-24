#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    /*
    int * pnumber;

    cout << endl;
    cout << "pnumber :" << pnumber << endl;
    cout << "*pnumber :" << *pnumber << endl;
    */
   /*
    int *pnumber{new int{67}};

    cout << "pnumber: " << *pnumber << endl;
    
    delete pnumber;

    cout << "pnumber: " << *pnumber << endl;
    */

   int *pnumber {new int(89)};
    int *pnumber1 {pnumber};
   cout << pnumber << "-" << *pnumber << endl ;
   cout << pnumber1 << "-" << *pnumber1 << endl ;

    delete pnumber;
    //pnumber1 = nullptr;

   cout << pnumber1 << " - " ;
   if (pnumber1 != nullptr){
        cout << *pnumber1 << endl ;
   }else{
       cout << "invalid adress " << endl;
   }

   


    cout << "program ending well" << endl;



    return 0;
}
