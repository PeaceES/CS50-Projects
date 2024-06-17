#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;                // create a type called BYTE that is worth a byte
const int BLOCK = 512;               // we are going to be reading and writing one block i.e 512 B at a time

int main(int argc, char *argv[])
{

    // ensure the user enters the correct number of arguments after the command
    if (argc != 2)
    {
        printf("Usage: ./recover file \n");

        return 1;
    }

    // open argv[1] into a file named 'forensic_image'
    FILE *forensic_image = fopen(argv[1], "r");

    //check that the file exists or opens for reading
    if (forensic_image == NULL)
    {
        printf("Could not open forensic image \n");
        return 1;
    }

    // create empty holding glass of size 512 B i.e one block space
    // it can also be considered an array of size BLOCK
    BYTE buffer_block[BLOCK];
    int n = 0;                                    // where n records the number of JPEG signatures we have come across
    FILE *recovered_image;                        // create a holding file for the recovered images
    char filename [8];                            // the file to which we copy the new block. it has 8 characters to allow for the full new name

    // read the first block of the forensic image and store it in buffer block

    while ((fread(buffer_block, BLOCK, 1, forensic_image)) == 1)
    {
        // check that the first four bytes of the block correspond to JPEG signature
        if (buffer_block[0] == 0xff && buffer_block[1] == 0xd8 && buffer_block[2] == 0xff && (buffer_block[3] & 0xf0) == 0xe0)
        {
            // every time you come across a new signature, close the preview file exept if this the first file
            if (n > 0)
            {
                fclose(recovered_image);
            }

            // make a new jpeg file in the format ###.jpg
            sprintf(filename, "%03i.jpg", n);
            recovered_image = fopen(filename, "w");
            fwrite(buffer_block, BLOCK, 1, recovered_image);
            n += 1;
        }

        else if (n > 0)
        {
            fwrite(buffer_block, BLOCK, 1, recovered_image);

        }

    }
}
