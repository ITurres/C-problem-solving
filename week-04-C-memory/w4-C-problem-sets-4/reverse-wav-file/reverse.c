#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "wav.h"

const int HEADER_SIZE = 44;

int check_format(WAVHEADER header);
int get_block_size(WAVHEADER header);

int main(int argc, char *argv[])
{
    // Ensure proper usage
    if (argc != 3)
    {
        printf("Usage: ./reverse input.wav output.wav\n");
        return 1;
    }
    // Open input file for reading

    FILE *inputFile = fopen(argv[1], "r");
    if (inputFile == NULL)
    {
        printf("file couldn't open./\n");
        fclose(inputFile);
        return 2;
    }
    // Read header into an array
    WAVHEADER newHeader;
    fread(&newHeader, HEADER_SIZE, 1, inputFile);

    // Use check_format to ensure WAV format
    if (check_format(newHeader) != 0)
    {
        printf("Input is not a WAV file.\n");
        return 3;
    }

    // Open output file for writing
    FILE *outputFile = fopen(argv[2], "w");
    if (outputFile == NULL)
    {
        printf("file couldn't open./\n");
        fclose(outputFile);
        return 4;
    }

    // Write header to file
    fwrite(&newHeader, HEADER_SIZE, 1, outputFile);

    // Use get_block_size to calculate size of block
    int blockSize = get_block_size(newHeader);

    // Write reversed audio to file
    fseek(inputFile, blockSize, SEEK_END);
    BYTE c[blockSize];
    while (ftell(inputFile) - blockSize > HEADER_SIZE)
    {
        fseek(inputFile, -2 * blockSize, SEEK_CUR);
        fread(&c, blockSize, 1, inputFile);
        fwrite(&c, blockSize, 1, outputFile);
    }

    fclose(inputFile);
    fclose(outputFile);
}

int check_format(WAVHEADER header)
{
    int formatOk = 1; // false
    char waveFormat[] = {'W', 'A', 'V', 'E'};

    for (int i = 0, length = sizeof(waveFormat); i < length; i++)
    {
        if (header.format[i] == waveFormat[i])
            formatOk = 0; // true
        else
            formatOk = 1;
    }
    return formatOk;
}

int get_block_size(WAVHEADER header)
{
    int bytesPerSample = header.bitsPerSample / 8;
    return header.numChannels * bytesPerSample;
}