#ifndef COMMANDPARSER_H
#define COMMANDPARSER_H

int is_valid_display_mode(const char *arg);

int parse_arguments(int argc, char *argv[], int *display_mode, char **pbm_file_path);

#endif