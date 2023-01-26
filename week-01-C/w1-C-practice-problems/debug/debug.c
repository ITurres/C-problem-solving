// Become familiar wih C syntax
// Learn to debug buggy code

// #include <cs50.h>// the "string" data type will only work with this include...
#include <stdio.h>

int main(void)
{
    // Ask for your name and where live
    string name = get_string("What is your name? ");
    string location = get_string("Where do you live? ");

    // Say hello
    printf("Hello, %s, from %s!\n", name, location);
}
