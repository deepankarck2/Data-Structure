#include<iostream>
using namespace std;

void pascals(int n){
    int array[n][n]; 
    for(int i = 0; i< n ; i++){
        for (size_t j = 0; j <=i ; j++){
            if(j== 0 || j == i){
                array[i][j] = 1; 
            }
            else{
                array[i][j] = array[i-1][j-1] + array[i-1][j]; 
            }
        }
        
    }
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j <=i; j++)
        {
            cout << array[i][j]; 
        }
        cout << endl; 
    }
    

}
int main(){
    pascals(8); 
    return 0;
}