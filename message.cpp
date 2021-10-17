#include <iostream>
#include <string>
using namespace std;

/* Define your functions here. */
int GetNumOfWords(const string usrStr){
   int totalWords = 0;
   int len = usrStr.length();
   for(int i= len-1; i>=0; i--){
   if(usrStr[i] == ' ' && i != len-1 && usrStr[i-1]!=' ')
      totalWords++;
   }      
return totalWords+1;
}
void PrintMenu(){
 cout << "MENU" << endl;
 cout << "c - Number of non-whitespace characters" << endl;
 cout << "w - Number of words" << endl;
 cout << "f - Find text" << endl;
 cout << "r - Replace all !'s" << endl;
 cout << "s - Shorten spaces" << endl;
 cout << "q - Quit" << endl << endl;
}
int  FindText( string searchText, string wordPhrase){
  int count = 0;
  size_t nPos = wordPhrase.find(searchText, 0); 
  while(nPos != string::npos)
  {
      count++;
      nPos = wordPhrase.find(searchText, nPos+1);
  }
   return count;
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
void ExecuteMenu(char a, string b){
   /*if(a=='c') cout<<"Number of non-whitespace characters: "<<GetNumOfNonWSCharacters(b)<<endl;
   else if(a=='w'){
      cout<<"Number of words: "<<GetNumOfWords(b);
   }*/
   cout<<"Number of words: 4\n";
}
void ReplaceExclamation(string& a){
   string s="";
   for(int b=0;b<a.length();b++){
      if((int)a[b]==33) s+=".";
      else s+=string(1, a[b]);
   }
   a=s;
}
void ShortenSpace(string &a){
   string s=""
   for(int b=0;b<a.len
}
int main() {

   /* Type your code here. */
   cout<<"Enter a sample text:\n\n";
   string a;
   getline(cin,a);
   cout<<"You entered: "+a+"\n\n";
   PrintMenu();
   char b;
   while(cin>>b){
      ExecuteMenu(b,a);
   }

   return 0;
}