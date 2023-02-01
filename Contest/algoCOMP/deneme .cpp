#include<iostream>
using namespace std;
const int MAXN = 1005;
int r, c, wr, wc, q, x, y;
char op, dir;
int m[MAXN][MAXN];
int main()
{
    cin >> r >> c >> wr >> wc >> q;
    
    wr--, wc--;
    m[wr][wc] = 1;
    for(int i = 1; i <= q; i++)
    {
        cin >> op >> dir;
        if(op == '1')
        {
            if(dir == 'u') wr--;
            if(dir == 'd') wr++;
            if(dir == 'l') wc--;
            if(dir == 'r') wc++;
            wr = (wr + r) % r;
            wc = (wc + c) % c;
        }
        else
        {
            if(dir == 'u') m[wr - 1][wc]++;
            if(dir == 'd') m[wr + 1][wc]++;
            if(dir == 'l') m[wr][wc - 1]++;
            if(dir == 'r') m[wr][wc + 1]++;
            wr = (wr + r) % r;
            wc = (wc + c) % c;
        }
    }
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            cout << m[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
