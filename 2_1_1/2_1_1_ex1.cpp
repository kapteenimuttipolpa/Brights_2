#include<iostream>
int main()
{
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    
    int size = sizeof(arr) / sizeof(arr[0]);

    for(size_t i = 0; i < size; i++){
        std::cout << arr[i] << "\n";
    }
 return 0;
}