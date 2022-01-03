#include <iostream>
#include <time.h>

using namespace std; 

int main()
{
	clock_t start, end;
	start = clock();

	size_t size = 100000;
	for(size_t i = 0; i < size; i++){

    }

	end = clock(); 
	cout << "time: " << end-start << " miliseconds" << endl;
	
	return 0;
}