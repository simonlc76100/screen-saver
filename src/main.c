#include <stdlib.h>
#include <constants.h>
#include "commandParser.h"

int main(int argc, char *argv[])
{
    char *pbm_file_path = NULL;
    char *airplane_file_path = NULL;

    int display_mode = STATIC;

    int result = parse_arguments(argc, argv, &pbm_file_path, &display_mode, &airplane_file_path);

    if (result != 0)
    {
        printf("Error while parsing arguments\n");
        return -1;
    }

    return 0;
}