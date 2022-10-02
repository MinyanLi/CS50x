#include "helpers.h"
#include <math.h>
#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            int mean = round((image[h][w].rgbtBlue + image[h][w].rgbtGreen + image[h][w].rgbtRed) / 3.0);
            image[h][w].rgbtBlue = mean;
            image[h][w].rgbtGreen = mean;
            image[h][w].rgbtRed = mean;
        }
    }
    return;
}




// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width / 2; w++)
        {
            RGBTRIPLE tmp = image[h][w];
            image[h][w] = image[h][width - w - 1];
            image[h][width - w - 1] = tmp;
        }
    }
    return;
}



// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE tmp[height][width];
    int h, w, a, b;

    for (h = 0; h < height; h++)
    {
        for (w = 0; w < width; w++)
        {
            int total_red = 0;
            int total_green = 0;
            int total_blue = 0;
            float counter = 0.0;
            for (a = 0; a < 3; a++)
            {
                for (b = 0; b < 3; b++)
                {
                    if ((h + a - 1) < 0 || (w + b - 1) < 0 || (h + a - 1) > (height - 1) || (w + b - 1) > (width - 1))
                    {
                        continue;
                    }
                    total_red += image[h + a - 1][w + b - 1].rgbtRed;
                    total_green += image[h + a - 1][w + b - 1].rgbtGreen;
                    total_blue += image[h + a - 1][w + b - 1].rgbtBlue;
                    counter++;
                }
            }
            tmp[h][w].rgbtRed = round(total_red / counter);
            tmp[h][w].rgbtGreen = round(total_green / counter);
            tmp[h][w].rgbtBlue = round(total_blue / counter);
        }
    }

    for (h = 0; h < height; h++)
    {
        for (w = 0; w < width; w++)
        {
            image[h][w] = tmp[h][w];
        }
    }
    return;
}





// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE tmp[height + 2][width + 2];

    int h, w, tmph, tmpw;

    //make tmp1 circled with black pixels
    for (tmph = 0; tmph < height + 2; tmph++)
    {
        tmp[tmph][0].rgbtBlue = 0;
        tmp[tmph][0].rgbtGreen = 0;
        tmp[tmph][0].rgbtRed = 0;

        tmp[tmph][width + 1].rgbtBlue = 0;
        tmp[tmph][width + 1].rgbtGreen = 0;
        tmp[tmph][width + 1].rgbtRed = 0;
    }
    for (tmpw = 0; tmpw < width + 2; tmpw++)
    {
        tmp[0][tmpw].rgbtBlue = 0;
        tmp[0][tmpw].rgbtGreen = 0;
        tmp[0][tmpw].rgbtRed = 0;

        tmp[height + 1][tmpw].rgbtBlue = 0;
        tmp[height + 1][tmpw].rgbtGreen = 0;
        tmp[height + 1][tmpw].rgbtRed = 0;
    }
    // copy image to tmp1 center
    for (h = 0; h < height; h++)
    {
        for (w = 0; w < width; w++)
        {
            tmph = h + 1;
            tmpw = w + 1;
            tmp[tmph][tmpw] = image[h][w];
        }
    }
    // calculate tmp1 Gx Gy and put to image
    int Gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int Gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

    for (tmph = 1; tmph < height + 1; tmph++)
    {
        for (tmpw = 1; tmpw < width + 1; tmpw++)
        {
            int GxBlue = 0;
            int GxGreen = 0;
            int GxRed = 0;
            int GyBlue = 0;
            int GyGreen = 0;
            int GyRed = 0;
            for (int a = 0; a < 3; a++)
            {
                for (int b = 0; b < 3; b++)
                {
                    GxRed = GxRed + tmp[tmph + a - 1][tmpw + b - 1].rgbtRed * Gx[a][b];
                    GxGreen = GxGreen + tmp[tmph + a - 1][tmpw + b - 1].rgbtGreen * Gx[a][b];
                    GxBlue = GxBlue + tmp[tmph + a - 1][tmpw + b - 1].rgbtBlue * Gx[a][b];
                    GyRed = GyRed + tmp[tmph + a - 1][tmpw + b - 1].rgbtRed * Gy[a][b];
                    GyGreen = GyGreen + tmp[tmph + a - 1][tmpw + b - 1].rgbtGreen * Gy[a][b];
                    GyBlue = GyBlue + tmp[tmph + a - 1][tmpw + b - 1].rgbtBlue * Gy[a][b];
                }
            }

            int red = round(sqrt(pow(GxRed, 2) + pow(GyRed, 2)));
            int green = round(sqrt(pow(GxGreen, 2) + pow(GyGreen, 2)));
            int blue = round(sqrt(pow(GxBlue, 2) + pow(GyBlue, 2)));

            if (red > 255)
            {
                red = 255;
            }
            if (green > 255)
            {
                green = 255;
            }
            if (blue > 255)
            {
                blue = 255;
            }

            image[tmph - 1][tmpw - 1].rgbtRed = red;
            image[tmph - 1][tmpw - 1].rgbtGreen = green;
            image[tmph - 1][tmpw - 1].rgbtBlue = blue;
        }
    }

    return;
}


