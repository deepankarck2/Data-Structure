//19.13 LAB: Acronyms
#include<iostream>
#include <string>
#include <cctype>

using namespace std;
 string CreateAcronym(string userPhrase){
    int j=0; 
    for (size_t i = 0; i < userPhrase.length(); i++){
        if(isupper(userPhrase[i])){
            userPhrase[j]= userPhrase[i]; //VERY USEFUL STRATEGY
            j++; 
        }
    }
    return userPhrase.substr(0, j); 
 }
int main () {
    string input; 
    getline(cin , input); 

    cout<< CreateAcronym(input)<< endl; 
    return 0; 
}


/* //Dynamicaaly allocate array. Using NEW
//int* array = new int[size];

#include <iostream>
using namespace std;

int
main ()
{
  int size;
  int arr[3]={1,2,3};
   
  std::cin >> size;
  int *array = new int[size];
 // cout << sizeof (array) / sizeof (int);
    array[0]= arr[0];
    array[1]= arr[1];
    array[2]= arr[2];
    array[3]= 5; 
    
   for (int i = 0; i < size; i++) {
       cout<< array[i]<<" "; 
   }
  delete[]array;

  return 0;
} */







//ranged based for loop 
/*
https://www.geeksforgeeks.org/range-based-loop-c/ 
for (range_declaration : range_expression) {  
 //loop body
} 
#include <iostream>
using namespace std;

int main()
{
    int a[]={1,2,3,4,1,6,1,34,6,78,84,2,132,5,67,87,5};
        
    for(int b: a){ //int b--> here int has to match the data type of array a; or use auto. 
        cout << b << " ";
    } 

    return 0;
}
*/ 


//-------------------------------------------------------------------------------------------
//Size of an array
/* 
int a[]={1,2,3,4,5,6,7,8,9};
unsigned int n = sizeof(arr)/sizeof(arr[0]); // 36/4 = 9
*/






//-------------------------------------------------------------------------------------------
//passing array by pointer reference: https://www.geeksforgeeks.org/how-arrays-are-passed-to-functions-in-cc/ 
/* #include <iostream>
using namespace std;

void arrayPrint(int* a){
    for(int i=0; i<5; i++){
        cout<<a[i]<<endl; 
    }
}
int main()
{
    int a[5]={1,2,3,4,5};
        
    arrayPrint(a); 

    return 0; //output=1 2 3 4 5
}




 */
//Array element move by one 
/* for (size_t i = array.length(); i > 0 ; i--) 
{
    array[length] = array[i-1]; 
}
 */





//-------------------------------------------------------------------------------------------
// if((userText[i] != ',')|| (userText[i]!= ' ') || (userText[i]!= '.') || (userText[i]!= '!')) //here multiple != doesn't work. 
//if((userText[i] == ',')|| (userText[i]== ' ') || (userText[i]== '.') || (userText[i]== '!')) this one does 

//or do this if((userText[i] =! ',') && (userText[i] != ' ') && ..... 
//-------------------------------------------------------------------------------------------
// for (size_t i = input.length()-1; i >= 0 ; i--) //doesn't work.. see lecture 9 by Wes
// for (size_t i = input.length()-1; i != -1; i--) 


//-------------------------------------------------------------------------------------------
// //short handed if/else statement
// #include<iostream>
// #include<string>
// using namespace std; 

// int main () 
// {
//     int a = 1000, b = 100; 
    
//     //variable = (condition) ? expressionTrue : expressionFalse;
//     string result = (a < b)? "a < b": "a > b";  
//     cout<<result<<endl; 

//     return 0; 
// }


//-------------------------------------------------------------------------------------------
// //Program: Text message expander
// //find and replace string
// #include <iostream>
// #include <string>
// using namespace std;

// int main()
// {
//    string BFF = "best friend forever";
//    string IDK = "I don't know";
//    string JK = "just kidding";
//    string TMI = "too much information";
//    string TTYL = "talk to you later";

//    string input;
//    cout << "Enter test:" << endl;
//    getline(cin, input);
   
//    cout <<"You entered: "<< input<<endl; 
//    size_t found_B = input.find("BFF"); 
//    if (found_B!=std::string::npos){
//       input.replace(found_B, 3, BFF); 
//    }

//    size_t found_I = input.find("IDK");
//    if(found_I!=std::string::npos){
//       input.replace(found_I, 3, IDK); 
//    } 

//    size_t found_J = input.find("JK");
//    if(found_J!=std::string::npos){
//       input.replace(found_J, 2, JK); 
//    }
   
//    size_t found_T = input.find("TMI");
//    if(found_T!=std::string::npos){
//       input.replace(found_T, 3, TMI); 
//    }

//    size_t found_TT = input.find("TTYL");
//    if(found_TT!=std::string::npos){
//       input.replace(found_TT, 4, TTYL); 
//    }

//    cout <<"Expanded: "<< input<<endl; 
//    return 0;
// }