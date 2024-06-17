#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

string substitute(string plaintext, char key[]);

int main(int argc, string argv[])
{
    // check key's validity
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else // argc == 2
    {
        if (strlen(argv[1]) != 26)
        {
            printf("Key must contain 26 characters\n");
            return 1;
        }
        else // there are 26 characters
        {
            int m = 0;
            for (int i = 0, n = strlen(argv[1]); i < n; i++)
            {
                if (isalpha(argv[1][i]))
                {
                    m++;
                }
            }
            if (m != 26)
            {
                printf("Usage: ./substitution key\n");
                return 1;
            }
            else // all 26 characters are alphabetical
            {
                int duplicate_check = 0;

                for (int i = 0; i < 26; i++)
                {
                    for (int j = i + 1; j < 26; j++)
                    {
                        if (argv[1][i] == argv[1][j])
                        {
                            duplicate_check++;
                        }
                    }
                }

                if (duplicate_check != 0)
                {
                    printf("Usage: ./substitution key\n");
                    return 1;
                }
                else // no 2 letters are the same: all checks done
                {
                    // now run substitute
                    // get plaintext from user
                    string plaintext = get_string("Plaintext: ");
                    string ciphertext = substitute(plaintext, argv[1]);
                    printf("ciphertext: %s\n", ciphertext);
                    return 0;
                }
            }
        }
    }
}

string substitute(string plaintext, char key[])
{
    static char ciphertext[100];
    int position;
    // go through every letter of the plaintext and find its position in the alphabet - then find said position in the key
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        // make the letter uppercase if it is alphabetical
        if isalpha (plaintext[i]) // we are only cyphering the alpha letters
        {
            if (isupper(plaintext[i])) // the isupper function is not working
            {
                position = plaintext[i] - 65;
                ciphertext[i] = toupper(key[position]);
            }
            else // it's lowercase and gets replaced with lowercase characters
            {
                position = plaintext[i] - 97;
                ciphertext[i] = tolower(key[position]);
            }
        }
        else
        {
            ciphertext[i] = plaintext[i]; // if not an alpha character, we just store it as it is
        }
    }
    return ciphertext;
}