// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <string.h>
#include <stdio.h>

int check_commands(int, string[]);
void replace(string[]);

int main(int argc, string argv[])
{
    check_commands(argc, argv);
}

int check_commands(int argc, string argv[])
{
    if (argc == 2 && argc < 3)
    {
        replace(argv);
    }
    else
    {
        printf("No commands found or too many\n");
        return 1;
    }
    return 0;
}

void replace(string argv[])
{
    for (int i = 0, length = strlen(argv[1]); i < length; i++)
    {
        switch (argv[1][i])
        {
        case 'a':
            argv[1][i] = '6';
            break;
        case 'e':
            argv[1][i] = '3';
            break;
        case 'i':
            argv[1][i] = '1';
            break;
        case 'o':
            argv[1][i] = '0';
            break;
        }
    }

    printf("%s\n", argv[1]);
}