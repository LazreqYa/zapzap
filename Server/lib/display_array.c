/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** display_array
*/

#include <stdio.h>
#include "../../include/server.h"

void display_array(char **arr)
{
    int nb_elem = count_elements_array(arr);

    for (int i = 0; i < nb_elem; i++)
        printf("%d : %s\n", i, arr[i]);
}

void display_array_map(map_t **map, int x, int y)
{
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            printf("Line %d -> [%d] [%d] [%d] [%d] [%d] [%d] [%d]\n",
                j,
                map[i][j].res->food,
                map[i][j].res->deraumere,
                map[i][j].res->linemate,
                map[i][j].res->mendiane,
                map[i][j].res->phiras,
                map[i][j].res->sibur,
                map[i][j].res->thystame);
        }
    }
}
