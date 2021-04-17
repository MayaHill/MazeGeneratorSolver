/*
** EPITECH PROJECT, 2020
** Dante Star
** File description:
** main.c
*/

#include "../include/my.h"

void free_map(dante_t *dante)
{
    for (int i = 0; dante->map[i]; i++)
        free(dante->map[i]);
    free(dante->map);
}

void delete_rand_block(dante_t *dante, int x)
{
    int n = 0;
    bool removed = false;
    int nb = rand() % (dante->width - 1);

    while (removed == false && n < 5) {
        if (dante->map[x][nb] == 'X') {
            dante->map[x][nb] = '*';
            removed = true;
        }
        nb = rand() % (dante->width - 1);
        n++;
    }
}

void print_final_map(dante_t *dante)
{
    if (dante->perfect == false)
        for (int x = 0; dante->map[x]; x++)
            delete_rand_block(dante, x);
    for (int i = 0; dante->map[i]; i++) {
        if (i != 0)
            printf("\n");
        printf("%s", dante->map[i]);
    }
    free_map(dante);
}

int main(int argc, char **argv)
{
    dante_t dante;

    if (check_errors(argc, argv) == 84)
        return (84);
    srand(time(0));
    dante.width = atoi(argv[1]);
    dante.height = atoi(argv[2]);
    if (dante.height <= 1 || dante.width <= 1)
        return (0);
    create_empty_gen_map(&dante);
    create_labyrinth(&dante);
    if (argc == 4 && strcmp(argv[3], "perfect") == 0)
        dante.perfect = true;
    else
        dante.perfect = false;
    print_final_map(&dante);
    return (0);
}