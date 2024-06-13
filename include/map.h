/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** map
*/

#ifndef MAP_H_
    #define MAP_H_
    #include "header.h"
    #define INIT_RESOURCES(game) ({ \
        game->map[i][j].res->deraumere = 0; \
        game->map[i][j].res->food = 0;  \
        game->map[i][j].res->linemate = 0;  \
        game->map[i][j].res->mendiane = 0;  \
        game->map[i][j].res->phiras = 0;    \
        game->map[i][j].res->sibur = 0; \
        game->map[i][j].res->thystame = 0;  \
    })
    #define SET_RESOURCES(mp) ({  \
        (*mp)->res_d.food = nbr_box * 0.5;  \
        (*mp)->res_d.sibur = nbr_box * 0.1; \
        (*mp)->res_d.phiras = nbr_box * 0.08;   \
        (*mp)->res_d.mendiane = nbr_box * 0.1;  \
        (*mp)->res_d.linemate = nbr_box * 0.3;  \
        (*mp)->res_d.thystame = nbr_box * 0.05; \
        (*mp)->res_d.deraumere = nbr_box * 0.15;    \
        (*mp)->total_res = (*mp)->res_d.food + (*mp)->res_d.sibur + \
            (*mp)->res_d.phiras + (*mp)->res_d.mendiane +   \
            (*mp)->res_d.linemate + (*mp)->res_d.thystame + \
            (*mp)->res_d.deraumere; \
    })
    #define ADD_RESOURCES(resources, max_resources, res_id, index) ({   \
        for (int i = 0; i < max_resources; i++)    \
            resources[index++] = res_id; \
    })

typedef struct resources_s {
    int food;
    int linemate;
    int deraumere;
    int sibur;
    int mendiane;
    int phiras;
    int thystame;
} resources_t;

typedef struct map_s {
    size_t x;          // Position de la case col
    size_t y;          // Position de la case row
    resources_t *res;  // Ressource de la case
} map_t;

typedef struct map_infos_s {
    int cols;          // Total COl
    int rows;          // Total ROW 
    int total_res;     // Total des ressources
    int *res_array;
    map_t **map;       // Map  
    resources_t res_d; // Ressource density
} map_infos_t;

#endif /* !MAP_H_ */
