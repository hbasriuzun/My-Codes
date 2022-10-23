#include <bits/stdc++.h>
using namespace std;
class Tree
{
private:
    


public:

    void Height(Tree tree);

    Tree(/* args */);
    ~Tree();
};

Tree::Tree(/* args */)
{
}

Tree::~Tree()
{
}

int main(int argc, char const *argv[])
{
    
    return 0;
}

int Tree::Height(Tree tree){
    if(tree == NULL)
        return 0;
    return 1 + max(Height(tree.right),Height(tree.left));   
    vector<int> a;
    
}