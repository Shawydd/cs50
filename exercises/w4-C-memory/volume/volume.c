// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

typedef uint8_t UBYTE;
typedef int16_t BYTTE;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        // Added to prevent memory leak
        fclose(input);
        return 1;
    }

    float factor = atof(argv[3]);
    // --------------------------------------------------------------------------------------------------------------------------------------
    // Copy header from input file to output file
    UBYTE *wav_header = malloc(HEADER_SIZE * sizeof(UBYTE));
    if (wav_header == NULL)
    {
        printf("Memory allocation failed for WAV header.\n");
        fclose(input);
        fclose(output);
        return 1;
    }

    // Read WAV header (44 bytes) from input
    if (!fread(wav_header, HEADER_SIZE, 1, input))
    {
        printf("Failed to read WAV header.\n");
        free(wav_header);
        fclose(input);
        fclose(output);
        return 1;
    }

    // Write WAV header to output file
    if (!fwrite(wav_header, HEADER_SIZE, 1, output))
    {
        printf("Failed to write WAV header.\n");
        free(wav_header);
        fclose(input);
        fclose(output);
        return 1;
    }

    free(wav_header);

    // Allocate memory for a single 16-bit sample
    BYTTE *post_header_content = malloc(sizeof(BYTTE));
    if (post_header_content == NULL)
    {
        printf("Memory allocation failed for WAV content.\n");
        fclose(input);
        fclose(output);
        return 1;
    }

    // Read, modify and write samples, by the given factor, one by one until EOF
    while (fread(post_header_content, sizeof(BYTTE), 1, input))
    {
        *post_header_content = (BYTTE) (*post_header_content * factor);

        if (!fwrite(post_header_content, sizeof(BYTTE), 1, output))
        {
            printf("Failed to write WAV content.\n");
            free(post_header_content);
            fclose(input);
            fclose(output);
            return 1;
        }
    }

    free(post_header_content);
    // --------------------------------------------------------------------------------------------------------------------------------------
    // Close files
    fclose(input);
    fclose(output);
}
