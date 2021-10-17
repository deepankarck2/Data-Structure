/* #include<iostream>
#include<string>
using namespace std;

class Employee{
public:
    string Name; 
    string Company; 
    int age; 

//private:
    void intro(){
        cout <<"My name is " << Name << ". Age: " << age << endl; 
    }
};

int main(){
    Employee person1; 

    person1.Name = "Deep"; 
    person1.age = 24; 
    person1.Company = "Apple";
    person1.intro(); 

    return 0; 
}
 */

//Constructors: 
#include<iostream>
#include<string>
using namespace std;

class Employee{
private:
    string Name; 
    string Company; 
    int age; 
    
public: 
    Employee(string n, string c, int a){
        Name = n; 
        Company = c;
        age = a; 
    }
    void intro(){
        cout <<"My name is " << Name << ". Age: " << age << endl; 
    }
};

int main(){
    //Employee person1 = Employee("Deep", "Apple", 24); //One way
    Employee person1 ("Deep", "Apple", 24); //Another way

 /*    person1.Name = "Deep"; 
    person1.age = 24; 
    person1.Company = "Apple"; */
    person1.intro(); 

    return 0; 
}

