#include <iostream> 
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <list>
#include <queue>

using namespace std;
typedef long long ll;

int main(){
    int n,q;
    cin >> n >> q;
    vector<int> nums;
    int num;
    nums.push_back(0);
    for(int i = 0; i < n; i++){
        cin >> num;
        nums.push_back(num);
    }
    pair<int,int> query;
    queue<pair<int,int>> queries;
    for(int i = 0; i < q; i++){
        cin >> query.first >> query.second;
        queries.push(query);
    }

    while(!queries.empty()){
        query = queries.front();
        queries.pop();
        int start = query.first, end = query.second;
        int index = (start + end) / 2,right = end, left = start;
        int sum_left = 0, sum_right = 0;
        for(int i = index + 1; i <= end; i++){
            sum_right += nums[i];
        }
        for(int i = start; i <= index; i++){
            sum_left += nums[i];
        }
        int previous_differecce = abs(sum_left - sum_right);

        while(1){
            if(sum_left == sum_right){
                cout << index << endl;
                break;
            }
            else if(sum_left > sum_right){
                sum_left -= nums[index];
                sum_right += nums[index];
                if(sum_left == sum_right){
                    cout << index << endl;
                    break;
                }else if(abs(sum_left - sum_right) > previous_differecce){
                    cout << index << endl;
                    break;
                }else if(abs(sum_left - sum_right) == previous_differecce){
                    if(nums[index] > nums[index - 1]){
                        cout << index - 1<< endl;
                        break;
                    }else if(nums[index] < nums[index - 1]){
                        cout << index << endl;
                        break;
                    }
                }else
                    previous_differecce = abs(sum_left - sum_right);
                index--;
            }
            else{
                sum_right -= nums[index];
                sum_left += nums[index];
                if(sum_left == sum_right){
                    cout << index << endl;
                    break;
                }else if(abs(sum_left - sum_right) > previous_differecce){
                    cout << index << endl;
                    break;
                }else if(abs(sum_left - sum_right) == previous_differecce){
                    if(nums[index] > nums[index + 1]){
                        cout << index + 1 << endl;
                        break;
                    }else if(nums[index] < nums[index + 1]){
                        cout << index << endl;
                        break;
                    }
                }else
                    previous_differecce = abs(sum_left - sum_right);
                index++;
            }

            
        }


        
    }
    return 0;
}