/*
** EPITECH PROJECT, 2020
** my.h
** File description:
** my.h
*/

#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdarg.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdbool.h>
#include <time.h>

typedef struct coords_s {
    int x;
    int y;
} coords_t;

typedef struct path_s {
    coords_t c;
    struct path_s *next;
} path_t;

char **my_str_to_word_array(char const *str, char *delim);

void push_back_path(path_t **paths, int x, int y);

void push_front_path(path_t **paths, coords_t *coords);

coords_t *pop_front_path(path_t **paths);

void destroy_paths(path_t **paths);