#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void convert_to_decimal(string);
void convert_to_binary(int);
void print_bulb(int);

int main(void)
{
    string message = get_string("Message to convert: ");
    convert_to_decimal(message);
}

void convert_to_decimal(string message)
{
    for (int i = 0, length = strlen(message); i < length; i++)
    {
        // printf("%i\n", (int)message[i]);
        convert_to_binary((int)message[i]);
    }
}

void convert_to_binary(int decimal)
{
    int bits = BITS_IN_BYTE; // create a copy of BITS_IN_BYTE since its a global constant (cant be change);
    int myBinary[BITS_IN_BYTE];
    int index = BITS_IN_BYTE - 1;
    while (bits > 0 || decimal > 0)
    {
        (decimal % 2 == 0) ? (myBinary[index] = 0) : (myBinary[index] = 1);
        decimal /= 2;
        bits--;
        index--; // so 0s && 1s are store in reverse (in the correct way);
    }

    for (int i = 0; i < BITS_IN_BYTE; i++)
    {
        // printf("%i", myBinary[i]);
        print_bulb(myBinary[i]);
    }
    printf("\n");
}

void print_bulb(int bit)
{
    (bit == 0) ? printf("\U000026AB") : printf("\U0001F7E1");
    //\U000026AB = lightEmoji
    //\U0001F7E1 = darkEmoji
}
