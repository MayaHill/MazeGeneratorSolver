/*
** EPITECH PROJECT, 2020
** Sokoban
** File description:
** sokoban.h
*/

#include <time.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Window.h>
#include <math.h>
#include "my.h"
#include "framebuffer.h"

typedef enum {
    WALL,
    FLOOR,
    PLAYER
} my_type;

typedef enum {
    UP,
    DOWN,
    LEFT,
    RIGHT,
    IDLE
} state_t;

typedef struct var_s {
    int quit;
    int play;
    int reset;
} var_t;

typedef struct button_s {
    sfRectangleShape *rect;
    sfTexture *inactive;
    sfTexture *hover;
    sfSprite *sprite;
    void (*ptr)(var_t *var);
} button_t;

typedef struct buttons_s {
    button_t all[10];
    int size;
} buttons_t;

typedef struct tile_s {
    sfIntRect rect;
    sfTexture *texture;
    sfSprite *sprite;
    my_type type;
    sfVector2f pos;
} tile_t;

typedef struct player_s {
    tile_t p;
    sfVector2i coords;
    state_t state;
} player_t;

typedef struct map_s {
    tile_t tiles[10001];
    buttons_t buttons;
    var_t var;
    int size_t;
} map_t;

typedef struct bonus_s {
    int height;
    int width;
    sfVector2i max;
    player_t player;
    map_t tiles;
    map_t s_tiles;
    char **map;
    char **solved_map;
    coords_t dir_coords[4];
    coords_t coords;
    coords_t temp;
    path_t *path;
} bonus_t;

// Solver functions

void change_map(bonus_t *dante);

int check_map_error(bonus_t *dante, char *buff);

int find_end(bonus_t *d);

void solve_map(bonus_t *dante);

// CSFML functions

void reset_map_positions(bonus_t *d);

void add_tile(tile_t *tile, char type);

void update_player(bonus_t *d);

void destroy_array(char **array);

int end_loop(int status, char **map, char **dup_map);

void add_object(tile_t *object, char type);

void show_map(sfRenderWindow *win, map_t *map);

void destroy_map(map_t *map);

void analyse_events(window_t *win, bonus_t *d);

sfRenderWindow *create_window(void);

void destroy_window(window_t *win, bonus_t *dante);

sfText *create_text(sfText *text, sfVector2f pos, sfFont *font);

void draw_text(window_t *win, char *str);

void init_map(bonus_t *d, char **map, map_t *tiles);

void add_elem(map_t *tiles, char type, int x, int y);

int *get_index(char **map, char c);

char **duplicate_map(char **map);

int walkable(char c);

void move_player(bonus_t *dante, int x, int y);

void get_move_action(char c, char **dup_map, char **map);

char *read_file(char *filepath);

int my_strlen_array(char **array);

int print_help(void);

void init_tiles(bonus_t *dante);

void update_game(window_t *win, bonus_t *dante);

void update_window(window_t *win, bonus_t *dante);

void update_menu(window_t *win, bonus_t *dante);

// Buttons

void create_buttons_array(buttons_t *buttons);

void add_graphics(char *inactive, char *hover, button_t *button);

void add_button(buttons_t *buttons, sfVector2f pos, void (*ptr)(var_t *var));

void display_buttons(sfRenderWindow *window, buttons_t *obj_array, var_t var);

void destroy_buttons(buttons_t *obj_array);

// Button functions

void play_button(var_t *var);

void quit_button(var_t *var);

void back_button(var_t *var);

void switch_button(var_t *var);