//Brace your keyboard
//inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <list>


using namespace std;
typedef long long ll;

class Node{
    public:
        int node;
        int size;
        Node::Node(){
             size = 0;
        }
};

ll find_hibiscus(vector<vector<Node>> tree){
    int size = tree.size();
    if(tree[1].size() == 0)
        return 0;
    
    int lenght = 0,count = 0,curr_node;
    Node child_node;
    bool explored = new bool[size];
    for(int i = 0; i < size; i++)
        explored[i] = false;

    list<int> frontier;
    frontier.push_back(1);
    explored[1] = true;
    
    while(!frontier.empty()){
        Node curr_node;
        curr_node.node = frontier.front();
        frontier.pop_front();
        
        for(auto j = tree[curr_node.node].begin() ; j != tree[curr_node.node].end(); j++){
            child_node = *j;
            child_node.size = curr_node.size + 1;
            if(!explored[child_node.node]){
                explored[child_node.node] = true;
                frontier.push_back(child_node.node);
            }
            
        }
    }
    
} 

int main() {
    vector <vector<Node>> tree;
    int number_of_node;
    Node first, second;
    cin >> number_of_node;
    for(int i = 0; i < number_of_node; i++){
        cin >> first.node >> second.node;
        tree[first.node].push_back(second);
        tree[second.node].push_back(first);
    }

	return 0;
}
