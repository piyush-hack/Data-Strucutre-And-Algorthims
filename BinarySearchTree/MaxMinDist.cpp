#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool isFesible(int mid, int arr[], int n, int k, vector<int> &ans)
{
    int pos = arr[0], elements = 1;
    ans.push_back(pos);

    for (int i = 1; i < n; i++)
    {
        if (arr[i] - pos >= mid)
        {
            pos = arr[i];
            ans.push_back(pos);
            elements++;
            if (elements == k)
            {
                return true;
            }
        }
    }
    ans.clear();
    return false;
}

int larMinDist(int arr[], int n, int k, vector<int> &ans)
{
    sort(arr, arr + n);

    int result = -1;
    int left = 1, right = arr[n - 1];

    while (left < right)
    {
        int mid = (left + right) / 2;
        if (isFesible(mid, arr, n, k, ans))
        {
            result = max(result, mid);
            left = mid + 1;
        }
        else
        {
            right = mid;
        }
    }

    return result;
}

int main()
{
    int arr[] = {2, 3, 8, 4, 9};
    int n = 5;
    vector<int> ans;
    int k = 3;
    cout << "largest min distance " << larMinDist(arr, n, k, ans) << endl;
    for(auto i : ans){
        cout << i << " ";
    }
    return 0;
}