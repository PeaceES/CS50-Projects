#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // get input from user 1-8 include
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    // print #s

    for (int row = 0; row < height; row++) // for every row
    {
        for (int space = 0; space < height - row - 1; space++) // making the pyramids right aligned
        {
            printf(" ");
        }
        for (int column = 0; column <= row; column++) //  one of the key in visualising how this code works is knwoing that column initialises to 0 every time the row loop restarts
        {
            printf("#");
        }

        printf("  ");                                 // the space between the pyramids
        for (int column = 0; column <= row; column++) // printing the left aligned pyramid
        {
            printf("#");
        }
        printf("\n");
    }
}