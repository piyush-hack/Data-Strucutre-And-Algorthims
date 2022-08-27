// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

int main() {
    // Write C++ code here
    vector<int> nums = { 1, 2, 3, 4, 4 };
    
    for(int i =0; i< nums.size(); i++){
        if(nums[abs(nums[i])] > 0){
            nums[abs(nums[i])] =  -nums[abs(nums[i])] ;
            
        }else{
            cout << "Duplicate " << abs(nums[i]) << endl;
            break;
        }
        
    }
    return 0;
}
