#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
//    int *pnumber{new int(100000000000)};

    /*
    for (size_t i = 0; i < 100000; i++)
    {
        int *pnumber{new int(100000000000)};
    }
    */
/*
   try{

   }catch(exception & ex){
       cout << "something went wrong :" << ex.what() << endl; 
   }
    */
    
    for (size_t i = 0; i < 100000000; i++)
    {   
        try{
            
            int * data = new int[100000];
        }catch(std::exception& ex){

            cout << "something went wrong :" << ex.what() << endl; 
        }

    }

    cout << "ending well" << endl;


    return 0;
}
