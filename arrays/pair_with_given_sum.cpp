// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

int main() {
    // Write C++ code here
    int arr[] = {8, 7, 2, 5, 3, 1 , 0 , 10};
    // 1 ,2, 3 5, 7, 8
    int n =6;
    int target = 10;
    vector<pair<int , int>> vec;
    sort(arr , arr + n);
    int l = 0;
    int r = n;
    while(l < r && l < n - 1){
        if(arr[l] + arr[r] == target){
            cout << arr[l] << "," << arr[r] << endl;
            l++;
        }else if(arr[l] + arr[r] < target){
            l++;
        }else{
            r--;
        }
    }

    return 0;
}
