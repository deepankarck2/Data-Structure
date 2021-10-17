#include <iostream>
#include <vector>

using namespace std;

int binary_search(int *list, int key, int size)
{
    int low = 0, high = size - 1;
    int mid = (high + low) / 2;

    while (low <= high){
        if (list[mid] == key)
            return mid;
        else if (key < list[mid]){
            high = mid - 1;
            mid = (high + low) / 2;
        }
        else if (list[mid] < key ) {
            low = mid + 1;
            mid = (high + low) / 2;
        }
    }
    return -1;
}
int main()
{
    const int size = 11;
    int list[size] = {1, 5, 8, 19, 20, 24, 99,100,102,199,200};
    int key = 199;
    int index = binary_search(list, key, size); //passing array nad key to a finction

    if (index != -1) printf("Found at pos: %d", index + 1);
    else printf("Not Found"); 
}