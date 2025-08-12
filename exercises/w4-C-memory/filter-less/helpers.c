/*
For a better understanding:

typedef uint8_t  BYTE;
typedef uint16_t WORD;

typedef struct
{
    BYTE  rgbtBlue;
    BYTE  rgbtGreen;
    BYTE  rgbtRed;
} __attribute__((__packed__))
RGBTRIPLE;

Other files are owned by CS50 course and weren't modified.
*/
#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    const BYTE rgb_avg = 3;

    // Iterate over each pixel
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
        {
            // Calculate average of RGB values with rounding
            const BYTE temp_value =
                (BYTE) ((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) /
                            ((float) rgb_avg) +
                        0.5);

            // Set all channels to average for grayscale
            image[i][j].rgbtBlue = temp_value;
            image[i][j].rgbtGreen = temp_value;
            image[i][j].rgbtRed = temp_value;
        }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    const BYTE rgb_limit_value = 255;

    // Iterate over each pixel
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
        {
            WORD sepiaValue = (WORD) ((.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen +
                                       .131 * image[i][j].rgbtBlue) +
                                      0.5);

            // Calculate sepia blue with rounding with 255 as limit
            BYTE sepiaBlue = (sepiaValue > rgb_limit_value) ? rgb_limit_value : (BYTE) sepiaValue;

            sepiaValue = (WORD) ((.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen +
                                  .168 * image[i][j].rgbtBlue) +
                                 0.5);

            // Calculate sepia green with rounding with 255 as limit
            BYTE sepiaGreen = (sepiaValue > rgb_limit_value) ? rgb_limit_value : (BYTE) sepiaValue;

            sepiaValue = (WORD) ((.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen +
                                  .189 * image[i][j].rgbtBlue) +
                                 0.5);

            // Calculate sepia red with rounding with 255 as limit
            BYTE sepiaRed = (sepiaValue > rgb_limit_value) ? rgb_limit_value : (BYTE) sepiaValue;

            // Assign new sepia values to pixel
            image[i][j].rgbtBlue = sepiaBlue;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtRed = sepiaRed;
        }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // Iterate over each row
    for (int i = 0; i < height; i++)
        // Swap pixels horizontally up to the midpoint
        for (int j = 0, half_width = width / 2; j < half_width; j++)
        {
            RGBTRIPLE pixel = image[i][j]; // temporary storage

            int symmetrical_position = width - j - 1;

            // Swap pixels from left to right
            image[i][j] = image[i][symmetrical_position];
            image[i][symmetrical_position] = pixel;
        }
    return;
}

// Blur image by averaging surrounding pixels
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp_image[height][width];

    const int cube_lower_cap = -1, cube_upper_cap = 1;

    // Iterate over each pixel
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            WORD tempBlue = 0;
            WORD tempGreen = 0;
            WORD tempRed = 0;

            BYTE counter = 0;

            // Iterate over 3x3 pixel grid around current pixel
            for (int k = cube_lower_cap; k <= cube_upper_cap; k++)
                for (int l = cube_lower_cap; l <= cube_upper_cap; l++)
                {
                    int iindex = i + k;
                    int jindex = j + l;

                    // Check valid pixel coordinates inside image bounds
                    if (iindex >= 0 && iindex < height && jindex >= 0 && jindex < width)
                    {
                        tempBlue += image[iindex][jindex].rgbtBlue;
                        tempGreen += image[iindex][jindex].rgbtGreen;
                        tempRed += image[iindex][jindex].rgbtRed;
                        counter++;
                    }
                }

            // Compute average color values with rounding
            temp_image[i][j].rgbtBlue = (BYTE) ((tempBlue / (float) counter) + 0.5);
            temp_image[i][j].rgbtGreen = (BYTE) ((tempGreen / (float) counter) + 0.5);
            temp_image[i][j].rgbtRed = (BYTE) ((tempRed / (float) counter) + 0.5);
        }
    }

    // Copy blurred pixels back to original image
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            image[i][j] = temp_image[i][j];

    return;
}
