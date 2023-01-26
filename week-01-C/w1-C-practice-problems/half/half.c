// Calculate your half of a restaurant bill
// Data types, operations, type casting, return value

// #include <cs50.h>// the ""
#include <stdio.h>

float half(float bill, float tax, int tip);

int main(void)
{
    float bill_amount = get_float("Bill before tax and tip: ");
    float tax_percent = get_float("Sale Tax Percent: ");
    int tip_percent = get_int("Tip percent: ");

    printf("You will owe $%.2f each!\n", half(bill_amount, tax_percent, tip_percent));
}

// TODO: Complete the function
float half(float bill, float tax, int tip)
{
    return ((((bill + tax) * tip) / 100) * 4) / 2;
}

// Bill before tax and tip: 12.50
// Sale Tax Percent: 8.875
// Tip percent: 20
// You will owe $8.17 each!

// Bill before tax and tip: 23.50
// Sale Tax Percent: 7
// Tip percent: 15
// You will owe $14.46 each!

// Bill before tax and tip: 100
// Sale Tax Percent: 6.25
// Tip percent: 18
// You will owe $62.69 each!