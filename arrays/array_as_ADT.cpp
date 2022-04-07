#include <iostream>
using namespace std;


//creating a ADT of array named as myarray
class myarray
{
private:
    /* data */
public:

    int total_size;
    int used_size;
    int *ptr;
    
    void create_array(int total_size, int u_size);
    void show();
    void setval();
};

void myarray::create_array(int t_size, int u_size)
{
    total_size = t_size;
    used_size = u_size;

    //reserving a specific memory in heap . Dynamic memory allocation
    ptr = (int*) malloc( t_size * sizeof(int));

}

void myarray::show(){

    std::cout << "Elements are " << std::endl;

    for(int i = 0; i < used_size; i++){

        std::cout << ptr[i] << " ";

    }

    std::cout << std::endl;
}

void myarray::setval(){

    int n;
    for (int i = 0; i < used_size; i++)
    {
        std::cout << "Enter element " << i << std::endl;
        cin >> n ;
        ptr[i] = n;
    }
    

}


int main()
{
    myarray arr;
    arr.create_array(10, 2);
    arr.setval();
    arr.show();
    
    system("pause");
    return 0;
}
