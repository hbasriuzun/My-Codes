#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
//    int *pnumber{new int(100000000000)};

    
    for (size_t i = 0; i < 100000; i++)
    {
        int *pnumber{new int[10000000000000000]};
    }
    
/*
   try{

   }catch(exception & ex){
       cout << "something went wrong :" << ex.what() << endl; 
   }
    */
    /*
    for (size_t i = 0; i < 100; i++)
    {      
        try{
            
            int * data = new int[100000000];
        }catch(std::exception& ex){

            cout << i << "something went wrong :" << ex.what() << endl; 
        }
    }
    */
   /*
   for (size_t i = 0; i < 10000; i++)
   {
       int * pnumber = new int[10000000000]; 

        if (pnumber != nullptr){
            cout << "Data allocated" << endl;
        }else{
            cout << i << "Data allocation failed" << endl;
        }
        


   }
   */


    cout << "Program is ending well" << endl;


    return 0;
}
