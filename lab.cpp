//19.33 LAB*: Program: Authoring assistant
#include <iostream>
#include <string>
using namespace std;

int GetNumOfNonWSCharacters(string);
void ExecuteMenu(char, string);
void PrintMenu();
int GetNumOfWords(string);
int FindText(string, string);
string ReplaceExclamation(string);   
string ShortenSpace(string); 

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
    else if(choice == 'w') printf("Number of words: %d\n", GetNumOfWords(input));
    else if(choice == 'f') {
        cin.ignore();
        string find; 
        cout<<"Enter a word or phrase to be found:\n"; 
        getline(cin,find); 
        printf("\"%s\" instances: %d\n",find.c_str(), FindText(find, input));
    }  
    else if(choice == 'r'){
        string temp; 
        temp = ReplaceExclamation(input); 
        cout<<"Edited text: " << temp<<endl; 
    }
    else if(choice == 's'){
        string temp; 
        temp = ShortenSpace(input); 
        cout<<"Edited text: " << temp<<endl; 
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
//      for(int i= 0; i==len; i++){

  if(usrStr[i] == ' ' && i != len-1 && usrStr[i-1]!=' ')
    totalWords++;
    
}
      
return totalWords+1;
}

int FindText( string searchText, string wordPhrase){
  int count = 0;

  size_t nPos = wordPhrase.find(searchText, 0); 
  while(nPos != string::npos)
  {
      count++;
      nPos = wordPhrase.find(searchText, nPos+1);
  }
return count;
}

string ReplaceExclamation(string s) //function to replacing exclamation.
{
    string newS = ""; //to store string.
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == '!') //if present character is ! then replacing with .
            newS += '.';
        else //if present character is not a ! then storing as it is.
            newS += s[i];
    }
    return newS; //returning new string.
}

string ShortenSpace(string s) //function to remove extra spaces.
{
    string newS = "";
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] != ' ') // if present character is not a space then storing in new string.
            newS += s[i];
        else if (i != 0 && s[i - 1] != ' ' && s[i] == ' ') //if present character is space and previous character is alphabet then store one space.
            newS += s[i];
    }
    return newS; //returning new string.
}

int main() {
    string input;
    char choice;  
    cout <<"Enter a sample text:\n";
    getline(cin, input); 
    cout<< endl; 

    cout<<"You entered: "<< input<<endl; 
    cout<<endl; 
    PrintMenu(); 
    cout<<"Choose an option:\n";
    while(cin >> choice)
    {
        if(choice == 'q') break; 
        ExecuteMenu(choice,input);
        cout<<endl; 
        PrintMenu();
        cout<<"Choose an option:\n";

    }
   return 0;
}



/* //19.33 LAB*: Program: Authoring assistant
#include <iostream>
#include <string>
using namespace std;

void GetNumOfNonWSCharacters(string);
void ExecuteMenu(char, string);
void PrintMenu();
void GetNumOfWords(string);
void FindText(string, string);
string ReplaceExclamation(string);   
string ShortenSpace(string); 

void PrintMenu(){
    printf("MENU\nc - Number of non-whitespace characters\nw - Number of words\nf - Find text\nr - Replace all !'s\ns - Shorten spaces\nq - Quit"); 
    cout<<endl; 
}
void ExecuteMenu(char choice, string input){
    if(choice == 'c') GetNumOfNonWSCharacters(input);
    else if(choice == 'w') GetNumOfWords(input);
    else if(choice == 'f') {
        string find; 
        cout<<"Enter a word or phrase to be found:\n"; 
        cin >> find; 
        FindText(find, input);
    }  
    else if(choice == 'r'){
        string temp; 
        temp = ReplaceExclamation(input); 
        cout<<"Edited text: " << temp<<endl; 
    }
    else if(choice == 's'){
        string temp; 
        temp = ReplaceExclamation(input); 
        cout<<"Edited text: " << temp<<endl; 
    }
    else if(choice == 'q'){
        return; 
    }
}
void GetNumOfNonWSCharacters(string input){
     int count=0; 
    for (int i = 0; i < input.length(); i++)
    {
       if(input[i] != ' '){
           count++; 
       } 
    }
    cout<<"Number of non-whitespace characters: "<< count<<endl; 
}
void GetNumOfWords(string input){
    int count =0; 
    for (size_t i = 0; i < input.size(); i++){
        if(input[i] == ' '){
            count++;
            if(input[i+1]==' '){
                count = count -1; 
            } 
        }
    }
    cout<< count+1 <<endl; 
}
void FindText(string find, string input){
        int i=0, j, temp, countW=0, chk;
    
    while(input[i]!='\0')
    {
        temp = i;
        j=0;
        while(find[j]!='\0')
        {
            if(input[i]==find[j])
                i++;
            j++;
        }
        chk = i-temp;
        if(chk==j)
            countW++;
        i = temp;
        i++;
    }
    cout<<countW<<endl; 
}
string ReplaceExclamation(string input){
    for (size_t i = 0; i < input.size(); i++)
    {
        if(input[i]=='!'){
            input[i] = '.'; 
        }
    }
    return input; 
}
string ShortenSpace(string input){
    size_t n = input.size(); 
     for (size_t i = 0; i < n; i++){
        if(input[i] == ' '){
            if(input[i+1]==' '){
                input.erase(input.begin()+i+1); 
            } 
        }
    }
    
}

int main() {
    /* string input;
    char choice;  
    cout <<"Enter a sample text:\n";
    getline(cin, input); 
    cout<< endl; 

    cout<<"You entered: "<< input<<endl; 
    cout<<endl;  */
   // PrintMenu(); 
    /* cout<<"Choose an option:\n";
    while(cin >> choice)
    {
        if(choice == 'q') break; 
        ExecuteMenu(choice,input);
        cout<<endl; 
        PrintMenu();
        cout<<"Choose an option:\n";

    } 
   return 0;
}
*/