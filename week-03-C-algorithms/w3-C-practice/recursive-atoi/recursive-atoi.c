#include <cs50.h>
#include <ctype.h>
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

    // Convert string to int
    printf("%i\n", convert(input));
}

// Start with the last char and convert it into an integer value.
// then shorten the string, removing the last char, and then recursively call convert using the shortened
// string as input, where the next char will be processed.
// Return this value plus 10 times the integer value of the new shortened string.

int convert(string input)
{
    char lastChar = input[strlen(input) - 1];
    int intVal = lastChar - 48;
    input[strlen(input) - 1] = '\0'; // here we remove last digit---input will be ready to be pass on line 43 without last char an so on..

    if (input[strlen(input) - 1] == '\0')
        return intVal;
    else
        return (10 * convert(input) + intVal);
}

