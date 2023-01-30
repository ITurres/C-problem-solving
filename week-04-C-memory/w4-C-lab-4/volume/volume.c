//! Modifies the volume of an audio file

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

    const int sizeOfInt16 = sizeof(int16_t);
    uint8_t newHeader[HEADER_SIZE]; //'same as a "buffer"'
    fread(newHeader, HEADER_SIZE, 1, input); //it reads everything from input and stores it on newHeader..
    fwrite(newHeader, HEADER_SIZE, 1, output);// it paste everything from newHeader to output

    int16_t buffer;

    while (fread(&buffer, sizeOfInt16, 1, input)) //-true- until size of data is 0, and so it will break the loop
    {
        buffer *= factor;
        fwrite(&buffer, sizeOfInt16, 1, output);
    }
    // Close files
    fclose(input);
    fclose(output);
}
