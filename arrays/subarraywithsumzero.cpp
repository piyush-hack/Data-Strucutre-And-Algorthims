// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

int main() {
    // Write C++ code here
    int arr[] = {-3, 2, 1, 3, 6};
    int N = sizeof(arr) / sizeof(arr[0]);
    
    unordered_set<int> sum;
    int currSum = 0;
    bool found = false;
    for(int i =0; i < N; i++){
        currSum+= arr[i];
        if(currSum == 0 || sum.find(currSum) != sum.end()){
            found = true;
            break;
        }
        sum.insert(currSum);
    }
    if(found){
        cout << "Found" << endl;
    }else{
        cout << "Not Found" << endl;
    }
    
    return 0;
}
