#include<iostream>
using namespace std;

void duplicate_missing(int* arr, int size){
    int check[size] = {};
    for(int i = 0; i < size; i++){
        check[arr[i]]++; 
    }

    for (size_t i = 0; i < size; i++)
    {
        if(check[i]==0) cout<< i << " doesn't exit" << endl; 
        if(check[i] > 1) cout<< i << " is duplicate"; 
    }
    
}
int main(){
    int arr[] = {1,3,3,0}; 
    int size = sizeof(arr)/sizeof(arr[0]); 

    duplicate_missing(arr, size);
    return 0;
}