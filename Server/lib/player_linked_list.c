/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** player_linked_list
*/

#include "../../include/server.h"

void print_list(player_t *player);

static resources_t init_inventory(void)
{
    resources_t res;

    res.food = 1;
    res.deraumere = 2;
    res.linemate = 0;
    res.mendiane = 0;
    res.phiras = 0;
    res.sibur = 0;
    res.thystame = 0;
    return res;
}

static coordinate_t init_coordinates(void)
{
    coordinate_t coord;

    coord.x = 2;
    coord.y = 2;
    return coord;
}

static player_t *new_player_node(int fd)
{
    player_t *node = (player_t *)malloc(sizeof(player_t));

    if (node == NULL) {
        perror("Failed to allocate memory");
        return NULL;
    }
    node->fd = fd;
    node->level = 0;
    node->team = strdup("team1");
    node->coord = init_coordinates();
    node->inventory = init_inventory();
    node->next = NULL;
    return node;
}

player_t *player_list(player_t *player, int fd)
{
    player_t *new_node = new_player_node(fd);

    // print_list(new_node);
    if ((player) == NULL) {
        (player) = new_node;
    }
    // } else {
    //     player_t *tmp = (player);
    //     printf("BEFORE \n");
    //     if (tmp == NULL)
    //         printf("AFTER\n");
    //     while (tmp->next != NULL) {
    //         tmp = tmp->next;
    //     }
    //     tmp->next = new_node;
    // }
    return new_node;
}

void print_list(player_t *player) {
    player_t *tmp = player;
    int i = 0;

    while (tmp != NULL)
    {
        printf("USER %d -> [fd] = %d, [team] = %s, [level] = %d, [coord] = %d %d, [inventory] = %d %d\n", i, tmp->fd, tmp->team, tmp->level, tmp->coord.x, tmp->coord.y, tmp->inventory.food, tmp->inventory.deraumere);
        tmp = tmp->next;
    }
    
}

void free_player_list(player_t **player)
{
    player_t *tmp = NULL;

    while ((*player) != NULL) {
        tmp = (*player)->next;
        free(*player);
        (*player) = tmp;
    }
}