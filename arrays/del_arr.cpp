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

//deletion code

int indDeletion(int arr[] , int size, int index){


    for (int i = index; i < size -1 ; i++)
    {
        arr[i] = arr[i + 1]; 
    }

    return 1;
    
}

int main()
{
    
    int arr[100] = {7, 8 , 12, 27, 88};
    int size = 5;
    int element = 45;
    int capacity = 100;
    int index = 2;
    display(arr , size);
    indDeletion(arr , size, index);
    size -= 1;
    display(arr , size);

    system("pause");
    return 0;
}

