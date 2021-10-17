#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

void bubble_sort(vector<int>& list, int n){

    for(int i = 0 ; i < n-1; i++){
        for(int j = 0; j < n-i-1; j++){
            if(list[j] > list[j+1]){
                swap(list[j],list[j+1]); 
            }
        }
    }
}

int main(){

    vector<int> list = {57,1,24,6,78,23};

    bubble_sort(list, list.size()); 

    for (auto &&i : list){
        cout << i << " "; 
    }
    
}