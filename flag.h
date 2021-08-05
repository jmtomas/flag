#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define flag_init main

int argument_count;
char **arguments;
int docstring_count;
char **docstrings;
int flag_fail;

int flag_int(const char *flag_name, int default_value, const char *docstring) {
        int flag_name_length = strlen(flag_name);
        int docstring_length = strlen(docstring);
        char *new_docstring = malloc(flag_name_length + 4 + docstring_length);
        new_docstring[0] = '\t';
        memcpy(new_docstring + 1, flag_name, flag_name_length);
        new_docstring[flag_name_length + 1] = ' ';
        memcpy(new_docstring + flag_name_length + 2, docstring, docstring_length);
        new_docstring[flag_name_length + 3 + docstring_length] = '\0';
        docstrings[docstring_count] = new_docstring;
        docstring_count++;
        for (int i = 0; i < argument_count; i++) {
                if (strcmp(arguments[i], flag_name) == 0) {
                        if (i + 1 < argument_count) {
                                return atoi(arguments[i + 1]);
                        } else {
                                flag_fail = 1;
                        }
                }
        }
        if (flag_fail) {
                printf("Usage: %s [flags]\n", arguments[0]);
                puts("Available flags:");
                for (int j = 0; j < docstring_count; j++) {
                        printf("%s\n", docstrings[j]);
                }
                exit(1);
                return 0;
        } else {
                return default_value;
        }
}

int main_func();

int flag_init(int argc, char **argv) {
        argument_count = argc;
        arguments = argv;
        flag_fail = 0;
        docstring_count = 0;
        docstrings = malloc(argc * sizeof(char *));
        main_func(argc, argv);
}

#define main main_func
