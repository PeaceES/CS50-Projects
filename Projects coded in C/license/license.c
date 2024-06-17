#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    // Check for command line args
    if (argc != 2)
    {
        printf("Usage: ./read infile\n");
        return 1;
    }

    // Create buffer to read into
    char buffer[7];               // there's going to be 7 characters in this buffer; so the computer reads string by string

    // Create array to store plate numbers
    char *plates[8];                      // there's an array of 8 strings for each plate number (of length 6 + NUL terminator)

    FILE *infile = fopen(argv[1], "r");     // open in 'read' mode - the pointer *infile of type FILE is pointing to a memory space dedicated to opening and reading argv 1

    int idx = 0;         // counting how many times we've read something - what is this - i think the index of the plate number that we're currently reading/ printing

    while ((fread(&buffer, 1, 7, infile)) == 7)    // it's just the formula of how fread works - fread(buffer, size of each byte, how many characters, name of file)
    {
        // Replace '\n' with '\0'
        buffer[6] = '\0';

        // Save plate number in array
        plates[idx] = malloc(7);
        strcpy(plates[idx], buffer);
        idx++;
    }

    for (int i = 0; i < 8; i++)
    {
        printf("%s\n", plates[i]);
    }
}
