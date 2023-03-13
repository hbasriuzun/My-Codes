#include <iostream>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(int argc, char const *argv[])
{
    ll n, m, S_x, S_y;
    cin >> n >> m >> S_x >> S_y;
    ll max = n *m;
    cout << S_y << " " << S_x << endl;
    ll SS_x = S_x, SS_y = S_y;
    
        while (SS_x != 1)
        {
            SS_x--;
            cout << S_y << " " << SS_x << endl;
        }
        while (S_x != m)
        {
            S_x++;
            cout << S_y << " " << S_x << endl;
        }
        
        while(++S_y < n)
        {
            while (S_x != 0)
            {
                cout << S_y << " " << S_x << endl;
                S_x--;
            }
            if(++S_y < 5)
                break;
            while (++S_x < m)
            {
                cout << S_y << " " << S_x << endl;

            }
            cout << S_y << " " << S_x << endl;
        }
        S_y = 0;
        while (S_y++ != SS_y)
        {
            int bomb = 0;
            while (S_x > 0)
            {
                cout << S_y << " " << S_x << endl;
                S_x--;
                bomb++;
            }
            if(bomb != 0)
                continue;

            while (S_x != m)
            {
                S_x++;
                cout << S_y << " " << S_x << endl;      
            }
        }
        
        
    
    return 0;
    
}