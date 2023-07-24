#ifndef COMMANDPARSER_H
#define COMMANDPARSER_H

int is_valid_display_mode(char *arg);

int parse_arguments(int argc, char *argv[], char **pbm_file_path, int *display_mode, char **airplane_file_path);

#endif