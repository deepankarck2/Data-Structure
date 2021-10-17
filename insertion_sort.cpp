#include<iostream>
#include<vector>

using namespace std;
void InsertionSort(vector<int>& numbers, int numbersSize) {
   for (int i = 2; i < numbersSize; i++) {
      int j = i;
      while (j > 0 && numbers[j] < numbers[j - 1]) {
         // Swap numbers[j] and numbers [j - 1]
         int temp = numbers[j];
         numbers[j] = numbers[j - 1];
         numbers[j - 1] = temp;
         j--;
      }
   }
}

int main(){
    vector<int> list={32,12,44,1,3,7,8}; 
    
    InsertionSort(list, list.size()); 
    for (auto &&i : list)
    {
       cout << i << endl;
    }
    
    return 0; 
}
