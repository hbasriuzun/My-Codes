#include <bits/stdc++.h>

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
    
    auto start = std::chrono::high_resolution_clock::now();

    cout << find(stair, x, y, count, memory);

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    std::cout << "Program çalışma süresi: " << duration.count() << " saniye." << std::endl;
    return 0;
}