// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]);

    // TODO: Copy header from input file to output file

    //create buffer
    uint8_t buffer[HEADER_SIZE];

    fread(&buffer, sizeof(uint8_t), HEADER_SIZE, input);  // 'input' being where we're copying from and &buffer the address we're copying into
    fwrite(&buffer, sizeof(uint8_t), HEADER_SIZE, output); // why not write directly into output? why use a buffer?

    // TODO: Read samples from input file and write updated data to output file
    int16_t samplebuffer;

    while(fread(&samplebuffer, sizeof(int16_t), 1, input))   // how does the computer know to read the samples and not the header files?
    {
        samplebuffer = factor * samplebuffer;
        fwrite(&samplebuffer, sizeof(int16_t), 1, output);

    }

    // Close files
    fclose(input);
    fclose(output);
}

// can we just strcpy from buffer to output instead of using fwrite?