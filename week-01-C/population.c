// #include <cs50.h> //will make get_int work!...
#include <math.h>
#include <stdio.h>

int getStartSize(void);
int getEndSize(int);
int yearsToTake(int, int);

int main(void)
{
    int startSize = getStartSize();
    // printf("your start size is %i\n", startSize);
    int endSize = getEndSize(startSize);
    // printf("your end size is %i\n", endSize);
    int yearsTaken = yearsToTake(startSize, endSize);
    printf("Years to take for population to grow to %i is %i years.\n", endSize, (int)round(yearsTaken));
}

int getStartSize(void)
{
    int x;
    do
    {
        x = get_int("Enter the starting population size\n");
    } while (x < 9); // it should be (x >= 9), but somehow that approach doesn't work...why?
    return x;
}

int getEndSize(int startSize)
{
    int y;
    do
    {
        y = get_int("Enter the end population size\n");
    } while (y < startSize); // again, here it should be (y >= startSize), but somehow that approach doesn't work...why?
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