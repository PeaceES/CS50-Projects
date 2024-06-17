#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int convert(string input);

int main(void)
{
    string input = get_string("Enter a positive integer: ");

    for (int i = 0, n = strlen(input); i < n; i++)
    {
        if (!isdigit(input[i]))
        {
            printf("Invalid Input!\n");
            return 1;
        }
    }
    printf("%i\n", convert(input));



    // Convert string to int - to convert any str digit '7' to int 7, just do '7' - '0' or '7' - 48 #ASCII- so char to int calculations is possible in c
}

int convert(string input)
{
    // base case is that there is only one digit to be converted
    int length = strlen(input);

    if (length == 1)
    {
        return (input[0] - '0');                // return the integer version of this digit
    }

    char last_char = input[length - 1];      // Start by getting the index of the last char in the string (the char before the \0).

    int converted_last = last_char - '0';        // Convert this char into its numeric value.

    input[length - 1] = '\0';               // Remove the last char from the string by moving the null terminator one position to the left.

    // printf("input: %s \n", input);

    // Return this value plus 10 times the integer value of the new shortened string
    return converted_last + 10 * (convert (input));   // this is the part where we are applying the recursion

    // I have an explanation of how this recursive function works in my green exercise notebook
}

// the way this code works is such that for the number 768, it goes 700 + 60 + 8 and not 8 + 60 + 700
// it's just a detail, but it's important in understanding how recursion works  