// Check that a password has at least one lowercase letter, uppercase letter, number and symbol
// Practice iterating through a string
// Practice using the ctype library

#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>

bool valid(string password);

int main(void)
{
    string password = get_string("Enter your password: ");
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol\n");
    }
}

// TODO: Complete the Boolean function below
bool valid(string password)
{
    bool hasUpper = false;
    bool hasLower = false;
    bool hasNumber = false;
    bool hasSymbol = false;

    for (int i = 0, length = strlen(password); i < length; i++)
    {
        // printf("%c\n", password[i]);
        if (password[i] >= 33 && password[i] <= 47)
        {
            hasSymbol = true;
        }
        else if (isdigit(password[i]))
        {
            hasNumber = true;
        }
        else if (isupper(password[i]))
        {
            hasUpper = true;
        }
        else if (islower(password[i]))
        {
            hasLower = true;
        }
    }

    return (hasSymbol &&
            hasNumber &&
            hasUpper &&
            hasLower);
}

//! WITH ASCII//////////////////////////////////
//
// bool valid(string password)
// {
//     bool hasUpper = false;
//     bool hasLower = false;
//     bool hasNumber = false;
//     bool hasSymbol = false;

//     for (int i = 0, length = strlen(password); i < length; i++)
//     {
//         // printf("%c\n", password[i]);
//         if (password[i] >= 33 && password[i] <= 47)
//         {
//             hasSymbol = true;
//         }
//         else if (password[i] >= 48 && password[i] <= 57)
//         {
//             hasNumber = true;
//         }
//         else if (password[i] >= 65 && password[i] <= 90)
//         {
//             hasUpper = true;
//         }
//         else if (password[i] >= 97 && password[i] <= 122)
//         {
//             hasLower = true;
//         }
//     }
//     if (hasSymbol &&
//         hasNumber &&
//         hasUpper &&
//         hasLower)
//     {
//         return true;
//     }
//     return false;
// }
