// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

int main() {
    // Write C++ code here
    int nums[] = { 5, 6, -5, 5, 3, 5, 3, -2, 0 };
    int target = 8;
 
    int n = sizeof(nums) / sizeof(nums[0]);
    
    unordered_map<int , int> map;
    map[0] = -1;
    int sum = 0;
    int len = 0;
    int end = -1;
    
    for(int i = 0; i < n; i++){
        sum += nums[i];
        if(map.find(sum) == map.end()){
            map[sum] = i;
        }
        if(map.find(sum - target) != map.end() && len < i - map[sum - target]){
            len = i - map[sum - target];
            end = i;
            
        }
    }
    
     cout << end - len + 1 << ", " << end << endl;

    return 0;
}
