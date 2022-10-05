#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;

const int BLOCK_SIZE = 512;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("file does not exist\n");
        return 1;
    }

    BYTE buffer[BLOCK_SIZE];

    int count_image = 0;

    FILE *jpg = NULL;

    char filename[8];

    while (fread(buffer, sizeof(BYTE), BLOCK_SIZE, file) == BLOCK_SIZE)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {

            if (jpg == NULL)
            {
                sprintf(filename, "%03i.jpg", count_image);
            }

            if (jpg != NULL)
            {
                fclose(jpg);
                count_image++;
                sprintf(filename, "%03i.jpg", count_image);
            }

            jpg = fopen(filename, "w");
            fwrite(buffer, sizeof(BYTE), BLOCK_SIZE, jpg);
        }
        else if (jpg != NULL)
        {
            fwrite(buffer, sizeof(BYTE), BLOCK_SIZE, jpg);
        }

    }
    fclose(jpg);
    fclose(file);
    return 0;


}