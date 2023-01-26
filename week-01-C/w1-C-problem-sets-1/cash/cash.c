#include <cs50.h>
#include <stdio.h>

int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);
// int calculate_coins(int, int); //funtion to replace all calculate_"coin name" since it repeats same code pattern//

int main(void)
{
    int cents = get_cents();
    printf("Change owed is => %i\n", cents);

    int quarters = calculate_quarters(cents);
    cents = cents - quarters * 25;

    int dimes = calculate_dimes(cents);
    cents = cents - dimes * 10;

    int nickels = calculate_nickels(cents);
    cents = cents - nickels * 5;

    int pennies = calculate_pennies(cents);
    cents = cents - pennies * 1;

    int coins = quarters + dimes + nickels + pennies;

    printf("%i\n", coins);
}

int get_cents(void)
{
    int cents;
    do
    {
        cents = get_int("Change owed: ");
    } while (cents < 0);
    return cents;
}

int calculate_quarters(int cents)
{
    int quarter = 25;
    int quartersToHand = 0;
    while (cents >= quarter)
    {
        quartersToHand++;
        cents -= quarter;
    }
    return quartersToHand;
}

int calculate_dimes(int cents)
{
    int dime = 10;
    int dimesToHand = 0;
    while (cents >= dime)
    {
        dimesToHand++;
        cents -= dime;
    }
    return dimesToHand;
}

int calculate_nickels(int cents)
{
    int nickel = 5;
    int nickelsToHand = 0;
    while (cents >= nickel)
    {
        nickelsToHand++;
        cents -= nickel;
    }
    return nickelsToHand;
}

int calculate_pennies(int cents)
{
    int pennie = 1;
    int penniesToHand = 0;
    while (cents >= pennie)
    {
        penniesToHand++;
        cents -= pennie;
    }
    return penniesToHand;
}

//funtion to replace all calculate_"coin name" since it repeats same code pattern//
// int calculate_coins(int cents, int coinValue)
// {
//     int coinsToHand = 0;
//     while (cents >= coinValue)
//     {
//         coinsToHand++;
//         cents -= coinValue;
//     }
//     return coinsToHand;
// }