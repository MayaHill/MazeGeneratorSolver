/*
** EPITECH PROJECT, 2020
** Bonus_Dante_Star
** File description:
** read_file.c
*/

#include "../include/bonus_dante.h"

int print_help(void)
{
    printf("USAGE\n\t./solver map\n");
    printf("DESCRIPTION\n\tmap\tfile representing the labyrinthe,");
    printf("containing 'X' for walls and '*' for paths\n");
    printf("\t\tconstraints: the map must be rectangular");
    printf(" and can't be bigger than 100x100\n");
    return (0);
}

char *read_file(char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    struct stat s;
    char *buff;

    if (fd < 0)
        return (NULL);
    if (stat(filepath, &s) < 0)
        return (NULL);
    buff = malloc(s.st_size + 1);
    if (buff == NULL)
        return (NULL);
    buff[s.st_size] = 0;
    if (read(fd, buff, s.st_size) < 0)
        return (NULL);
    return (buff);
}

int main(int argc, char **argv)
{
    char *str = NULL;
    bonus_t dante;

    if (argc != 2)
        return (84);
    if (strcmp(argv[1], "-h") == 0)
        return (print_help());
    str = read_file(argv[1]);
    if (check_map_error(&dante, str) == 84)
        return (84);
    init_tiles(&dante);
    return (0);
}