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
    int elementsInBuffer = 7;
    char *buffer = malloc(elementsInBuffer * sizeof(char));
    if (buffer == NULL)
        return 1;

    // Create array to store plate numbers
    char *plates[8]; // array to hold the licenses

    FILE *infile = fopen(argv[1], "r");

    // Replace '\n' with '\0'
    // buffer[6] = '\0';
    int idx = 0;

    while (fread(buffer, sizeof(char), elementsInBuffer, infile))
    {
        plates[idx] = buffer;
        printf("%s", plates[idx]);
        idx++;
    }

    fclose(infile);

    free(buffer);
}
