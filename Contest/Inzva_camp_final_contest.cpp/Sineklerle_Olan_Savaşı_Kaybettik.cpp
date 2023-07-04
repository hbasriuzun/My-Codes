#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cmath>
#include <unordered_map>

using namespace std;
#define INF 0x3f3f3f3f

typedef pair<int, int> iPair;

typedef struct cor{
    int x;
    int y;
}cor;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
	
	int n;
    cin >> n;
    cor omer,fly,trash;

    cin >> omer.x >> omer.y;
    cin >> fly.x >> fly.y;
    cin >> trash.x >> trash.y;

    cor new_fly;
    int min;

    if(omer.x > fly.x && omer.y < fly.y){
        new_fly.x = 0;
        new_fly.y = n-1;
        min = abs(omer.x - new_fly.x) + abs(omer.y - new_fly.y);
        omer = new_fly;
    }else if(omer.x < fly.x && omer.y < fly.y){
        new_fly.x = n-1;
        new_fly.y = n-1;
        min = abs(omer.x - new_fly.x) + abs(omer.y - new_fly.y);  
        omer = new_fly;
    }else if(omer.x < fly.x && omer.y > fly.y){
        new_fly.x = n-1;
        new_fly.y = 0;
        min = abs(omer.x - new_fly.x) + abs(omer.y - new_fly.y);
        omer = new_fly;
    }else if(omer.x > fly.x && omer.y > fly.y){
        new_fly.x = 0;
        new_fly.y = 0;
        min = abs(omer.x - new_fly.x) + abs(omer.y - new_fly.y);    
        omer = new_fly;
    }else if(omer.x == fly.x && omer.y < fly.y){
        new_fly.x = omer.x;
        new_fly.y = n-1;
        min = abs(omer.x - new_fly.x) + abs(omer.y - new_fly.y);
        omer = new_fly;
    }else if(omer.x == fly.x && omer.y > fly.y){
        new_fly.x = omer.x;
        new_fly.y = 0;
        min = abs(omer.x - new_fly.x) + abs(omer.y - new_fly.y);
        omer = new_fly;
    }else if(omer.x < fly.x && omer.y == fly.y){
        new_fly.x = n-1;
        new_fly.y = omer.y;
        min = abs(omer.x - new_fly.x) + abs(omer.y - new_fly.y);
        omer = new_fly;
    }else if(omer.x > fly.x && omer.y == fly.y){
        new_fly.x = 0;
        new_fly.y = omer.y;
        min = abs(omer.x - new_fly.x) + abs(omer.y - new_fly.y);
        omer = new_fly;
    }  

    int tmp = abs(omer.x - trash.x) + abs(omer.y - trash.y);
    cout << tmp + min << endl;
	return 0;
}
