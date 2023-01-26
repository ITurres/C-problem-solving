#include <cs50.h>
#include <ctype.h>
#include <stdio.h>

float calc_hours(int hours[], int weeks, char output);

int main(void)
{
    int weeks = get_int("Number of weeks taking CS50: ");
    int hours[weeks];

    for (int i = 0; i < weeks; i++)
    {
        hours[i] = get_int("Week %i HW Hours: ", i);
    }

    char output;
    do
    {
        output = toupper(get_char("Enter T for total hours, A for average hours per week: "));
    } while (output != 'T' && output != 'A');

    printf("%.1f hours\n", calc_hours(hours, weeks, output));
}

float calc_hours(int hours[], int weeks, char output)
{
    float total = 0;
    for (int i = 0; i < weeks; i++)
    {
        total += hours[i];
    }

    if (output == 'T')
    {
        return total;
    }
    else if (output == 'A')
    {
        return total / weeks;
    }
    return 0; //<= return 0 - otherwise error = "non-void function does not return a value in all control paths";
}