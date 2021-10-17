#include <bits/stdc++.h>
    using namespace std;
int GetNumOfNonWSCharacters(string s) //function to count the number of non whitespace characters.
{
    int nonWhite = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] != ' ') //if character is not a space then counting.
        {
            nonWhite++;
        }
    }
    return nonWhite; //returning count.
}
int GetNumOfWords(string s) //function to count the number of words.
{
    int words = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (i != 0 && s[i - 1] != ' ' && s[i] == ' ') //if space occurred means one word. So incrementing count.
            words++;
    }
    words++;      //counting last word.
    return words; //returning count.
}
int FindText(string s, string sub) //function to find the instances of a sub string.
{
    //finding lengths.
    int M = sub.length();
    int N = s.length();

    int Count = 0;

    for (int i = 0; i <= N - M; i++)
    {
        int j;
        for (j = 0; j < M; j++) //from the present index i, checking for substring in main string.
            if (s[i + j] != sub[j])
                break;

        if (j == M) //if j is go to the length of substring i.e substring present then counting.
        {
            Count++;
            j = 0;
        }
    }
    return Count; //returning count.
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
void PrintMenu(string s) //function to print the menu and calling the function.
{
    char option;
    while (1) //infinity loop to ask input again and again.
    {
        //printing menu.
        cout << "\nMENU" << endl;
        cout << "c - Number of non-whitespace characters" << endl;
        cout << "w - Number of words" << endl;
        cout << "f - Find text" << endl;
        cout << "r - Replace all !'s" << endl;
        cout << "s - Shorten spaces" << endl;
        cout << "q - Quit" << endl;

        cout << "\nChoose an option: "; //prompting and reading user option.
        cin >> option;

        if (option == 'q') //if user want to quit then stop the execution.
            break;
        else if (option == 'c') //if user want to count number of non whitespaces then call function and print result.
        {
            cout << "Number of non-whitespace characters: " << GetNumOfNonWSCharacters(s) << endl;
        }
        else if (option == 'w') //if user want to count the number words then call the function and print result.
        {
            cout << "Number of words: " << GetNumOfWords(s) << endl;
        }
        else if (option == 'f') //if user want to find the occurrences of sub string
        {
            string sub;
            //prompting and reading word to search.
            cin.ignore();
            cout << "Enter a word or phrase to be found:" << endl;
            getline(cin, sub);

            cout << sub << " instances: " << FindText(s, sub) << endl; //calling the function and printing result.
        }
        else if (option == 'r') //if user want to replace ! with .
        {
            s = ReplaceExclamation(s);            //calling the function and getting the new string.
            cout << "Edited text: " << s << endl; //printing new string.
        }
        else if (option == 's') //if user want to short the spaces.
        {
            s = ShortenSpace(s);                  //calling the function and getting new string.
            cout << "Edited text: " << s << endl; //printing new string.
        }
    }
}
int main()
{
    string s;
    //prompting and reading text.
    cout << "Enter a sample text:" << endl;
    getline(cin, s);

    cout << "\nYou entered: " << s << endl; //printing entered string.
    PrintMenu(s);                           //calling the PrintMenu function.
    return 0;
}