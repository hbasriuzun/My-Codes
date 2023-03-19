#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll t;
    cin >> t;
    ll t2 = t;
    stack <ll> muffin;
    stack <ll> muf2;
    ll muf;
    while (t--)
    {

        cin >> muf;
        muffin.push(muf);
    }

    while(!muffin.empty()){
        while (!muffin.empty() && muffin.top() == 0)
        {
            muf2.push(muffin.top());
            muffin.pop();
        }
        while (!muffin.empty() && muffin.top() != 2)
        {
            if(muffin.top() == 1){
                muf2.push(muffin.top());
                muffin.pop();
            }else{
                muffin.pop();
            }
        }
        while(!muffin.empty())
        {
            if(muffin.top() == 2){
                muf2.push(muffin.top());
                muffin.pop();
            }else{
                muffin.pop();
            }
        }
        
    }
    while (!muf2.empty())
    {
        cout << muf2.top() << " ";
        muf2.pop();
    }

    return 0;
}