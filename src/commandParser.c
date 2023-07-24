#include <stdlib.h>
#include <constants.h>
#include <commandParser.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

const char *display_modes[] = {"--static", "-s", "--dynamic", "-d", "--interactive", "-i"};
char file_path[255];

int is_valid_display_mode(const char *arg)
{
    size_t num_modes = sizeof(display_modes) / sizeof(char *);

    for (size_t i = 0; i < num_modes; i++)
    {
        if (strcmp(arg, display_modes[i]) == 0)
        {
            return 1;
        }
    }
    return 0;
}

int parse_arguments(int argc, char *argv[], int *display_mode, char **pbm_file_name)
{
    *display_mode = 0;

    if (argc < 2)
        return 1;
    for (int i = 1; i < argc; i++)
    {
        if (argv[i][0] != '-')
            return 2;
        else
        {
            if (is_valid_display_mode(argv[1]) == 0)
                return 3;
            else
            {
                if (argc > 2)
                {
                    if (strcmp(argv[2], "--file") == 0 || strcmp(argv[2], "-f") == 0)
                    {
                        if (argc > 3)
                        {

                            *pbm_file_name = argv[3];

                            strcpy(file_path, ASSET_STATIC_PATH);
                            strcat(file_path, argv[3]);
                            strcat(file_path, ".pbm");

                            if (access(file_path, F_OK) == 0)
                            {
                                return 0;
                            }
                            else
                                return 4;
                        }
                        else
                            return 5;
                    }
                }
            }
        }
    }
    return 0;
}