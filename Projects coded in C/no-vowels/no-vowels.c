// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

string replace(string word);

int main(int argc, string argv[])
{
    // Your program must accept a single command-line argument, which will be the word that you want to convert

   if (argc == 2)
   {
       printf("%s\n", replace (argv[1]));

   }
   else
   {
       printf("Usage: ./no-vowels word \n");
       return 1;
   }

}
// Your program must contain a function called replace which takes a string input and returns a string output.

// This function will change the following vowels to numbers: a becomes 6, e becomes 3, i becomes 1, o becomes 0 and u does not change.
// the user must enter the word as an array

string replace (string word)
{

    for (int i = 0; i < strlen(word); i++)
    {
        // tolower(word[i]);
        if (word[i] == 'a')
        {
            word[i] = '6';
        }
        else if (word[i] == 'e')
        {
            word[i] = '3';
        }
        else if (word[i] == 'i')
        {
            word[i] = '1';
        }
        else if (word[i] == 'o')
        {
            word[i] = '0';
        }
    }
    return word;
}
