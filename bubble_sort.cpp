/* Bubble sort, sometimes referred to as sinking sort, is a simple sorting algorithm that repeatedly steps through the list, compares adjacent elements and swaps them if they are in the wrong order. The pass through the list is repeated until the list is sorted. */
//https://youtu.be/xli_FI7CuzA 

#include<iostream>
#include<algorithm>
using namespace std; 

int main (){
    
    int list[] ={23,43,12,5,6,7,12,67,99,1,67,4}; 
    size_t n = sizeof(list)/sizeof(int); 

   for (size_t i = 0; i < n-1; i++){
        for (size_t j = 0; j < n-i-1; j++){
            if(list[j] > list[j+1]){
                int temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            }
        }
    }
    for (auto i : list)
    {
        cout << i << " "; 
    }
    
}

