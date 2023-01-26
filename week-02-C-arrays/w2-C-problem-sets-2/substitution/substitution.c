#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>

bool check_argv_length(string[]);
bool check_only_alphabet_char(string[]);
bool check_duplicates(string[]);
void cypher_engine(char, string[]);

int main(int argc, string argv[])
{
    string plainText = "";
    bool loopOut = false;

    do
    {
        if ((argc == 1 || argc > 2) || (!check_argv_length(argv) || !check_only_alphabet_char(argv)))
        {
            printf("Usage: ./substitution key\n");
            return 1;
        }
        else
        {
            if (!check_duplicates(argv))
            {
                plainText = get_string("plaintext: ");
                loopOut = true;
            }
            else
            {
                printf("Usage: ./substitution key\n");
                return 1;
            }
        }
    } while (loopOut == false);

    printf("ciphertext: ");
    for (int j = 0, length = strlen(plainText); j < length; j++)
    {
        cypher_engine(plainText[j], argv);
    }
    printf("\n");
}

bool check_argv_length(string argv[])
{
    const int validLength = 26;
    bool isValidLength = false;

    if (strlen(argv[1]) == validLength)
        isValidLength = true;
    else
        printf("Key must contain 26 characters.\n");
    return isValidLength;
}

bool check_only_alphabet_char(string argv[])
{
    bool noDigits = false;

    for (int i = 0, length = strlen(argv[1]); i < length; i++)
    {
        if (isalpha(argv[1][i]))
            noDigits = true;
        else
            return false; // shut function as soon as the first digit shows up.
    }
    return noDigits;
}

bool check_duplicates(string argv[])
{
    const int length = strlen(argv[1]);

    for (int i = 0; i < length; i++)
    {
        for (int j = i + 1; j < length; j++)
        {
            if (argv[1][i] == argv[1][j])
                // printf("it has a duplicate, and that is => %c\n", argv[1][j]);
                return true;
        }
    }
    return false;
}

void cypher_engine(char character, string argv[])
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
        for (int alphabetIndex = 0; alphabetIndex < alphabetSize; alphabetIndex++)
        {
            if (character == upperAlphabet[alphabetIndex] || character == lowerAlphabet[alphabetIndex])
            {
                if (wasUpper)
                    printf("%c", toupper(argv[1][alphabetIndex]));
                else
                    printf("%c", tolower(argv[1][alphabetIndex]));
            }
        }
    }
    else
    {
        printf("%c", character); // print non alphabet characters..
    }
}
