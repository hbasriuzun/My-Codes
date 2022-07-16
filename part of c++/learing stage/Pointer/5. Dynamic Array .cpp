#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    const size_t size{10};

    double *p_salaries {new double[size]};
    int *p_student {new (std::nothrow) int[size]};
    double *p_scores {new(std::nothrow) double[size]{1,2,3,4,5}};

    if (p_scores){
        


        for (size_t i = 0; i < size; i++){
            cout << "value :" << *(p_scores + i) << endl;
        }
        
    }
    
    delete [] p_scores;
    p_scores = nullptr;

    delete [] p_student;
    p_student = nullptr;

    delete [] p_salaries;
    p_salaries = nullptr;

    cout << "====================================" << endl;

    int scores[10]{1,2,3,4,5,6,7,8,9,10};

    for (auto s : scores){
        cout << "value : " << s << endl;
    }
    


    return 0;
}
