#include <bits/stdc++.h>
#include <iostream>

#define endl "\n"
const int N = 1e5+5;

using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef push_back pb;

string evaluate(string s, vector<vector<string>>& knowledge) {
    map<string,string> mp;
    for(int i = 0; i < knowledge.size(); i++){
        mp[knowledge[i][0]] = knowledge[i][1];
    }
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '('){
            int left = i;
            for(int j = i+1; j < s.size(); j++){
                if(s[j] == ')'){
                    int right = j;
                    string key = s.substr(left+1,right-left-1);
                    if(mp.find(key) != mp.end()){
                        s.replace(left,right-left+1,mp[key]);
                    }
                    else{
                        s.replace(left,right-left+1,"?");
                    }
                    break;
                }
            }

        }
    }
    return s;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s = "(name)is(age)yearsold";
    vector<vector<string>> knowledge = {{"name","bob"},{"age","two"}};
    cout << evaluate(s,knowledge) << endl;

    return 0;
}