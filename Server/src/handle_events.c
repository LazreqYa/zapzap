/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** handle_events
*/

#include "../../include/server.h"

void handle_events(server_t *info, game_t *game) {
    handle_clients(info, game);
    handle_commands(info);
}
