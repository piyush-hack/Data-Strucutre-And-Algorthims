#include <iostream>
using namespace std;


//traversal code
void display(int arr[], int n){

    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << " " ;
    }

    std::cout << std::endl;
    
}

//insertion code

int indInsertion(int arr[] , int size, int element, int capacity, int index){

    if (size >= capacity)
    {
        return -1;
    }

    for (int i = size-1; i >= index; i--)
    {
        arr[i+1] = arr[i]; 
    }

    arr[index] = element;
    return 1;
    
}

int main()
{
    
    int arr[100] = {7, 8 , 12, 27, 88};
    int size = 5;
    int element = 45;
    int capacity = 100;
    int index = 3;
    display(arr , size);
    indInsertion(arr , size, element, capacity, index);
    size += 1;
    display(arr , size);

    system("pause");
    return 0;
}
