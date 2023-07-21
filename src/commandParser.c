#include <stdlib.h>
#include <constants.h>
#include <commandParser.h>
#include <stdio.h>

int parse_arguments(int argc, char *argv[], char **pbm_file_path, int *display_mode, char **airplane_file_path)
{

    *pbm_file_path = NULL;
    *airplane_file_path = NULL;

    *display_mode = STATIC;

    for (int i = 0; i < argc; i++)
    {
        printf("%s", argv[i]);
    }

    return 0;
}
