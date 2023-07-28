#include <string.h>
#include <stdio.h>
#include <constants.h>
#include <stdlib.h>

void get_img_dimensions(char line[255], int *row, int *col)
{
    char *separator = " ";
    char *token;
    char str_row[10];
    char str_col[10];

    token = strtok(line, separator);
    strcpy(str_row, token);
    token = strtok(NULL, separator);
    strcpy(str_col, token);

    *row = atoi(str_row);
    *col = atoi(str_col);
}

void display_image(char *pbm_file_path)
{
    system("clear");
    FILE *file;
    char line[255];
    int row;
    int col;

    file = fopen(pbm_file_path, "r");

    for (int i = 0; i < 3; i++)
        fgets(line, 255, file);

    get_img_dimensions(line, &row, &col);

    for (int i = 0; i < row; i++)
    {
        fgets(line, 255, file);

        for (int j = 0; j < col * 2; j++)
        {
            if (line[j] == '1')
                printf("\xE2\x96\xA0");
            else
                printf(" ");
        }
        printf("\n");
    }
}