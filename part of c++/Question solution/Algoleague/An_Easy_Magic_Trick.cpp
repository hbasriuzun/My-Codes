#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector <int> arr(1024);
    for(int i = 1; i < 1025; i++){
        cin >> arr[i];
    }

    int left = 0, right = 1023;

    int mid = (left + right) / 2;

    while (left <= right)
    {
        mid = (left + right) / 2;
        if(n == arr[mid]){
            std::cout << mid << " " << arr[mid] << endl;
            break;
        }else if(n < arr[mid]){
            right = mid + 1;
            std::cout << mid << " " << arr[mid] << endl;
        }else if(n > arr[mid]){
            left = mid - 1;
            std::cout << mid << " " << arr[mid] << endl;
        }
    }
    return 0;
}