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
#include <math.h>

// ...

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp_image[height][width];

    const int cube_lower_cap = -1, cube_upper_cap = 1;
    const int sobel_x[] = {-1, 0, 1, -2, 0, 2, -1, 0, 1};
    const int sobel_y[] = {-1, -2, -1, 0, 0, 0, 1, 2, 1};

    const int rgb_limit_value = 255;

    // Iterate over each pixel
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int gx_rgb[] = {0, 0, 0};
            int gy_rgb[] = {0, 0, 0};

            // Iterate over 3x3 pixel grid around current pixel
            for (int k = cube_lower_cap, kernel_index = 0; k <= cube_upper_cap; k++)
                for (int l = cube_lower_cap; l <= cube_upper_cap; l++, kernel_index++)
                {
                    int iindex = i + k;
                    int jindex = j + l;

                    // Check valid pixel coordinates inside image bounds
                    if (iindex >= 0 && iindex < height && jindex >= 0 && jindex < width)
                    {
                        // Salva una volta sola i valori RGB convertiti in int
                        int red = (int) image[iindex][jindex].rgbtRed;
                        int green = (int) image[iindex][jindex].rgbtGreen;
                        int blue = (int) image[iindex][jindex].rgbtBlue;

                        // Usa le variabili temporanee nel calcolo, senza fare cast ripetuti
                        gx_rgb[0] += red * sobel_x[kernel_index];
                        gx_rgb[1] += green * sobel_x[kernel_index];
                        gx_rgb[2] += blue * sobel_x[kernel_index];

                        gy_rgb[0] += red * sobel_y[kernel_index];
                        gy_rgb[1] += green * sobel_y[kernel_index];
                        gy_rgb[2] += blue * sobel_y[kernel_index];
                    }
                }

            int gs_length = sizeof(gx_rgb) / sizeof(gx_rgb[0]);

            int sobel_square_root_rgb[gs_length];

            for (int k = 0; k < gs_length; k++)
            {
                int temp_value_square = gx_rgb[k] * gx_rgb[k] + gy_rgb[k] * gy_rgb[k];
                int temp_sqrt = (int) (sqrt(temp_value_square) + 0.5);

                sobel_square_root_rgb[k] =
                    temp_sqrt > rgb_limit_value ? rgb_limit_value : temp_sqrt;
            }

            temp_image[i][j].rgbtRed = (BYTE) (sobel_square_root_rgb[0]);
            temp_image[i][j].rgbtGreen = (BYTE) (sobel_square_root_rgb[1]);
            temp_image[i][j].rgbtBlue = (BYTE) (sobel_square_root_rgb[2]);
        }
    }

    // Copy blurred pixels back to original image
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            image[i][j] = temp_image[i][j];

    return;
}