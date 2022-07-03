#include <iostream>
using namespace std;

// Class of a Node
class Node {
    int data;
    Node *next;
    public:
        Node(int i):data(i),next(NULL) {}
        // Methods

        // 1. Adds the given node as next of the current node
        inline void setNext(Node *node) {
            this->next = node;
        }

        // 2. Returns data of the current node
        inline int Data() {
            return this->data;
        }

        // 3. Return pointer of the next node
        inline Node * Next() {
            return this->next;
        }
};

// Class of a List
class List {
    Node *Head;
    public:
        List():Head(NULL) {}
        // Methods

        // 1. Add a Node at the Front
        void push_front(int i);

        // 2. Add a node at the end 
        void push_back(int i);

        //3. Print List
        void print();
};

void List::push_front(int i) {
    // Create a New Node
    Node *node = new Node(i);

    // Set Next of Node to Head of the current list.
    //  (Node)->(Current List)
    node->setNext(Head);
    Head = node;
}

void List::push_back(int i) {
    // Create a New Node
    Node *node = new Node(i);

    // Iterate through the end of the list and set new node as next
    // of last node
    //  (Current List)->(Node)

    // List is empty so new node is a head and return 
    if(Head == NULL) {
        Head = node;
        return;
    }

    Node *curr = Head;

    while(curr && curr->Next()) {
        curr = curr->Next();
    }

    // At this point curr is the last node
    // Set node as the next of the last node

    curr->setNext(node);
}

// Iterate through a list
void List::print() {
    // Start from the head of a list
    Node *curr = Head;
    while(curr) {
        cout << curr->Data();
        cout << "->";
        curr = curr->Next();
    }
    cout << "NULL \n";
}

int main() {
    List list;
    list.push_front(1);
    list.push_front(2);
    list.push_front(3);
    list.push_front(4);

    list.print();

    // Output : 4->3->2->1->NULL

    List list2;
    list2.push_back(1);
    list2.push_back(2);
    list2.push_back(3);
    list2.push_back(4);
    list2.print();
    // Output : 1->2->3->4->NULL
}