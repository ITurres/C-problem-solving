#include <cs50.h>
#include <stdio.h>

int getHeight(void);
void drawPyramid(int);

int main(void)
{
    int pyramidHeight = getHeight();
    drawPyramid(pyramidHeight);
}

int getHeight(void)
{
    int height;
    do
    {
        height = get_int("Height:\n");
    } while (height < 1 || height > 8);
    return height;
}

void drawPyramid(int height)
{
    for (int row = 0; row < height; row++)
    {
        for (int leftSpace = height - 1; leftSpace > row; leftSpace--)
        {
            printf(" ");
        }
        for (int leftHashes = height + 1; leftHashes > height - row; leftHashes--)
        {
            printf("#");
        }
        for (int middle = 0; middle < 2; middle++)
        {
            printf(" ");
        }
        for (int rightHashes = height + 1; rightHashes > height - row; rightHashes--)
        {
            printf("#");
        }
        printf("\n");
    }
}
