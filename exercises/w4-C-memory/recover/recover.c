#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

bool forensic_search(char *filename);

int main(int argc, char *argv[])
{
    // Check for correct command line usage
    if (argc != 2)
    {
        printf("USAGE: ./recover nameOfTheFile.extension\n");
        return 1;
    }

    // Start forensic search on the provided file
    if (forensic_search(argv[1]))
        return 1;

    return 0;
}

bool forensic_search(char *filename)
{
    typedef uint8_t UBYTE;
    typedef uint16_t UWORD;

    const UWORD JPEG_BLOCKS = 512; // Size of one block for JPEG recovery

    // Open file for reading raw data
    FILE *input = fopen(filename, "r");
    if (input == NULL)
    {
        printf("Could not open input file.\n");
        return true; // Return error if file cannot be opened
    }

    FILE *output = NULL; // Output file pointer for recovered images

    // Allocate memory buffer for one block of data
    UBYTE *buffer = malloc(JPEG_BLOCKS * sizeof(UBYTE));
    if (buffer == NULL)
    {
        printf("Memory allocation failed for the buffer.\n");
        fclose(input);
        return true;
    }

    int name_counter = 0;             // Counter for recovered file naming
    const size_t name_max_length = 8; // Buffer size for filename (e.g. 000.jpg + \0)
    char name[name_max_length];       // Filename buffer

    // Process the input file block by block until EOF
    while (fread(buffer, JPEG_BLOCKS, 1, input))
    {
        // Detect start of a new JPEG file by signature bytes
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff &&
            (buffer[3] >= 0xe0 && buffer[3] <= 0xef))
        {
            // Generate filename for new JPEG file (e.g. "000.jpg")
            snprintf(name, name_max_length, "%03d.jpg", name_counter);
            name_counter++;

            // Close previous output file if already open
            if (output != NULL)
                fclose(output);

            // Open new output file for writing recovered JPEG data
            output = fopen(name, "w");
            if (output == NULL)
            {
                printf("Could not open output file.\n");
                free(buffer);
                fclose(input);
                return true;
            }
        }

        // If output file is open, write current 512-byte block into it
        if (output != NULL)
        {
            if (!fwrite(buffer, JPEG_BLOCKS, 1, output))
            {
                // Handle write failure
                printf("Failed to write the file.\n");
                free(buffer);
                fclose(input);
                fclose(output);
                return true;
            }
        }
    }

    // Free allocated memory and close open files before exiting
    free(buffer);
    fclose(input);
    fclose(output);

    return false;
}
