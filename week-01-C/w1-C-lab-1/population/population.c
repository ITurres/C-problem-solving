// #include <cs50.h>
#include <math.h>
#include <stdio.h>

int getStartSize(void);
int getEndSize(int);
int yearsToTake(int, int);

int main(void)
{
    int startSize = getStartSize();
    int endSize = getEndSize(startSize);
    int yearsTaken = yearsToTake(startSize, endSize);
    // printf("Start size: %i\n", startSize);
    // printf("End size: %i\n", endSize);
    // printf("Years to take for population to grow to %i is %i years.\n", endSize, (int)round(yearsTaken));
    printf("Years: %i\n", (int)round(yearsTaken));
}

int getStartSize(void)
{
    int x;
    do
    {
        x = get_int("Enter the starting population size\n");
    } while (x < 9);
    return x;
}

int getEndSize(int startSize)
{
    int y;
    do
    {
        y = get_int("Enter the end population size\n");
    } while (y < startSize);
    return y;
}

int yearsToTake(int startSize, int endSize)
{
    int years = 0;
    while (startSize < endSize)
    {
        startSize = startSize + ((startSize / 3) - (startSize / 4));
        years++;
    }
    return years;
}