/* 
 * File: lab6_skeleton.cpp
 *
 * Lab 6: Recursion - Alien Word Parsing
 */

#include <iostream>
#include <cstring>

using namespace std;

const int MAX_LEN = 256; 

bool correct_word(char word[],int start,int end)
{
   int mid = start;
   int count = 0;
   while(mid < MAX_LEN)
   {  
         if(word[mid] - 'a' >= 0 && 'z' - word[mid] >= 0)
         {
            count++;
            if(count == 2)break;
         }
         mid++;
   }
   mid--;
   /* ADD YOUR CODE HERE */
   /* THIS MUST BE A RECURSIVE FUNCTION */
   //cout << start <<' '<< end << endl;
    // Task 1: Base case with only a single character
   if(start==end)return (word[start] - 'a' >= 0 && 'z' - word[start] >= 0);
    // Task 2: Recursive case with suffix characters '@', or '#'
   if(word[end] == '@' || word[end] == '#')return correct_word(word,start,end-1);
    // Task 3: Recursive case with concatenation characters '|' at suffix position.
   if(word[end]== '|')
   {  
      return correct_word(word,start,mid) && correct_word(word,mid+1,end-1);
   }
    // Task 4: Recursive case with concatenation characters '#' at prefix position.
   if(word[start] == '#')
   {
      return correct_word(word,start+1,mid) && correct_word(word,mid+1,end);
   }
    // All remaining cases are wrong
    return false;
}


int main()
{
   char word[MAX_LEN];
   char c;
   
   do{
      cout << "Enter a word: ";
      cin >> word;
      if (correct_word(word, 0, strlen(word) - 1))
         cout << "The word is CORRECT!\n";
      else
         cout << "The word is INCORRECT!\n";
      cout << "Do you want to enter a new word ('Y'/'y' for Yes, 'N'/'n' for No)? ";
      cin >> c; 
   } while (c == 'Y' || c=='y');

   return 0;
}

