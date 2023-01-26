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
        for (int toRight = height - 1; toRight > row; toRight--)
        {
            printf(" ");
        }
        for (int hashes = height + 1; hashes > height - row; hashes--)
        {
            printf("#");
        }
        printf("\n");
    }
}
