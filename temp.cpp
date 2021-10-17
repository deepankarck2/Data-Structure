#include <iostream>
#include<string>
using namespace std;

#include "ItemToPurchase.h"

int main() {
   ItemToPurchase item1;
   ItemToPurchase item2; 
   
   string itemName; 
   int itemPrice, itemQuan, cost1, cost2;
   cout<<"Item 1\n"; 
   cout<<"Enter the item name:\n";
    cin >> itemName;
   item1.SetName(itemName); 
   cout<<"Enter the item price:\n";
   cin >> itemPrice;
   item1.SetPrice(itemPrice); 
   cout<<"Enter the item quantity:\n";
   cin >> itemQuan; 
   item1.SetQuantity(itemQuan); 
    cout<<endl; 
    
    cin.ignore(); 
    cout<<"Item 2\n"; 
    cout<<"Enter the item name:\n";
   cin >> itemName; 
   item2.SetName(itemName); 
   cout<<"Enter the item price:\n";
   cin >> itemPrice;
   item2.SetPrice(itemPrice); 
   cout<<"Enter the item quantity:\n";
   cin >> itemQuan; 
   item2.SetQuantity(itemQuan); 
    
    cout<<endl; 
    cout<<"TOTAL COST\n"; 
    cost1 = item1.GetPrice() * item1.GetQuantity();
    cost2 = item2.GetPrice() * item2.GetQuantity(); 

    int total_cost = cost1+cost2; 

    cout << item1.GetName() <<" " << item1.GetQuantity() << " " << "@ " << "$"<< item1.GetPrice() << "= " << cost1<<endl; 
    cout << item2.GetName() <<" " << item2.GetQuantity() << " "<< "@ "<< "$"<< item2.GetPrice() << "= " << cost2<<endl; 
    cout << endl; 
    cout<<"Total: $" << total_cost; 

   return 0;
}