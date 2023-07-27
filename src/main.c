#include <stdio.h>
#include <constants.h>
#include <commandParser.h>

int main(int argc, char *argv[])
{
    int display_mode = 0;
    char *pbm_file_path = NULL;

    int result = parse_arguments(argc, argv, &display_mode, &pbm_file_path);

    switch (result)
    {
    case 0:
        printf("%s", pbm_file_path);
        break;
    case 1:
        printf("%s", "No arguments passed\n");
        break;
    case 2:
        printf("%s", "Error while parsing arguments\n");
        break;
    case 3:
        printf("%s", "Invalid display mode\n");
        break;
    case 4:
        printf("%s", "The file doesn't exist\n");
        break;
    case 5:
        printf("%s", "No file specified\n");
        break;
    }
    return 0;
}