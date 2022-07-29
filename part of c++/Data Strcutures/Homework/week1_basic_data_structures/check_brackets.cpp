#include <iostream>
#include <stack>
#include <string>
using namespace std;
struct Bracket {
    Bracket(char type, int position) : type(type), position(position) {}

    bool Matchc(char c) {
        if (type == '[' && c == ']')
            return true;
        if (type == '{' && c == '}')
            return true;

            if (type == '(' && c == ')')
            return true;
        return false;
    }

    char type;
    int position;
};

int main() {
    std::string text;
    getline(std::cin, text);
    if(text.size()==1){
    cout << text.size() << endl;
    return 0;
    }
    if(text[0] == '}' || text[0] == '}' || text[0] == '}' ){
    cout << "1" << endl;
    return 0;
    }
    int position;

    std::stack <Bracket> opening_brackets_stack;
    for (position = 0; position < text.length(); ++position) {
        char next = text[position];

        if (next == '(' || next == '[' || next == '{') {
            // Process opening bracket, write your code here
            opening_brackets_stack.push({next,position});
            
        }

        if (next == ')' || next == ']' || next == '}') {
            // Process closing bracket, write your code here
            if (opening_brackets_stack.size() == 0){
                cout << position + 1 << endl; return 0;} 
            
            if(opening_brackets_stack.top().Matchc(next))
            opening_brackets_stack.pop();
            else if (!(opening_brackets_stack.top().Matchc(next)))
            {
                cout << position + 1 << endl;
                exit(1);
            }
            
        }
    }

   /* if (opening_brackets_stack.size() > 0)
    {
        cout << position << endl;
        return 0; 
    }
    */
    if(opening_brackets_stack.empty())
    cout << "Success" << endl;
    else
    cout << opening_brackets_stack.top().position + 1 << endl;
    // Printing answer, write your code here

    return 0;
}
