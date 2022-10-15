#include <bits/stdc++.h> //https://www.codesdope.com/blog/article/c-linked-lists-in-c-singly-linked-list/

using namespace std;

template <typename T>
 struct node
{
  T key;
  T *next_data;
};


template <class T>
class Linked_list
{
  public:
  void Push_Front(T key);
  void Push_Back(T key);
  void Pop_Front();
  Linked_list<T>::Linked_list(node<T>* head, node<T>* tail);

  private:
    node<T> *head;
    node<T> *tail;
};

int main(int argc, char const *argv[])
{
  Linked_list<int> *first = nullptr;
  first->Push_Back(8);

  return 0;
}

template<class T>
Linked_list<T>::Linked_list(node<T>* head,node <T>* tail){
    head = nullptr;
    tail = nullptr;
  }

template<class T>
void Linked_list<T>::Push_Front(T key){
  node<T> newNode;
  newNode->key = key;
  newNode->next_node = head;
  head = &newNode;

  if(tail == nullptr)
    tail == head;
}

template<class T>
void Linked_list<T>::Pop_Front(){
  if(head == nullptr){
    printf("Error"); return;}

  head = head->next_node;
  if(head == nullptr)
    tail = nullptr;
}

template<class T>
void Linked_list<T>::Push_Back(T key){
  node<T> newNode;
  newNode.key = key;
  newNode.next_data=nullptr;
  if(tail == nullptr){
    head=&newNode;
    tail=&newNode;
  }else{
    tail.next_node = *newNode;
    tail = *newNode;
  }
}
