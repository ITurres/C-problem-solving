#include <math.h>
#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int average = 0;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            average = round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0);
            image[i][j].rgbtRed = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtBlue = average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int sepiaRed = 0;
    int sepiaGreen = 0;
    int sepiaBlue = 0;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            sepiaRed = round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue);
            sepiaGreen = round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue);
            sepiaBlue = round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue);

            (sepiaRed <= 255) ? (image[i][j].rgbtRed = sepiaRed) : (image[i][j].rgbtRed = 255);
            (sepiaGreen <= 255) ? (image[i][j].rgbtGreen = sepiaGreen) : (image[i][j].rgbtGreen = 255);
            (sepiaBlue <= 255) ? (image[i][j].rgbtBlue = sepiaBlue) : (image[i][j].rgbtBlue = 255);
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            temp = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE imageCopy[height][width];

    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            imageCopy[i][j] = image[i][j];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float red = 0;
            float green = 0;
            float blue = 0;
            int counter = 0;

            for (int x = -1; x < 2; x++)
            {
                for (int y = -1; y < 2; y++)
                {
                    if ((i + x < 0) || (i + x > height - 1) || (j + y < 0) || (j + y > width - 1))
                    {
                        continue;
                    }
                    red += imageCopy[i + x][j + y].rgbtRed;
                    green += imageCopy[i + x][j + y].rgbtGreen;
                    blue += imageCopy[i + x][j + y].rgbtBlue;
                    counter++;
                }
            }
            image[i][j].rgbtRed = round(red / counter);
            image[i][j].rgbtGreen = round(green / counter);
            image[i][j].rgbtBlue = round(blue / counter);
        }
    }
    return;
}
