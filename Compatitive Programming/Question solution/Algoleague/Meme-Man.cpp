#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int find(int stair, int x, int y, int* count, map<int, int>* memory){
    
    if(memory->find(stair) != memory->end()){
        return (*memory)[stair];
    }
    if(stair == 0){
        return 1;
    }else if(stair < 0){
        return 0;
    }

    (*memory)[stair] = find(stair - x, x, y, count, memory) + find(stair - y, x, y, count, memory);
    return (*memory)[stair];

}

int main(){
    int stair, x, y, *count = 0;
    map<int, int> *memory;
    memory = new map<int, int>;
    cin >> stair >> x >> y;
    cout << find(stair, x, y, count, memory);
    return 0;
}