/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** map
*/

#include "../../include/server.h"

static void position_resources(map_infos_t *mp, map_t **map, int *index,
int i) {
    for (int j = 0; j < mp->rows; j++) {
        switch (mp->res_array[(*index)]) {
            case 1: map[i][j].res->food++; break;
            case 2: map[i][j].res->sibur++; break;
            case 3: map[i][j].res->phiras++; break;
            case 4: map[i][j].res->mendiane++; break;
            case 5: map[i][j].res->linemate++; break;
            case 6: map[i][j].res->thystame++; break;
            case 7: map[i][j].res->deraumere++; break;
        }
        (*index)++;
    }
}

static void distribute_resources(map_t **map, map_infos_t *mp)
{
    int i = 0;
    int index = 0;

    while(index < mp->total_res) {
        position_resources(mp, map, &index, i);
        i = (i + 1) % mp->rows;
    }
}

static void shuffle_map_resources(map_infos_t *mp)
{
    int index = 0;
    srand(time(NULL));
    ADD_RESOURCES(mp->res_array, mp->res_d.food, 1, index);
    ADD_RESOURCES(mp->res_array, mp->res_d.sibur, 2, index);
    ADD_RESOURCES(mp->res_array, mp->res_d.phiras, 3, index);
    ADD_RESOURCES(mp->res_array, mp->res_d.mendiane, 4, index);
    ADD_RESOURCES(mp->res_array, mp->res_d.linemate, 5, index);
    ADD_RESOURCES(mp->res_array, mp->res_d.thystame, 6, index);
    ADD_RESOURCES(mp->res_array, mp->res_d.deraumere, 7, index);
    for (int i = mp->total_res - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = mp->res_array[i];
        mp->res_array[i] = mp->res_array[j];
        mp->res_array[j] = temp;
    }
}

static void map_resource_setup_calculation(
    map_t ***map, map_infos_t **mp, int x, int y)
{
    int nbr_box = x * y;

    (*mp)->res_array = malloc(sizeof(int) * nbr_box + 1);
    (*mp)->cols = x;
    (*mp)->rows = y;
    SET_RESOURCES(mp);
    shuffle_map_resources(*mp);
    distribute_resources(*map, *mp);
}

static void map_init(game_t *game, int x, int y)
{
    game->mp = malloc(sizeof(map_infos_t));
    game->mp->map = malloc(y * sizeof(map_t*));
    for (int i = 0; i < y; i++) {
        game->mp->map[i] = malloc(sizeof(map_t) * x);
        for (int j = 0; j < x; j++) {
            game->mp->map[i][j].res = malloc(sizeof(resources_t));
            INIT_RESOURCES(game->mp);
        }
    }
}

void map_setup(game_t *game)
{
    int x = 10; // * col setup avec les params
    int y = 10; // * row setup avec les params

    map_init(game, x, y);
    map_resource_setup_calculation(&game->mp->map, &game->mp, x, y);

    /* DEBUG */
    // display_array_map(game->mp->map, x, y);
}
