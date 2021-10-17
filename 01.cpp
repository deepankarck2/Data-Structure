//-------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
#include <iostream>
#include <cstring>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

int main() {

   fstream myFile;
   string fileName;
   cin >> fileName;
   myFile.open(fileName);

   string input;
   vector<string> movies;
   while(!myFile.eof()) {
      getline(myFile, input);
      movies.push_back(input);
   }

  movies.pop_back();

   vector<string> times;
   vector<string> titles;
   for (int i=0 ; i<movies.size() ; i++) {
      string showTime = movies.at(i).substr(0,5);
      times.push_back(showTime);
      movies.at(i).erase(0,6);

      int pos = movies.at(i).find(",");
      string title = movies.at(i).substr(0,pos);
      titles.push_back(title);
      movies.at(i).erase(0,pos+1);
   }

     size_t i=0
       while(i<movies.size()){
      cout << setw(45) << left ;
      if (titles.at(i).size() > 45) {
         string newTitle = titles.at(i).substr(0,44);
         cout << newTitle;
      }
      else {
         cout << titles.at(i);
      }
      cout << "|";
      cout << setw(6) << right << movies.at(i) << " ";
      cout << "|";
      cout << " " << times.at(i) ;
      for (int j=i+1 ; j<movies.size() ; j++) {
         if (titles.at(i) == titles.at(j)) {
            cout << " " << times.at(j);
         }
      }
      for (int j=i+1 ; j<movies.size() ; j++) { 
         if (titles.at(i) == titles.at(j)) {
            i++;
         }
      }

      cout << endl;
      i++
   }

   return 0;
}
//-------------------------------------------------------------------------------------------

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;
string Grade(int); 

int main() {
   double averageOne = 0;
   double averageTwo = 0;
   double averageFinal = 0;
   int numStudents = 0, sumMidOne = 0, sumMidTwo = 0, sumFinal = 0;
   
   string fileName;
   fstream myFile;
   
   /* TODO: Read a file name from the user and read the tsv file here. */
   cin>>fileName;
   myFile.open(fileName);


   string line;
   vector <string> fullLines;
   while(getline(myFile, line)){ 
      fullLines.push_back(line);
      numStudents++;
   }

   for(int i = 0; i < fullLines.size(); i++){
      vector<string> studentBreakDown = {};
      istringstream iss(fullLines[i]);
      string word;
      while(iss >> word) { 
         studentBreakDown.push_back(word.c_str());
      }
      int mid1 = stoi(studentBreakDown[2]);
      int mid2 = stoi(studentBreakDown[3]);
      int final = stoi(studentBreakDown[4]);
      
      int studentAverage = (mid1 + mid2 + final) / 3;
      string letter = Grade(studentAverage);
      fullLines[i] += '\t';
      //fullLines[i] += ' ';
      fullLines[i] += letter;
      
      sumMidOne += mid1;
      sumMidTwo += mid2;
      sumFinal += final;
   }
   
   myFile.close();

   averageOne = (double)sumMidOne / (double)numStudents;
   averageTwo = (double)sumMidTwo / (double)numStudents;
   averageFinal = (double)sumFinal / (double)numStudents;
   
   ofstream myfile;
   myfile.open ("report.txt");
   for(int i = 0; i < fullLines.size(); i++){
      myfile<<fullLines[i]<<endl;
   }
   myfile << fixed << setprecision(2) << endl;
   myfile <<"Averages: midterm1 "<< averageOne<<", midterm2 "<< averageTwo<<", final "<<averageFinal<<endl;
   myfile.close();
   return 0;
}

string Grade(int average){
   string grade = "";
   
   if(average>=90){
      grade +="A";
   }else if(average >= 80 && average < 90){
      grade +="B";
   }else if(average >= 70 && average < 80){
      grade +="C";
   }else if(average >= 60 && average < 70){
      grade +="D";
   }else if(average<60){
      grade +="F";
   }
   
   return grade;
}


//-------------------------------------------------------------------------------------------
//22.5 
#include <iostream>
#include <cstring>
#include <fstream>
#include<vector>
using namespace std;

int main() {
  vector<string> category;
  vector<string> name;
  vector<string> description;
  vector<string> availability;

  string fileName, line;
  
  cin >> fileName;
  ifstream file(fileName);

  while (getline(file, line)) {
    size_t pos1 = line.find('\t');             
    size_t pos2 = line.find('\t', pos1 + 1);
    size_t pos3 = line.find('\t', pos2 + 1);
    
    category.push_back(line.substr(0, pos1));
    name.push_back(line.substr(pos1 + 1, pos2 - pos1 - 1));
    description.push_back(line.substr(pos2 + 1, pos3 - pos2 - 1));
    availability.push_back(line.substr(pos3 + 1, line.length() - pos3));
  }

  for (int i = 0; i < name.size(); i++)
    if (availability[i] == "Available")
      cout << name[i] << " (" << category[i] << ") -- " << description[i] << endl;
}
//-------------------------------------------------------------------------------------------
22.9 
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <ios>
#include <iomanip> 

using namespace std;

int main(){
    vector<string> Names;
    vector<int> Int_type_data;
    string title;

   string col1Name, col2Name, input;

   cout << "Enter a title for the data:" << endl;
   getline(cin, title);
   cout << "You entered: " << title << endl<< endl;

   cout << "Enter the column 1 header:" << endl;
   getline(cin, col1Name);
   cout << "You entered: " << col1Name << endl<< endl;

   cout << "Enter the column 2 header:" << endl;
   getline(cin, col2Name);
   cout << "You entered: " << col2Name << endl << endl;

   cout << "Enter a data point (-1 to stop input):" << endl;
   getline(cin, input);
   while(input!="-1"){
       int commaCount = 0;
       size_t i = 0;
       
       while (i < input.length()){
           if (input[i] == ','){
               commaCount++;
           }
           i++;
       }
       
       if (commaCount == 0){
           cout << "Error: No comma in string." << endl;
       }else if (commaCount > 1){
       cout << "Error: Too many commas in input." << endl;
       }else{
           string firstSection = input.substr(0, input.find(","));
           string secondSection = input.substr(input.find(",") + 1, input.length() - 1);
           
           firstSection.erase(0, firstSection.find_first_not_of(' '));
           secondSection.erase(0, secondSection.find_first_not_of(' '));
           
           int countNumbers = 0;
           for (size_t i = 0; i < secondSection.length(); i++){
               if (secondSection[i] >= '0' && secondSection[i] <= '9'){
                  countNumbers++;
               }
           }
           
           if (countNumbers == secondSection.length()){
               Int_type_data.push_back(atoi(secondSection.c_str()));
               Names.push_back(firstSection);
               cout << "Data string: " << firstSection << endl;
               cout << "Data integer: " << secondSection << endl;
           }else{
               cout << "Error: Comma not followed by an integer." << endl;
           }
           
       }
       cout << endl <<"Enter a data point (-1 to stop input):" << endl;
       getline(cin, input);
   }
   
   
   cout << endl;
   cout << setw(33) << title  << endl;
   cout << left << setw(20) << col1Name << "|" << right << setw(23) << col2Name << endl;
   cout << "--------------------------------------------" << endl;
   
   
   size_t j = 0;
   while (j < Names.size()){
       cout << left << setw(20) << Names[j] << "|" << setw(23) <<right<< Int_type_data[j] << endl;
       j++;
   }
   cout << endl;


   for (size_t i = 0; i < Names.size(); i++){
       cout << setw(20)<<Names[i] << " ";
       for (int j = 0; j < Int_type_data[i]; j++){
           cout << "*";
       }
       cout << endl;
   }
   return 0;
}






//-------------------------------------------------------------------------------------------
//Movie show time display
#include <iostream>
#include <cstring>
#include <iomanip>
#include <fstream>
using namespace std;

int main()
{

    FILE *file; // file pointer

    // other required variables
    char fileName[50], buf[1000], prevTitle[200], showTime[10], title[200], rating[10], temp[200];
    int i, j, k, x;

    // accept a filename from user
    cin >> fileName;

    file = fopen(fileName, "r"); // open the file in read mode

    // if input file couldn't be opened then
    if (file == NULL)
    {
        printf("Error in opening the file!");
        exit(0);
    }

    strcpy(prevTitle, "");
    i = 0;
    // read each line from the file
    while (fgets(buf, 1000, file))
    {
        // make required string variables empty
        title[0] = '\0';
        rating[0] = '\0';
        showTime[0] = '\0';

        k = 0;
        // until end of current line is reached
        for (j = 0; buf[j] != '\0'; j++)
        {
            x = 0;
            temp[0] = '\0'; // set temp as empty

            // split current line using comma as delimeter
            while (buf[j] != ',' && j < strlen(buf) - 1)
            {
                temp[x] = buf[j];
                x++;
                j++;
            }
            temp[x] = '\0';

            // for first substring of the line, store it in variable 'showTime'
            if (k == 0)
                strcpy(showTime, temp);
            // for second substring of the line, store it in variable 'title'
            else if (k == 1)
            {
                memset(title, '\0', sizeof(title));
                if (strlen(temp) > 44) // if title is > 44, then copy only first 44 characters
                    strncpy(title, temp, 44);
                else
                    strcpy(title, temp);
            }
            // for third substring of the line, store it in variable 'rating'
            else
            {
                strcpy(rating, temp);
                k = -1;
            }
            k++;
        }

        // print the results
        if (strcmp(prevTitle, title) == 0)
            printf("%s ", showTime);
        else
            printf("%-44s | %7s | %s \n", title, rating, showTime);

        strcpy(prevTitle, title);
    }

    fclose(file); // close the file
    return 0;
}

//-------------------------------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int main()
{
    string str;
    char fileName[50], tempFile[] = "temp.txt";
    // Getting user file name
    cin >> fileName;
    // Opening user file for reading
    ifstream file(fileName);
    // Opening temp file for writing
    ofstream file1(tempFile);

    if (file.fail())
    {
        cerr << "ERROR";
        exit(1);
    }
    // Reading line by line from user's file
    while (getline(file, str))
    {
        // split the name by "_"
        // get only the prefix of name
        string name = str.substr(0, str.find("_"));
        // concat the suffix with name's prefix
        name = name + "_info.txt";
        // write the resultant name into temp file
        file1 << name << endl;
        // Print the modified name
        cout << name << endl;
    }

    remove(fileName);

    rename(tempFile, fileName);
    file1.close();
    return 0;
}
//-------------------------------------------------------------------------------------------
#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
using namespace std;

int main()
{
    ifstream file;
    ifstream output;
    output.open("report.txt");
    file.open("StudentInfo.tsv");

    double average;
    string firstname, lastname;
    char letter;
    int mid1, mid2, final;
    /* TODO: Declare any necessary variables here. */

    if (!file.is_open())
    {
        exit(EXIT_FAILURE);
    }

    /* TODO: Read a file name from the user and read the tsv file here. */
    while (file.good())
    {
        getline(file, firstname, '\t');
        getline(file, lastname, '\t');
        getline(file, mid1, '\t');
        getline(file, mid2, '\t');
        getline(file, final, '\n');

        average = (mid1 + mid2 + final) / 3;

        output << firstname << "\t" << lastname << "\t" << mid1 << "\t" << mid2 << "\t" << final << "\t" << average << "\n";
    }

    /* TODO: Compute student grades and exam averages, then output results to a text file here. */
    file.close();
    output.close();
    return 0;
}

//-------------------------------------------------------------------------------------------

if (firstSpace == 0 || firstComma == 0 || firstComma < firstSpace)
    continue;
string month = input.substr(0, firstSpace);
string day = input.substr(firstSpace + 1, firstComma - firstSpace - 1);
string year = input.substr(firstComma + 2);

bool flag = true;
for (int i = 0; i < day.length(); i++)
    if (day[i] < '0' || day[i] > '9') // flag becomes false when non-digit character found
        flag = false;
if (flag == false) // go to next date when day contains non-digit character
    continue;
// check whether year contains non-digit character
flag = true;
for (int i = 0; i < year.length(); i++)
    if (year[i] < '0' || year[i] > '9') // flag becomes false when non-digit character found
        flag = false;
if (flag == false) // go to next date when year contains non-digit character
    continue;
int m = DateParser(month);               // getting integer equivalent of month
int d = stoi(day);                       // getting integer form of day
int y = stoi(year);                      // getting integer form of year
if (m == 0 || d <= 0 || d > 31 || y < 0) // go to next date if month, day or year is not valid
    continue;
cout << m << "/" << d << "/" << y << "\n"; // print in required form
}
}

//-------------------------------------------------------------------------------------------

// Header files section
#include "Playlist.h"

// function prototype
void PrintMenu(string title);

// start main function
void PrintMenu(string title)
{
    cout << endl
         << title << " PLAYLIST MENU" << endl;
    cout << "a - Add song" << endl;
    cout << "d - Remove song" << endl;
    cout << "c - Change position of song" << endl;
    cout << "s - Output songs by specific artist" << endl;
    cout << "t - Output total time of playlist (in seconds)" << endl;
    cout << "o - Output full playlist" << endl;
    cout << "q - Quit" << endl
         << endl;
}

int main()
{
    Playlist list;
    string id;
    string sname;
    string aname;
    int length;
    int oldPos;
    int newPos;
    char choice;
    string plTitle;

    cout << "Enter playlist's title: ";
    getline(cin, plTitle);

    do
    {
        PrintMenu(plTitle);
        cout << "Choose an option: ";
        cin >> choice;
        cin.ignore(); //flush newline
        if (choice == 'q' || choice == 'Q')
        {
            exit(1);
        }
        else if (choice == 'a' || choice == 'A')
        {
            cout << "\nADD SONG" << endl;
            cout << "Enter song's unique ID: ";
            cin >> id;
            cin.ignore(); //ignore newline
            cout << "Enter song's name: ";
            getline(cin, sname);
            cout << "Enter artist's name: ";
            getline(cin, aname);
            cout << "Enter song's length (in seconds): ";
            cin >> length;
            list.AddSong(id, sname, aname, length);
        }
        else if (choice == 'd' || choice == 'D')
        {
            cout << "\nREMOVE SONG" << endl;
            cout << "Enter song's unique ID: ";
            cin >> id;
            list.RemoveSong(id);
        }
        else if (choice == 'c' || choice == 'C')
        {
            cout << "\nCHANGE POSITION OF SONG" << endl;
            cout << "Enter song's current position: ";
            cin >> oldPos;
            cout << "Enter new position for song: ";
            cin >> newPos;
            list.ChangePosition(oldPos, newPos);
        }
        else if (choice == 's' || choice == 'S')
        {
            cout << "\nOUTPUT SONGS BY SPECIFIC ARTIST" << endl;
            cout << "Enter artist's name: ";
            getline(cin, aname);
            list.SongsByArtist(aname);
        }
        else if (choice == 't' || choice == 'T')
        {
            cout << "\nOUTPUT TOTAL TIME OF PLAYLIST (IN SECONDS)" << endl;
            cout << "Total time: " << list.TotalTime() << " seconds" << endl;
        }
        else if (choice == 'o' || choice == 'O')
        {
            cout << endl
                 << title << " - OUTPUT FULL PLAYLIST" << endl;
            list.PrintList();
        }
        else
        {
            cout << "Invalid menu choice! Please try again." << endl;
        }
    } while (choice != 'q');
    return 0;
}

// PrintMenu function implementation
// PrintMenu() takes the playlist title as a parameter and outputs a menu
// of options to manipulate the playlist. Each option is represented by a
// single character. Build and output the menu within the function.

//-------------------------------------------------------------------------------------------
#include "MileageTrackerNode.h"
#include <string>
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    // References for MileageTrackerNode objects
    MileageTrackerNode *headNode;
    MileageTrackerNode *currNode;
    MileageTrackerNode *lastNode;

    double miles;
    string date;
    int i;

    // Front of nodes list
    headNode = new MileageTrackerNode();
    lastNode = headNode;

    // TODO: Read in the number of nodes
    cin >> i;
    // TODO: For the read in number of nodes, read
    //       in data and insert into the linked list
    for (int j = 0; j < i; j++)
    {
        cin >> miles >> date;
        currNode = new MileageTrackerNode(miles, date);
        lastNode->InsertAfter(currNode);
        lastNode = currNode;
    }
    currNode = headNode->next;
    // TODO: Call the PrintNodeData() method
    //       to print the entire linked list
    for (int j = 0; j < i; j++)
    {
        currNode = PrintNodeData();
        currNode = currNode->GetNext();
    }
    // MileageTrackerNode Destructor deletes all
    //       following nodes
    delete headNode;
}

//-------------------------------------------------------------------------------------------

#include "LinkedListLibrary.h"
#include "VectorLibrary.h"
#include "BookNode.h"
#include "Book.h"
#include <fstream>
#include <iostream>
using namespace std;

void FillLibraries(LinkedListLibrary &linkedListLibrary, VectorLibrary &vectorLibrary)
{
    ifstream inputFS; // File input stream
    int linkedListOperations = 0;
    int vectorOperations = 0;

    BookNode *currNode;
    Book tempBook;

    string bookTitle;
    string bookAuthor;
    long bookISBN;

    // Try to open file
    inputFS.open("books.txt");

    while (getline(inputFS, bookTitle))
    {
        inputFS >> bookISBN;
        inputFS.ignore(1, '\n');
        getline(inputFS, bookAuthor);

        // Insert into linked list
        currNode = new BookNode(bookTitle, bookAuthor, bookISBN);
        linkedListOperations = linkedListLibrary.InsertSorted(currNode, linkedListOperations);
        linkedListLibrary.lastNode = currNode;

        // Insert into vector
        tempBook = Book(bookTitle, bookAuthor, bookISBN);
        vectorOperations = vectorLibrary.InsertSorted(tempBook, vectorOperations);
    }

    inputFS.close(); // close() may throw ios_base::failure if fails
}

int main(int argc, const char *argv[])
{
    int linkedListOperations = 0;
    int vectorOperations = 0;

    // Create libraries
    LinkedListLibrary linkedListLibrary = LinkedListLibrary();
    VectorLibrary vectorLibrary;

    // Fill libraries with 100 books
    FillLibraries(linkedListLibrary, vectorLibrary);

    // Create new book to insert into libraries
    BookNode *currNode;
    Book tempBook;

    string bookTitle;
    string bookAuthor;
    long bookISBN;
    int counter1 = 0, counter2 = 0;

    getline(cin, bookTitle);
    cin >> bookISBN;
    cin.ignore();
    getline(cin, bookAuthor);

    // Insert into linked list
    // No need to delete currNode, deleted by LinkedListLibrary destructor
    currNode = new BookNode(bookTitle, bookAuthor, bookISBN);
    // TODO: Call LL_Library's InsertSorted() method to insert currNode and return
    //       the number of operations performed
    int counter1 = LinkedListLibrary.InsertSorted(currNode, 0)
                       linkedListLibrary.lastNode = currNode;

    // Insert into VectorList
    tempBook = Book(bookTitle, bookAuthor, bookISBN);
    // TODO: Call VectorLibrary's InsertSorted() method to insert tempBook and return
    //       the number of operations performed
    int counter2 = VectorLibrary.InsertSorted(tempBook, 0);
    // TODO: Print number of operations for linked list
    cout << "Number of linked list operations: " << counter1 << endl;
    // TODO: Print number of operations for vector
    cout << "Number of linked list operations: " << counter2 << endl;
}

//-------------------------------------------------------------------------------------------
ShoppingCart.h :
#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H

#include <iostream>
#include <string>
#include <vector>
    using namespace std;
#include "ItemToPurchase.h"

class ShoppingCart
{
private:
    string customerName;
    string currentDate;
    vector<ItemToPurchase> cartItems;

public:
    void GetCustomerName();
    void GetDate();
    void AddItem(ItemToPurchase);
    void RemoveItem(string itemNames);
    void ModifyItem(ItemToPurchase);
    int GetNumItemsInCart();
    int GetCostOfCart();
    void PrintTotal();
    void PrintDescriptions();
};
#endif

ItemToPurchase.h :
#ifndef ITEM_TO_PURCHASE_H
#define ITEM_TO_PURCHASE_H

#include <string>
    using namespace std;

class ItemToPurchase
{
public:
    //  ItemToPurchase(string itemName, int itemPrice, int itemQuantity){
    //  itemName = "none";
    //  itemPrice = 0;
    //  itemQuantity=0;
    //  }
    void SetName(string itemName1);
    string GetName();
    void SetPrice(int itemPrice1);
    int GetPrice();
    void SetQuantity(int itemQuantity1);
    int GetQuantity();
    void SetDescription(itemDescription1);
    string GetDescription();
    void PrintItemCost();
    void PrintItemDescription();

private:
    string itemName;
    int itemPrice;
    int itemQuantity;
    string itemDescription;
};

#endif

#include <iostream>
#include <iomanip>
using namespace std;

#include "ShoppingCart.h"

void PrintMenu()
{
    printf("MENU\n");
    printf("a - Add item to cart\n");
    printf("r - Remove item from cart\n");
    printf("c - Change item quantity\n");
    printf("i - Output items' descriptions\n");
    printf("o - Output shopping cart\n");
    printf("q - Quit\n\n");
}

void ExecuteMenu(char option, ShoppingCart &theCart)
{
    /* Type your code here */
}

int main()
{
    /* Type your code here */

    return 0;
}

//-------------------------------------------------------------------------------------------
/* #include <iostream>
using namespace std;

#include "ItemToPurchase.h"

void ItemToPurchase::SetName(string itemName1)
{
    itemName = itemName1;
}
string ItemToPurchase::GetName()
{
    return itemName;
}
void ItemToPurchase::SetPrice(int itemPrice1)
{
    itemPrice = itemPrice1;
}
int ItemToPurchase::GetPrice()
{
    return itemPrice;
}

void ItemToPurchase::SetQuantity(int itemQuantity1)
{
    itemQuantity = itemQuantity1;
}
int ItemToPurchase::GetQuantity()
{
    return itemQuantity;
}

#include <iostream>
using namespace std;

#include "ItemToPurchase.h"

int main()
{
    ItemToPurchase item1;
    ItemToPurchase item2;
    string itemName;
    int itemPrice, itemQuan, cost1, cost2;
    cout << "Item 1\n";
    cout << "Enter item name:\n";
    cin >> itemName;
    item1.SetName(itemName);
    cout << "Enter item price:\n";
    cin >> itemPrice;
    item1.SetPrice(itemPrice);
    cout << "Enter item quantity:\n";
    cin >> itemQuan;
    item1.SetQuantity(itemQuan);

    cin.ignore();
    cout << "Item 2\n";
    cout << "Enter item name:\n";
    cin >> itemName;
    item2.SetName(itemName);
    cout << "Enter item price:\n";
    cin >> itemPrice;
    item2.SetPrice(itemPrice);
    cout << "Enter item quantity:\n";
    cin >> itemQuan;
    item2.SetQuantity(itemQuan);

    cout << endl;
    cout << "TOTAL COST";
    cost1 = item1.GetPrice() * item1.GetQuantity();
    cost2 = item2.GetPrice() * item2.GetQuantity();

    int total_cost = cost1 + cost2;

    cout << item1.GetName() << " " << item1.GetQuantity() << " "
         << "$" << item1.GetPrice() << "=" << cost1 << endl;
    cout << item2.GetName() << " " << item2.GetQuantity() << " "
         << "$" << item2.GetPrice() << "=" << cost2 << endl;
    cout << endl;
    cout << "Total: $" << total_cost;

    return 0;
}

class ItemToPurchase
{
public:
    ItemToPurchase(string itemName, int itemPrice, int itemQuantity);
    void SetName();
    string GetName();
    void SetPrice();
    int GetPrice();
    void SetQuantity();
    int GetQuantity()

        private : string itemName;
    int itemPrice;
    int itemQuantity;
}; */

/* #include <iostream>
#include "Course.h"
using namespace std;

Student Course::FindStudentHighestGpa()
{
    int max = 0;
    for (size_t i = 0; i < roster.size(); i++){
   if(roster[i].GetGPA() > roster[max].GetGPA(){
            max = i; 
        }
    }
    return roster[max];
}

void Course::AddStudent(Student s)
{
    roster.push_back(s);
}
 */
//-------------------------------------------------------------------------------------------
/* //20.11 LAB: Count probations
#include <iostream>
#include "Course.h"
using namespace std;

int Course::CountProbation() {
	int count = 0; 
    for (size_t i = 0; i < roster.size(); i++)
    {
        if(roster.GetGPA() < 2.0){
            count++; 
        } 
    }
	return count; 
}

void Course::AddStudent(Student s) {
	roster.push_back(s);
}

 */

//-------------------------------------------------------------------------------------------

/* //BAnkAccount.h
#ifndef BANKACCOUNTH
#define BANKACCOUNTH

#include <string>
using namespace std;

class BankAccount {
   public:
      // TODO: Declare public member functions
      BankAccount(string newName, double amt1, double amt2){
          cus_name = newName;
          che_bal = amt1;
          sav_bal = amt2;
      }
   void SetName(string newName);
   string GetName();
   void SetChecking(double amt);
   double GetChecking();
   void SetSavings(double amt); 
   double GetSavings(); 
   void DepositChecking(double amt);
   void DepositSavings(double amt);
   void WithdrawChecking(double amt); 
   void WithdrawSavings(double amt); 
   void TransferToSavings(double amt); 

   private:
      // TODO: Declare private data members
    string cus_name;
    double sav_bal; 
    double che_bal; 

};

#endif

 */

//Trianlge Area
/* #include <iostream>
#include "Triangle.h"
using namespace std;

int main() {
   Triangle triangle1;
   Triangle triangle2;
    double base1, height1, base2, height2;
    cin >> base1 >> height1 >> endl; 
   // TODO: Read and set base and height for triangle1 (use SetBase() and SetHeight())
    triangle1.SetBase(base1); 
    triangle1.SetHeight(height1); 
   // TODO: Read and set base and height for triangle2 (use SetBase() and SetHeight())
   cin >> base2 >> height2 endl; 
   triangle2.SetBase(base2);
   triangle2.SetHeight(height2); 
   // TODO: Determine larger triangle (use GetArea())
   double area1 = triangle1.GetArea();
    double area2 = triangle2.GetArea()
   if(area1 > area2){
       cout << "Triangle with larger area:" << triangle1.PrintInfo() <<endl;
   }      
   
    else  cout << "Triangle with larger area:" << triangle2.PrintInfo() <<endl;
    
   // TODO: Output larger triangle's info (use PrintInfo())
   
   return 0;
}
 */

/* //19.33 LAB*: Program: Authoring assistant
#include <iostream>
#include <string>
using namespace std;

int GetNumOfNonWSCharacters(string);
void ExecuteMenu(char, string);
void PrintMenu();
int GetNumOfWords(string);
int FindText(string, string);
void ReplaceExclamation(string&);   
void ShortenSpace(string&); 

void PrintMenu(){
     cout << "MENU" << endl;
 cout << "c - Number of non-whitespace characters" << endl;
 cout << "w - Number of words" << endl;
 cout << "f - Find text" << endl;
 cout << "r - Replace all !'s" << endl;
 cout << "s - Shorten spaces" << endl;
 cout << "q - Quit" << endl << endl;
}
void ExecuteMenu(char choice, string input){
    if(choice == 'c') cout<<"Number of non-whitespace characters: "<< GetNumOfNonWSCharacters(input)<<endl; 
    else if(choice == 'w'){
      cout << "Number of words: " << GetNumOfWords(input) << endl << endl;

    }
    else if(choice == 'f') {
        cin.ignore();
        string find; 
        cout<<"Enter a word or phrase to be found:\n"; 
        getline(cin,find); 
        printf("\"%s\" instances: %d\n",find.c_str(), FindText(find, input));
    }  
    else if(choice == 'r'){
        //string temp;
        ReplaceExclamation(input); 
        cout<<"Edited text: " << input<<endl; 
    }
    else if(choice == 's'){
        //string temp; 
        ShortenSpace(input); 
        cout<<"Edited text: " << input<<endl; 
    }
    else if(choice == 'q'){
        return; 
    }
}

int GetNumOfNonWSCharacters(const string usrStr){
   int totalNonWhiteSpaceChars = 0;
   int len = usrStr.length();
    for(int i= len-1; i>=0; i--){
  if(usrStr[i] != ' ' )
    totalNonWhiteSpaceChars++;
}
      
return totalNonWhiteSpaceChars;
}
int GetNumOfWords(const string usrStr){
   int totalWords = 0;
   int len = usrStr.length();
    for(int i= len-1; i>=0; i--){


  if(usrStr[i] == ' ' && i != len-1 && usrStr[i-1]!=' ')
    totalWords++;
    
}
      
return totalWords+1;
}

int FindText( string Text, string input){
  int count = 0;

  size_t nPos = input.find(Text, 0); 
  while(nPos != string::npos)
  {
      count++;
      nPos = input.find(Text, nPos+1);
  }
return count;
}

void ReplaceExclamation(string& input){
   string edited="";
   for(size_t i=0;i<input.length();i++){
      if(input[i]=='!') edited+=".";
      else edited +=string(1, input[i]);
   }
   input=edited;
}
void ShortenSpace(string& input) //function to remove extra spaces.
{
    string edited = "";
    for (int i = 0; input[i] != '\0'; i++)
    {
        if (input[i] != ' ') // if present character is not a space then storing in new string.
            edited += input[i];
        else if (i != 0 && input[i - 1] != ' ' && input[i] == ' ') //if present character is space and previous character is alphabet then store one space.
            edited += input[i];
    }
    input = edited; 
}

int main() {
    string input;
    char choice;  
    cout <<"Enter a sample text:\n";
    getline(cin, input); 
    cout<< endl; 

    cout<<"You entered: "<< input<<endl; 
    cout<<endl; 

     do
    {
        PrintMenu();
        cout<<"Choose an option:\n";
        cin >> choice; 
        if(choice !='q'){
        ExecuteMenu(choice,input);
         if(choice != 'w'){
            cout<<endl;
         }
        } 
    } while (choice != 'q'); 
   return 0;
}
 */
//-------------------------------------------------------------------------------------------
/* //Str length
#include <iostream>
#include <string>
using namespace std;

//Returns the number of characters in usrStr
int GetNumOfCharacters(const string usrStr) {
    int count=0; 
    for (int i = 0; i < usrStr.length(); i++)
    {
        count++; 
    }
      return count; 
}

void OutputWithoutWhitespace(string usrStr){
    size_t n = usrStr.length();

    for (size_t i = 0; i < n; i++)
    {
        if(usrStr[i]== ' ' || usrStr[i]== '\t'){
            usrStr.erase(usrStr.begin()+i); 
        }
    }
    cout<<"String with no whitespace: "<< usrStr<<endl;  
}

int main() {
    string input; 
   cout<<"Enter a sentence or phrase:\n"; 
   getline(cin,input);

    cout<<endl; 
    cout<<"You entered: "<< input<<endl; 
    cout<<endl; 

    cout<<"Number of characters: " << GetNumOfCharacters(input)<< endl;  
    OutputWithoutWhitespace(input); 
   return 0;
}
 */
/* //19.31 LAB: Write Convert() function to cast double to int
#include <iostream>
using namespace std;

int Convert(double input){
    int a = input; 
    return a; 
} 


int main() {
	cout << Convert(19.9) << endl;
	cout << Convert(3.1) << endl;

	return 0;
} */

/* //19.30 LAB: Fun with characters
#include <iostream>
#include<cctype>
using namespace std;

string CheckCharacter(string word, int index) {
    string result,temp;
    result += word[index];
    temp+= to_string(index); 
	if(isalpha(word[index])) return "Test CheckCharacter(\""+word+"\","+temp+")"+".equals" +"(\"Character '" + result + "' is a letter\")" ; 
    else if(isspace(word[index])) return "\"Character '"+ result +"' is a whitespace\""; 
    else if(isdigit(word[index])) return "\"Character '"+ result +"' is a digit\""; 
    else return "\"Character '" + result + "' is unknown\"";; 
}

int main() {
	cout << CheckCharacter("happy birthday", 2) << endl;
	cout << CheckCharacter("happy birthday", 5) << endl;
	cout << CheckCharacter("happy birthday 2 you", 15) << endl;
	cout << CheckCharacter("happy birthday!", 14) << endl;

	return 0;
}
 */

//-------------------------------------------------------------------------------------------
/* //19.29 LAB: Remove all even numbers from a vector
#include <iostream>
#include <vector>
using namespace std;

vector<int> RemoveEvens(vector<int> nums) {
    vector<int> answer; 
	for (int i = 0; i < nums.size(); i++)
    {
        if(nums[i] %2 != 0){
            answer.push_back(nums[i]); 
        }
    }
    return answer; 
}

int main() {

	vector<int> input(9);
	input.at(0) = 1;
	input.at(1) = 2;
	input.at(2) = 3;
	input.at(3) = 4;
	input.at(4) = 5;
	input.at(5) = 6;
	input.at(6) = 7;
	input.at(7) = 8;
	input.at(8) = 9;

	vector<int> result = RemoveEvens(input); // Should return [1, 3, 5, 7, 9]

    cout<<"["; 
	for (size_t i = 0; i < result.size()-1; ++i) {
		cout << result.at(i)<<", ";
	}
    cout<< result.at(result.size()-1); 
	cout <<"]"<< endl;


	return 0;
} */

//-------------------------------------------------------------------------------------------
/* //19.19 LAB: Output values below an amount - functions
#include <iostream>
#include <vector> 
using namespace std;

vector<int> GetUserValues(vector<int>& userValues, int numValues){
    int n; 
    for (int i = 0; i < numValues; i++){
        cin >> n;
        userValues.push_back(n); 
    }
    return userValues; 
}
 void OutputIntsLessThanOrEqualToThreshold(vector<int> userValues, int upperThreshold){
    for (size_t i = 0; i < userValues.size(); i++)
    {
        if(userValues[i] <= upperThreshold){
            cout<<userValues[i]<<" "; 
        }
    }
    cout<< endl; 
} 

int main() {
   vector<int> userValues; 
   int upperThreshold;
   int numValues;
   
   cin >> numValues;
   userValues = GetUserValues(userValues, numValues);
    
    cin >> upperThreshold;
   OutputIntsLessThanOrEqualToThreshold(userValues, upperThreshold);
   
   return 0;
} */

//-------------------------------------------------------------------------------------------
/* //19.16 LAB: Even/odd values in a vector
#include <iostream>
#include <vector>
using namespace std;

bool IsVectorEven(vector<int> myVec){
    for (size_t i = 0; i < myVec.size(); i++)
    {
        if(myVec[i] %2 !=0){
            return false; 
        } 
    }
    return true; 
}
bool IsVectorOdd(vector<int> myVec){
     for (size_t i = 0; i < myVec.size(); i++)
    {
        if(myVec[i] %2 == 0){
            return false; 
        }
    }
    return true; 
}

int main()
{
    vector<int> input;
    int n,m;
    cin >> n; 
    for (size_t i = 0; i < n; i++)
    {
        cin >>m; 
        input.push_back(m);  
    }
    bool a,b,c; 
    if(IsVectorEven(input)) printf("all even\n"); 
    else if(IsVectorOdd(input)) printf("all odd\n"); 
    else printf("not even or odd\n");
    return 0;
} */

//-------------------------------------------------------------------------------------------
/* //19.13 LAB: Acronyms
#include<iostream>
#include <string>
#include <cctype>

using namespace std;
 string CreateAcronym(string userPhrase){
    int j=0; 
    for (size_t i = 0; i < userPhrase.length(); i++){
        if(isupper(userPhrase[i])){
            userPhrase[j]= userPhrase[i]; 
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
} */
//-------------------------------------------------------------------------------------------
/* //19.10 LAB: Remove all non-alphabetic characters
#include <iostream>
#include<string>
#include<locale>
using namespace std;
string RemoveNonAlpha(string userString){

    for(int i=0; i < userString.size(); i++){
        if (userString[i] < 'A' || userString[i] > 'Z' &&
            userString[i] < 'a' || userString[i] > 'z'){
            userString.erase(i,1);
            i--;  
        }
    }
    return userString; 
}

int main() {
    string userString, answer;

    getline(cin,userString); 
    answer = RemoveNonAlpha(userString); 

    cout<< answer<<endl; 
    
   return 0;
} */

//-------------------------------------------------------------------------------------------
/*//Magnitude  
#include <iostream>
#include<cmath>
using namespace std;

int MaxMagnitude(int userVal1, int userVal2){
    
    if(abs(userVal1)< abs(userVal2)) return userVal2; 
    else if(abs(userVal1) > abs(userVal2) ) return userVal1; 
    else return -1; 
}
int main() {
    int a,b;

    cin >> a >> b;
    cout << MaxMagnitude(a,b)<<endl; 

   return 0;
}
 */

//-------------------------------------------------------------------------------------------
/* //19.4 LAB: A jiffy
#include <iostream>
#include <iomanip>
using namespace std;

double SecondsToJiffies(double userSeconds){
    
    return userSeconds*100;  
}

int main() {
   
    double userSeconds; 
    cin >> userSeconds; 

    cout << fixed << setprecision(2);
    cout << SecondsToJiffies(userSeconds)<<endl; 
   return 0;
}


 */

//-------------------------------------------------------------------------------------------
/* //uri 1149
#include<iostream>
using namespace std; 
int main (){
    int A,N, sum=0; 
    cin >> A >> N; 
    while(N <=0 ){
        cin >> N; 
    }
    for (int i = 0; i < N; i++)
    {
        sum = sum + A; 
        A++; 
    }
    cout<<sum<<endl; 
}
 */
//-------------------------------------------------------------------------------------------

/* //uri 1175
#include <iostream>
using namespace std;
int main()
{
    int array[20];
    int input;
    for (size_t i = 0; i < 20; i++){
        cin >> input;
        array[i] = input;
    }
    for (int i = 0; i < 10; i++)
    {
        int temp; 
        temp = array[i];
        array[i]= array[19-i];
        array[19-i]= temp;  
    }
    for(int i=0; i<20; i++){
    printf("N[%d] = %d\n", i, array[i]); 
    }
} */

/*//uri 1177
 #include<iostream>
using namespace std;
int main() {

    int array[1000];
    int number;
    cin >> number; 
     int j=0;
    for(int i=0; i< 1000; i++){ 
        printf("N[%d] = %d\n",i, j);
        j++;
          if(j==number){
            j=0; 
        }   
    }
} */

/* //18.11 LAB*: Program: Soccer team roster (Vectors)
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int jersy_num, rating_num;
    vector<int> jersy;
    vector<int> rating;
    for (int i = 1; i <= 5; i++)
    {
        printf("Enter player %d's jersey number:\n", i);
        cin >> jersy_num;
        jersy.push_back(jersy_num);

        printf("Enter player %d's rating:\n", i);
        cin >> rating_num;
        rating.push_back(rating_num);
        cout << endl;
    }
    cout << "ROSTER" << endl;
    for (int i = 0; i < 5; i++)
    {
        printf("Player %d -- Jersey number: %d, Rating: %d\n", i + 1, jersy[i], rating[i]);
    }
    cout << endl;
    printf("MENU\na - Add player\nd - Remove player\nu - Update player rating\nr - Output players above a rating\no - Output roster\nq - Quit\n\nChoose an option:\n");

    char option;
    while (cin >> option)
    {
        if (option == 'q')
        {
            break;
        }
        else if (option == 'a')
        {
            int new_num1, new_num2;
            printf("Enter a new player's jersey number:\n");
            cin >> new_num1;
            jersy.push_back(new_num1);

            printf("Enter the player's rating:\n");
            cin >> new_num2;
            rating.push_back(new_num2);
            cout << endl; 
            printf("MENU\na - Add player\nd - Remove player\nu - Update player rating\nr - Output players above a rating\no - Output roster\nq - Quit\n\nChoose an option:\n");
        }
        else if (option == 'o')
        {
            cout << "ROSTER" << endl;
            for (size_t i = 0; i < jersy.size(); i++)
            {
                printf("Player %d -- Jersey number: %d, Rating: %d\n", i + 1, jersy[i], rating[i]);
            }
            cout << endl;
            printf("MENU\na - Add player\nd - Remove player\nu - Update player rating\nr - Output players above a rating\no - Output roster\nq - Quit\n\nChoose an option:\n");
        }
        else if (option == 'd')
        {
            int new_num;
            cin >> new_num;
            for (int i = 0; i < jersy.size(); i++)
            {
                if (jersy[i] == new_num)
                {
                    jersy.erase(jersy.begin() + i);
                    rating.erase(rating.begin() + i);
                }
            }
            cout << endl;
            printf("MENU\na - Add player\nd - Remove player\nu - Update player rating\nr - Output players above a rating\no - Output roster\nq - Quit\n\nChoose an option:\n");
        }
        else if (option == 'r')
        {
            cout << "Enter a rating:\n";
            int new_num;
            cin >> new_num;
            cout << "ABOVE " << new_num<<endl;
            for (size_t i = 0; i < jersy.size(); i++)
            {
                if (rating[i] > new_num)
                {
                    printf("Player %d -- Jersey number: %d, Rating: %d\n", i + 1, jersy[i], rating[i]);
                }
            }
            cout << endl;
            printf("MENU\na - Add player\nd - Remove player\nu - Update player rating\nr - Output players above a rating\no - Output roster\nq - Quit\n\nChoose an option:\n");
        }

        else if (option == 'u')
        {
            int new_num, new_num2;
            cout << "Enter a jersey number:\n";
            cin >> new_num;
            cout << "Enter a new rating for player:\n";
            cin >> new_num2;
            for (size_t i = 0; i < jersy.size(); i++)
            {
                if (new_num == jersy[i])
                {
                    rating[i] = new_num2;
                }
            }
            cout << endl;
            printf("MENU\na - Add player\nd - Remove player\nu - Update player rating\nr - Output players above a rating\no - Output roster\nq - Quit\n\nChoose an option:\n");
        }
    }
    return 0;
}
 */
/* #include <iostream>
#include <iomanip>              // For setprecision
#include<vector> 
using namespace std;

int main() {
    float input, total_wei=0;
    vector<float> list;
    int max=0; 
    for (int i = 1; i <= 5; i++)
    {
        printf("Enter weight %d: ", i);
        cin >> input;
        list.push_back(input); 
    }
    
    cout<<"You entered: "; 
    for (size_t i = 0; i < list.size(); i++)
    {
        cout << fixed << setprecision(2);
        cout<< list[i]<< " "; 
        if(list[max] < list[i]){
            max = i; 
        }
        total_wei = total_wei + list[i]; 
    }
    printf("\n"); 
     printf("\n"); 
   printf("Total weight: %.2lf\n", total_wei); 

    printf("Average weight: %.2lf\n", total_wei/5); 

    printf("Max weight: %.2lf\n", list[max]); 

    
   return 0;
} */

/* //Print 2D array in reverse
#include <iostream>
using namespace std;

int main()
{
    int array[4][3];
    int input;

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> input;
            array[i][j] = input;
        }
    }
    for (int i = 3; i != -1 ; i--)
    {
        for (int j = 2; j != -1; j--)
        {
            cout<< array[i][j]<<" ";
        }
        cout << endl; 
    }
    return 0;
} */

/* //18.6 LAB: Contains the character
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int size;
    string input;
    char letter; 
    vector<string> list; 
    vector<string> final; 

    cin >> size; 
    int i= 0;
    while (i < size)
    {
        cin >> input; 
        list.push_back(input); 
        i++; 
    }
    cin >> letter; 

    for (int j = 0; j < size; j++)
    {  
        size_t find = list[j].find(letter); 
        if(find!= std::string::npos){
            final.push_back(list[j]);
        }
    }

    for (size_t k = 0; k < final.size(); k++)
    {
        cout<< final[k]<<",";  
    }
    cout << endl; 
   return 0;
}
 */
/* //18.4 LAB: Adjust list by normalizing
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

int main()
{
    int size, max = 0;
    ;
    float input;
    vector<float> list;
    cin >> size;
    int i = 0;
    while (i < size)
    {
        cin >> input;
        list.push_back(input);
        i++;
    }

    for (int j = 0; j < size; j++)
    {
        if (list[max] < list[j])
        {
            max = j;
        }
    }

    for (int k = 0; k < size; k++)
    {
        cout << fixed << setprecision(2);
        float ans = list[k] / list[max];
        cout << ans << " ";
    }
    cout << endl;
    return 0;
} */

//-------------------------------------------------------------------------------------------

/* //18.1 LAB: Output numbers in reverse
#include <iostream>
#include <vector>   // Must include vector library to use vectors
using namespace std;

int main() {
   vector<int> userInts; // A vector to hold the user's input integers
    int input,c; 
    int i =0;
    cin >> c;

    while(i != c){
        cin >> input; 
        userInts.push_back(input); 
        i++;
    } 

    for (int i = userInts.size()-1; i != -1; i--)
    {
        cout<< userInts[i]<<","; 
    }
    cout << endl; 
   return 0;
} */

//-------------------------------------------------------------------------------------------
// //Drawing right triangle
// #include <iostream>
// using namespace std;

// int main()
// {
//     char triangleChar;
//     int triangleHeight;

//     cout << "Enter a character:" << endl;
//     cin >> triangleChar;

//     cout << "Enter triangle height:" << endl;
//     cin >> triangleHeight;
//     cout << endl;
//     for (int i = 0; i < triangleHeight; i++){
//        for (int j = 0; j <= i; j++)
//        {
//            cout<<triangleChar;
//        }
//        cout << endl;
//     }

//     return 0;
// }

//-------------------------------------------------------------------------------------------
// //17.14 LAB: Count multiples
// #include<iostream>
// using namespace std;
// int main () {
//     int high, low, x, count=0;

//     cin >> low >> high >> x;

//     for (int i = low; i <= high; i++){
//         if(i %x == 0){
//             count++;
//         }
//     }
//     cout<< count << endl;
//     return 0;
// }

//-------------------------------------------------------------------------------------------
// //17.11 LAB: Print string in reverse (2nd way below())
// //
// #include <iostream>
// using namespace std;

// int main() {
//    string input;

//    while(getline(cin, input)){
//       if((input == "Done") || (input == "D") || (input == "done")){
//          break;
//       }
//       else {
//          for (size_t i = 0; i< input.length() ; i++)
//          {
//             cout<<input[input.size()-1-i];
//          }
//       }
//       cout << endl;
//    }

//    return 0;
// }

// //17.11 LAB: Print string in reverse (2nd way above))
// #include <iostream>
// using namespace std;

// int main() {
//    string input;

//    while(getline(cin, input)){
//       if((input == "Done") || (input == "D") || (input == "done")){
//          break;
//       }
//       else {
//          for (size_t i = input.length()-1; i != -1; i--)
//          {
//             cout<<input[i];
//          }
//       }
//       cout << endl;
//    }

//    return 0;
// }

//-------------------------------------------------------------------------------------------
// //17.8 LAB: Count input length without spaces, periods, exclamation points, or commas
// #include <iostream>
// #include <string>
// using namespace std;

// int main() {
//    string userText;
//    // Add more variables as needed
//    size_t len=0;

//    getline(cin, userText);  // Gets entire line, including spaces.

//    for (size_t i = 0; i < userText.length(); i++)
//    {
//       if((userText[i] == ',')|| (userText[i]== ' ') || (userText[i]== '.') || (userText[i]== '!')){

//       }
//       else {
//          len++;
//       }
//    }
//    cout << len<<endl;
//    return 0;
// }

// //17.6 LAB: Password modifier
// #include <iostream>
// #include <string>
// using namespace std;

// int main(){

//    string input;

//    cin >> input;
//    cout<<input.length()<<endl;
//    for (size_t i = 0; i < input.length(); i++)
//    {
//       if(input[i]== 'i'){
//          input[i] = '1';
//          continue;
//       }
//       if(input[i]== 'a'){
//          input[i] = '@';
//          continue;
//          }
//       if(input[i]== 'm'){
//          input[i] = 'M';
//          continue;
//          }
//       if(input[i]== 'B'){
//          input[i] = '8';
//          continue;
//       }
//       if(input[i]== 's'){
//          input[i] = '$';
//          continue;
//       }
//    }
//    cout << input<<endl;
// }

//-------------------------------------------------------------------------------------------
// //17.3 LAB: Varied amount of input data
// #include <iostream>
// #include<vector>
// using namespace std;

// int main() {
//    int n,sum=0,count, max=0;
//    vector<int> v;
//    while(cin>>n){
//       if(n>=0){
//          v.push_back(n);
//          count++;
//       }
//       else break;
//    }
//    for (size_t i = 0; i < v.size(); i++)
//    {
//       sum = sum +v[i];
//       if(v[max]<v[i]){
//          max = i;
//       }
//    }

//    cout<< v[max]<<" "<< sum/v.size();
//    return 0;
// }

//-------------------------------------------------------------------------------------------

// //finnaly a question
// #include <iostream>
// #include <string>
// using namespace std;

// int main() {
//     string input;
//     int n;

//     while(cin>> input){
//         if(input == "quit"){
//            break;
//         }
//         cin >> n;
//         printf("Eating %d %s a day keeps you happy and healthy.\n", n, input.c_str());
//     }

//    return 0;
// }

//-------------------------------------------------------------------------------------------
// #include <iostream>
// #include <string>
// using namespace std;

// int main()
// {
//    string input;

//    string BFF = "best friends forever";
//    string TMI = "too much information";
//    string IMHO = "in my humble opinion";
//    string IDK =  "I don't know";
//    string LOL = "laughing out loud";
//    cout<<"Input an abbreviation:\n";
//    cin >> input;

//    if(input == "BFF"){
//       cout<<BFF<<endl;
//    }
//    else if(input== "TMI"){
//       cout<<TMI<<endl;
//    }
//    else if(input=="IMHO"){
//       cout<<IMHO<<endl;
//    }
//    else if(input == "LOL"){
//       cout<<LOL<<endl;
//    }
//    else if(input == "IDK"){
//       cout<<IDK<<endl ;
//    }
//    else{
//       printf("Unknown\n");
//       }

// }

// // //Exact Change;
// #include <iostream>
// using namespace std;
//-------------------------------------------------------------------------------------------//-------------------------------------------------------------------------------------------
// int main() {

//    int input, temp1, temp2, temp3, temp4;
//    cin >> input;

//    if(input<=0) cout<<"No change"<< endl;

//    if(input >=100){
//       if(input<200){
//          cout << input/100<< " Dollar" << endl;
//       }
//       if(input>=200){
//          cout << input/100 <<" Dollars" << "\n";
//       }
//    }

//    if((input%100)>=25){
//       temp1 = input%100;
//       if((temp1/25) == 1){
//       cout << "1 Quarter"<<endl;
//       }
//       if((temp1/25) >=2){
//       cout<< temp1/25<< " Quarters" << endl;
//       }
//    }

//    if((input%100) % 25 >=10){
//       int temp2= temp1%25;
//       if((temp2/10) ==1){
//       cout << "1 Dime"<<endl;
//       }
//       if(temp2/10 >=2){
//          cout << temp2/10 << " Dimes" << endl;
//       }
//    }

//    if((((input%100) % 25)%10) >=5){
//    temp3 = (((input%100)%25) %10);
//    if((temp3/5) ==1 ){
//    cout<<"1 Nickel" << endl;
//    }
//    if(temp3/5 >=2) {
//    cout<< temp3/5<<" Nickels" <<endl;
//       }
//    }

//    if(((((input%100) % 25)%10) %5)>= 1){
//    temp4 = ((((input%100) % 25)%10) %5);
//    if((temp4/1)==1){
//    cout<<"1 Penny"<< endl;
//    }
//    if(temp4/1 >=2){
//    cout<< temp4/1<< " Pennies" << endl;
//       }
//    }

//    return 0;
// }
//-------------------------------------------------------------------------------------------//-------------------------------------------------------------------------------------------
// #include <iostream>
// using namespace std;

// int main()
// {
//    int input;
//    int dollar =0, quarter=0, dime=0, penny=0, nickel=0;
//    cin >> input;

//    dollar= input/100;
//       int temp = input%100;
//    if(temp>=25){
//    quarter = input/25;
//    }
//       int temp1 = input%25;
//    if(temp >= 10){
//    dime = temp/10;
//    }
//       int temp2= temp%10;
//    if(temp2 >=5){
//       nickel=temp2/5;
//    }
//       int temp3= temp2%5;
//    if(temp3 > 1){
//       penny = temp3;
//    }

//    printf("Dollar:%d, Quarter:%d, Dime:%d, Nickel:%d, Penny:%d\n", dollar, quarter, dime, nickel, penny);
//    return 0;
// }
//-------------------------------------------------------------------------------------------
// //Program: Text message expander

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
//------------------------------
// //golf score
// #include <iostream>
// #include <string>
// using namespace std;

// int main() {
// 	int par;
// 	int strokes;
// 	string name;

// 	cin >> par >> strokes;

//    if(par==3 || par ==4 || par ==5){
//      if((par -strokes) ==2) printf("Eagle\n");
//      else if((par-strokes)==1 ) printf("Birdie\n");
//      else if(par==strokes) printf("Par\n");
//      else if((strokes-par)==1) printf("Bogey\n");
//    }

//    else cout<< "Error";

// 	return 0;
// }

// //max between 3 numbers
// #include <iostream>
// using namespace std;

// int main() {
//     int val1;
//     int val2;
//     int val3;
//     int max;

//    cin >> val1 >> val2>>  val3;
//    if(val1 > val2){
//       max = val1;
//    }
//    else if(val2>val1){
//       max =val2;
//    }

//    else if(val1 == val2){
//       max = val1;
//    }

//    if(max > val3){
//       max = max;
//    }
//    else if (val3 > max) {
//       max= val3;
//    }

//    else if(max==val3){
//       max= max;
//    }

//    cout<<max<< endl;
//     return 0;
// }

// //name format
// #include <iostream>
// #include <string>
// using namespace std;

// int main()
// {
//    string firstName, middleName, lastName;

//    cin >> firstName >> middleName >> lastName;

//    if (lastName.empty())
//    {
//       cout << middleName << ", " << middleName[0] << "." << endl;
//    }

//    else if(!lastName.empty())
//    {
//       cout << lastName << ", " << firstName[0] << "." << middleName[0] << "." << endl;
//    }

//    return 0;
// }

//highway
// #include <iostream>
// using namespace std;

// int main()
// {
//    int highwayNumber;

//    cin >> highwayNumber;

//    if (1 <= highwayNumber && highwayNumber <= 99)
//    {
//       if (highwayNumber % 2 == 0)
//       {
//          printf("I-%d is primary, going east/west.\n", highwayNumber);
//       }
//       else
//          printf("I-%d is primary, going north/south.\n", highwayNumber);
//    }
//    else if (100 <= highwayNumber && highwayNumber <= 999 && highwayNumber % 100 != 0)
//    {
//       int temp = highwayNumber % 100;
//       if (temp % 2 == 0)
//       {
//          printf("I-%d is auxiliary, serving I-%d, going east/west.\n", highwayNumber, temp);
//       }
//       else
//          printf("I-%d is auxiliary, serving I-%d, going north/south.\n", highwayNumber, temp);
//    }
//    else
//       printf("%d is not a valid interstate highway number.\n", highwayNumber);
//    return 0;
// }

// //removing gray from rgb
// #include <iostream>
// using namespace std;

// int main() {

//   int red, green, blue;
//   int red1, green1, blue1;

//   cin>> red >> green >> blue;

//   if((red < green) && (red < blue)){
//     green = green - red;
//    blue = blue - red;
//    red = 0;
//   }

//   else if((green < red) && (green < blue)){
//    red = red - green;
//    blue = blue- green;
//    green = 0;
//   }
//   else if((blue < red) && (blue < green)){
//    red = red-blue;
//    green = green - blue;
//    blue = 0;
//   }

//    printf("%d %d %d\n", red, green, blue);

//   return 0;
// }

// #include <iostream>
// #include <string>      // Supports use of "string" data type
// using namespace std;

// int main() {
//    int    userInt;
//    double userDouble;
//    char character;
//    string line;
//    // FIXME: Define char and string variables

//    cout << "Enter integer:" << endl;
//    cin  >> userInt;

//    cout<<"Enter double:"<<endl;
//    cin >>userDouble;

//    cout<<"Enter character:"<<endl;
//    cin >> character;

//    cout<<"Enter string:"<< endl;
//    cin >>line;
//    // FIXME (1): Finish reading other items into variables, then output the four values on a single line separated by a space
//    printf("%d %.2lf %c %s\n", userInt, userDouble, character, line.c_str());

//    // FIXME (2): Output the four values in reverse
//    printf("%s %c %.2lf %d\n", line.c_str(), character, userDouble, userInt);

//    // FIXME (3): Cast the double to an integer, and output that integer
//    printf("%.2lf cast to an integer is %d\n", userDouble, (int)userDouble);
//    return 0;
// }

// #include <iostream>
// using namespace std;

// int main() {
//    int baseChar;
//    int headChar;
//    cin >> baseChar >> headChar;
//    int i, j;

//     for (int r = 0; r < 7; r++) {
//       for (int c1 = 0; c1 < 5; c1++) {
//          if (r < 2 || r > 4) {
//             cout << " ";
//          } else {
//             cout << baseChar;
//          }
//       }
//       for (int c2 = 0; c2 < 4; c2++) {
//          cout << headChar;

//       }
//       cout << "\n";
//    }
//    return 0;
// }
