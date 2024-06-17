#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// so far the program takes a number, checks that it's the valid length.
// then turns it into an array
// next: 1) If follows Luhn's calculation + number of digits, then we print the type


int main(void)
{
    // AMEX uses 15 digits; start with 34 or 37
    // Matstercard uses 16 digits; starts with 51-55
    // Visa uses 13 & 16 digits; starts with 4

    // get a number of from the user that matches lenght of a card

    long n;
    int length;

    do
    {
        n = get_long("Number: ");
        length = floor(log10(n)) + 1;
    }
    while (n <= 0);

    if ((length != 15 && length != 16 && length != 13))
    {
        printf("INVALID\n");
    }
    else
    {
        long m = n;
        int *numberArray = calloc(length, sizeof(int));
        for(int i = (length - 1); i > (-1); i--, m /= 10)
        {
            numberArray[i] = m % 10;
        }
        // printf("%i \n", numberArray[i]);        } // so far so good
        //int loop;
        //for (loop = 0; loop < length; loop ++)        //{
        // printf("%i", numberArray[loop]);        //}

       // printf("%li \n", n);   // printing n twice idk why

       // AMEX

        if ((length == 15) && ((n / 10000000000000 == 34) || (n / 10000000000000 == 37))) // AND luhn's calculation is true, then print amex
        {

            // Luhn's formula:

            // it's the product's digits & not the products themselves sigh

            int a = numberArray[13] * 2;
            if (a > 9)
            {
                a = (a % 10) + (a - (a % 10)) / 10;
            }
            int b = numberArray[11] * 2;
            if (b > 9)
            {
                b = (b % 10) + (b - (b % 10)) / 10;
            }
            int c = numberArray[9] * 2;
            if (c > 9)
            {
                c = (c % 10) + (c - (c % 10)) / 10;
            }
            int d = numberArray[7] * 2;
            if (d > 9)
            {
                d = (d % 10) + (d - (d % 10)) / 10;
            }
            int e = numberArray[5] * 2;
            if (e > 9)
            {
                e = (e % 10) + (e - (e % 10)) / 10;
            }
            int f = numberArray[3] * 2;
            if (f > 9)
            {
                f = (f % 10) + (f - (f % 10)) / 10;
            }
            int g = numberArray[1] * 2;
            if (g > 9)
            {
                g = (g % 10) + (g - (g % 10)) / 10;
            }

            int even_sum = (a + b + c + d + e + f + g);
            // printf("%i \n", even_sum);

            int odd_sum = (numberArray[14] + numberArray[12] + numberArray[10] + numberArray[8] + numberArray[6] + numberArray[4] +
                           numberArray[2] + numberArray[0]);
            // printf("%i \n", odd_sum);
            int total_sum = odd_sum + even_sum;
            // printf("%i \n", (odd_sum + total_sum));

            if (total_sum % 10 == 0)
            {
                printf("AMEX\n");
            }
            else
            {
                printf("INVALID\n");
            }

            // MASTERCARD
        }
        else if ((n / 10000000000000 != 34) && (n / 10000000000000 != 37))
        {
            printf("INVALID\n");
        }

        if ((length == 16) && (n / 100000000000000 == 51 || n / 100000000000000 == 52 || n / 100000000000000 == 53 ||
                               n / 100000000000000 == 54 || n / 100000000000000 == 55))
        {
            int a = numberArray[14] * 2;
            if (a > 9)
            {
                a = (a % 10) + (a - (a % 10)) / 10;
            }
            int b = numberArray[12] * 2;
            if (b > 9)
            {
                b = (b % 10) + (b - (b % 10)) / 10;
            }
            int c = numberArray[10] * 2;
            if (c > 9)
            {
                c = (c % 10) + (c - (c % 10)) / 10;
            }
            int d = numberArray[8] * 2;
            if (d > 9)
            {
                d = (d % 10) + (d - (d % 10)) / 10;
            }
            int e = numberArray[6] * 2;
            if (e > 9)
            {
                e = (e % 10) + (e - (e % 10)) / 10;
            }
            int f = numberArray[4] * 2;
            if (f > 9)
            {
                f = (f % 10) + (f - (f % 10)) / 10;
            }
            int g = numberArray[2] * 2;
            if (g > 9)
            {
                g = (g % 10) + (g - (g % 10)) / 10;
            }
            int h = numberArray[0] * 2;
            if (h > 9)
            {
                h = (h % 10) + (h - (h % 10)) / 10;
            }

            int even_sum = (a + b + c + d + e + f + g + h);
            // printf("%i \n", even_sum);

            int odd_sum = (numberArray[15] + numberArray[13] + numberArray[11] + numberArray[9] + numberArray[7] +
            numberArray[5] + numberArray[3] + numberArray[1]);
            // printf("%i \n", odd_sum);
            int total_sum = odd_sum + even_sum;
            // printf("%i \n", (total_sum));

            if (total_sum % 10 == 0)
            {
                printf("MASTERCARD\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }

        // Visa cards
        if (((length == 13) || (length == 16)) && ((n / 1000000000000 == 4) || (n / 1000000000000000 == 4)))
        {
            // luhn's math
            // if length is 16

            if (length == 16)
            {
                int a = numberArray[14] * 2;
            if (a > 9)
            {
                a = (a % 10) + (a - (a % 10)) / 10;
            }
            int b = numberArray[12] * 2;
            if (b > 9)
            {
                b = (b % 10) + (b - (b % 10)) / 10;
            }
            int c = numberArray[10] * 2;
            if (c > 9)
            {
                c = (c %10) + (c - (c % 10)) / 10;
            }
            int d = numberArray[8] * 2;
            if (d > 9)
            {
                d = (d % 10) + (d - (d % 10)) / 10;
            }
            int e = numberArray[6] * 2;
            if (e > 9)
            {
                e = (e % 10) + (e - (e % 10)) / 10;
            }
            int f = numberArray[4] * 2;
            if (f > 9)
            {
                f = (f % 10) + (f - (f % 10)) / 10;
            }
            int g = numberArray[2] * 2;
            if (g > 9)
            {
                g = (g % 10) + (g - (g % 10)) / 10;
            }
            int h = numberArray[0] * 2;
            if (h > 9)
            {
                h = (h % 10) + (h - (h %10)) / 10;
            }

            int even_sum = (a + b + c + d + e + f + g + h);
            // printf("%i \n", even_sum);

            int odd_sum = (numberArray[15] + numberArray[13] + numberArray[11] + numberArray[9] + numberArray[7] +
                           numberArray[5] + numberArray[3] + numberArray[1]);
            // printf("%i \n", odd_sum);
            int total_sum = odd_sum + even_sum;
            // printf("%i \n", (total_sum));

            if (total_sum % 10 == 0)
            {
               printf("VISA\n");
            }
            // else
            //{
            //printf("INVALID\n");
            //}

            // if length = 13
            }
            if (length == 13)
            {
                int a = numberArray[11] * 2;
            if (a > 9)
            {
                a = (a % 10) + (a - (a % 10)) / 10;
            }
            int b = numberArray[9] * 2;
            if (b > 9)
            {
                b = (b % 10) + (b - (b % 10)) / 10;
            }
            int c = numberArray[7] * 2;
            if (c > 9)
            {
                c = (c % 10) + (c - (c % 10)) / 10;
            }
            int d = numberArray[5] * 2;
            if (d > 9)
            {
                d = (d % 10) + (d - (d % 10)) / 10;
            }
            int e = numberArray[3] * 2;
            if (e > 9)
            {
                e = (e % 10) + (e - (e % 10)) / 10;
            }
            int f = numberArray[1] * 2;
            if (f > 9)
            {
                f = (f % 10) + (f - (f % 10)) / 10;
            }
            int even_sum = (a + b + c + d + e + f);
            //printf("%i \n", even_sum);
            int odd_sum = (numberArray[12] + numberArray[10] + numberArray[8] + numberArray[6] + numberArray[4] + numberArray[2] + numberArray[0]);
            //printf("%i \n", odd_sum);
            int total_sum = odd_sum + even_sum;
            //printf("%i \n", (total_sum));
            if (total_sum % 10 == 0)
            {
               printf("VISA\n");
            }
            // else
            // {
            // printf("INVALID\n");
            //}
            //}
        }
        }

             }
}

