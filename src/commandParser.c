#include <stdlib.h>
#include <constants.h>
#include <commandParser.h>
#include <stdio.h>
#include <string.h>

char *display_mode_args[] = {"--static", "-s", "--dynamic", "-d", "--interactive", "-i"};

int is_valid_display_mode(char *arg)
{
    size_t num_modes = sizeof(display_mode_args) / sizeof(char *);

    for (size_t i = 0; i < num_modes; i++)
    {
        if (strcmp(arg, display_mode_args[i]) == 0)
        {
            return 1;
        }
    }
    return 0;
}

int parse_arguments(int argc, char *argv[], char **pbm_file_path, int *display_mode, char **airplane_file_path)
{

    *pbm_file_path = NULL;
    *airplane_file_path = NULL;
    *display_mode = STATIC;

    for (int i = 1; i < argc; i++)
    {
        if (argv[i][0] != '-')
            return 1;
        else
        {
            if (strcmp(argv[i], "--static") == 0 || strcmp(argv[i], "-s") == 0)
                *display_mode = STATIC;
            else if (strcmp(argv[i], "--dynamic") == 0 || strcmp(argv[i], "-d") == 0)
                *display_mode = DYNAMIC;
            else if (strcmp(argv[i], "--interactive") == 0 || strcmp(argv[i], "-i") == 0)
                *display_mode = INTERACTIVE;
        }
    }
    return 0;
}