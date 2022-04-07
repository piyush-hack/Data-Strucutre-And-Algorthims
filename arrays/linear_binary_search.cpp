#include <iostream>
using namespace std;

int linerarSearch(int arr[], int size, int element)
{

    for (int i = 0; i < size; i++)
    {
        if (arr[i] == element)
        {
            return i;
        }
    }

    return -1;
}

int binarySearch(int arr[], int size, int element)
{
    int low, mid, high;

    low = 0;
    high = size -1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == element)
        {
            return mid;
        }

        if (arr[mid] < element)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return -1;
}
int main()
{
    int arr[] = {1, 3, 5, 4, 32, 56, 74, 235, 545};
    int size = sizeof(arr) / sizeof(int);
    int element = 56;
    int searchIndex = linerarSearch(arr, size, element);
    std::cout << "Found at " << searchIndex << std::endl;

    int bsearchIndex = binarySearch(arr, size, element);
    std::cout << "Found at " << bsearchIndex << std::endl;
    system("pause");
    return 0;
}
