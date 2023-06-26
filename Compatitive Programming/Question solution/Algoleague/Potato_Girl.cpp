#include <iostream> 
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
typedef long long ll;
vector<int> difference_arr(vector<int> nums1, vector<int> nums2){
    vector<int> nums3;
    for(int i = 0; i < nums1.size(); i++){
        nums3.push_back(abs(nums1[i] - nums2[i]));
    }
    return nums3;
}

bool canAchieveSum(std::vector<int>& b, int a, int index, int sum) {
    if (sum == a)
        return true;

    if (index >= b.size() || sum > a)
        return false;

    bool includeCurrent = canAchieveSum(b, a, index + 1, sum + b[index]);
    bool excludeCurrent = canAchieveSum(b, a, index + 1, sum);

    return includeCurrent || excludeCurrent;
}

bool canAchieveSum(std::vector<int>& b, int a) {
    return canAchieveSum(b, a, 0, 0);
}


int main(){
    int n;
    cin >> n;

    vector<int> nums1,num2;
    int num,sum1=0,sum2=0;

    for(int i = 0; i < n; i++){
        cin >> num;
        nums1.push_back(num);
        sum1 += num;
    }
    for(int i = 0; i < n; i++){
        cin >> num;
        num2.push_back(num);
        sum2 += num;
    }

    vector<int> nums3 = difference_arr(nums1,num2);
    int num3sum=0;

    for(int i = 0; i < nums3.size(); i++){
        num3sum += nums3[i];
    }

    //sort(nums3.begin(),nums3.end());

    for(int i = 0; i < nums3.size(); i++){
        cout << nums3[i] << " ";
    }

    cout << num3sum << endl;
    cout << sum1 << " " << sum2 << endl;
    bool result = canAchieveSum(nums3,(num3sum+num3sum)/2);
    if(result)
        cout << "Potato Girl" << endl;
    else
        cout << "Sasha Blouse" << endl;
}
