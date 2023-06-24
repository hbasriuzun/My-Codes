#include <iostream>

using namespace std;

class Burcu{
    public:

    void write_brthy();
    
    
    
    private:
    int brthdy_day{10};
    int brthdy_month{4};
    int brthdy_year{2003};
};

int main(int argc, char const *argv[])
{
    Burcu *a;
    a = new Burcu();
    a->write_brthy();

    delete a;
    a = nullptr;

  
    return 0;
}

void Burcu::write_brthy(){
    printf("%d.%d.%d",brthdy_day,brthdy_month,brthdy_year);
} 
