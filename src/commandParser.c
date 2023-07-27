#include <stdlib.h>
#include <constants.h>
#include <commandParser.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

const char *display_modes[] = {"--static", "-s", "--dynamic", "-d", "--interactive", "-i"};

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

int parse_arguments(int argc, char *argv[], int *display_mode, char **pbm_file_path)
{
    *display_mode = 0;

    if (argc < 2)
        return 1;
    if (argv[1][0] != '-')
        return 2;
    else
    {
        if (is_valid_display_mode(argv[1]) == 0)
            return 3;
        else
        {
            if (argc > 3)
            {
                if ((strcmp(argv[2], "--file") == 0 || strcmp(argv[2], "-f") == 0))
                {
                    {

                        *pbm_file_path = (char *)malloc(strlen(ASSET_STATIC_PATH) + strlen(argv[3]));

                        strcpy(*pbm_file_path, ASSET_STATIC_PATH);
                        strcat(*pbm_file_path, argv[3]);
                        strcat(*pbm_file_path, ".pbm");

                        if (access(*pbm_file_path, F_OK) == 0)
                            return 0;
                        else
                            return 4;
                    }
                }
                else
                    return 5;
            }
            else
                return 5;
        }
    }
    return 0;
}