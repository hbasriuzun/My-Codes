#include <iostream>
#include <string>
#include <stack>
#include <queue>

int main(){
    std::stack<int> s;
    std::queue<int> q;
    int n, temp;
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        std::cin >> temp;
        s.push(temp);
        q.push(temp);
    }
    while (!s.empty())
    {
        std::cout << s.top() << " ";
        s.pop();
    }
    std::cout << std::endl;
    while (!q.empty())
    {
        std::cout << q.front() << " ";
        q.pop();
    }
    std::cout << std::endl;
    
    return 0;

    
}