// C++ program to Find the missing element

#include <bits/stdc++.h>
using namespace std;

void findMissing(int arr[], int N)
{
	unordered_set<int> set;
	for(int i = 0; i < N; i++){
	    set.insert(arr[i]);
	}
	
	for(int i = 0; i < N; i++){
	    if(set.find(i) == set.end()){
	     cout << i << endl;   
	    }
	}
}

/* Driver code */
int main()
{
	int arr[] = { 1, 3, 7, 5, 6, 2 };
	int n = sizeof(arr) / sizeof(arr[0]);
	findMissing(arr, n);
}
