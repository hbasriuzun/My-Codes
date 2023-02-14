#include <iostream>

using namespace std;

class node{
    public:
    string value;
    node* next;
};

int main(int argc, char const *argv[])
{
    
    node* head = nullptr;
    node* hasan = NULL;
    node* basri = nullptr;
    node* uzun = nullptr;

    hasan = new (std::nothrow) node();
    basri = new (std::nothrow) node();
    uzun = new (std::nothrow) node();
    
    hasan->value = "I ";
    basri->value = "Love ";
    uzun->value = "You ";

    head = hasan;
    hasan ->next = basri;
    basri ->next = uzun;
    uzun ->next = nullptr;

    while (head != NULL) {
    cout << head->value;
    head = head->next;
  }




    return 0;
}
