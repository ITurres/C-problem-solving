#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

bool only_digits(string[]);
int convert_to_int(string[]);
void rotate(char, int);

int main(int argc, string argv[])
{
    string plainText = "";
    bool loopOut = false;

    do
    {
        if ((argc == 1 ||
             argc > 2) ||
            !only_digits(argv))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
        else
        {
            plainText = get_string("plaintext: ");
            loopOut = true;
        }
    } while (loopOut == false);

    int key = convert_to_int(argv);

    printf("ciphertext: ");
    for (int i = 0, length = strlen(plainText); i < length; i++)
    {
        rotate(plainText[i], key);
    }
    printf("\n");
}

bool only_digits(string argv[])
{
    bool noDigits = false;

    for (int i = 0, length = strlen(argv[1]); i < length; i++)
    {
        if (isdigit(argv[1][i]))
            noDigits = true;
        else
            return false; // shut function as soon as the first non-digit char shows up.
    }

    return noDigits;
}

int convert_to_int(string argv[])
{
    // printf("atoi to argv[1] = %i\n", atoi(argv[1]));
    return atoi(argv[1]);
}

void rotate(char character, int key)
{
    char lowerAlphabet[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    char upperAlphabet[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    const int alphabetSize = 26;
    bool wasUpper = false;
    if (isupper(character))
    {
        wasUpper = true;
    }

    if (isalpha(character))
    {
        for (int j = 0; j < alphabetSize; j++)
        {
            if (character == upperAlphabet[j] || character == lowerAlphabet[j])
            {
                if (wasUpper)
                {
                    character = (int)character - 'A';             // = to alphabet index...
                    character = (character + key) % alphabetSize; // formula
                    printf("%c", (int)character + 'A');           // print upper back to ASCII
                }
                else
                {
                    character = (int)character - 'a';             // = to alphabet index...
                    character = (character + key) % alphabetSize; // formula
                    printf("%c", (int)character + 'a');           // print lower back to ASCII
                }
            }
        }
    }
    else
    {
        printf("%c", character); // print non alphabet characters..
    }
}