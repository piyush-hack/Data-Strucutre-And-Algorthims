// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

int main() {
    // Write C++ code here
    int arr[] = { 3, 0, 2, 1, 4, 2, 7, 8 };
    int n = sizeof(arr) / sizeof(arr[0]);
    
    
    int maxLen = 0;
    int start = 0;
    int end = 0;
    for(int i =0; i< n; i++){
        unordered_set<int> set;
        for(int j = i; j < n; j++ ){
            cout << arr[j] << endl;
            if(set.find(arr[j]) != set.end()){
                if(maxLen < j - 1 - i){
                    maxLen = j -1 - i;
                    start = i;
                    end = j - 1;
                }
                break;
            }
            
            if(j == n-1){
                if(maxLen < j - i){
                    maxLen = j - i;
                    start = i;
                    end = j;
                }
            }
            
            set.insert(arr[j]);
        }
    }
    
    cout << start << "," << end << endl;
    return 0;
}
