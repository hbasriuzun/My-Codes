#include <bits/stdc++.h> //https://www.codesdope.com/blog/article/c-linked-lists-in-c-singly-linked-list/

using namespace std;

template <typename T>
 struct node
{
  T key;
  node<T> *next_data;
};


template <class T>
class Linked_list
{
  public:
  void Push_Front(T key);
  void Push_Back(T key);
  void Pop_Front();
  void Pop_Back();

  Linked_list();
  //Linked_list(node<T>* head, node<T>* tail);
  node<T>* Return_head(){return head;}
  node<T>* Return_tail(){return tail;}
  void Add_head(node<T> *newhead){head = newhead;}
  void Add_tail(node<T> *newtail){tail = newtail;}


  private:
    node<T> *head;
    node<T> *tail;
};

int main(int argc, char const *argv[])
{
  Linked_list<int> first;
  first.Push_Front(8);

  return 0;
}

template<class T>
//Linked_list<T>::Linked_list(node<T>* head,node <T>* tail)
Linked_list<T>::Linked_list(){
    head = NULL;
    tail = NULL;
  } 

template<class T>
void Linked_list<T>::Push_Front(T key){
  node<T> *newNode = new node<T>;
  newNode->key = key;
  newNode->next_data = head;
  head = newNode;

  if(tail == NULL)
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
  node<T>* newNode = new node<T>;
  newNode->key = key;
  newNode->key=nullptr;
  if(Return_tail() == nullptr){
    head=newNode;
    tail=newNode;
  }else{
    Return_tail()->next_data = newNode;
    Add_tail(newNode);
  }
}

  template<class T>
  void Linked_list<T>::Pop_Back(){
    if(head == nullptr){
    printf("Error"); return;}

    if(head == tail){
      head=NULL;
      tail=nullptr;
    }else{
      node<T>* ptr=head;
      while(head->next_data->next_data != nullptr){
        ptr=ptr->next_data;
      }
      ptr->next_data=nullptr;
    }
  }

  