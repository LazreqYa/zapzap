/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** handle_client
*/

#include "../../include/server.h"
#include "../../include/messages.h"

static void add_to_used_fds(int new_socket, int *used_fds, game_t *game)
{
    for (int i = 0; i < MAX_FDS; i++) {
        if (used_fds[i] == 0) {
            used_fds[i] = new_socket;
            player_list(game->player, new_socket);
            MESS_SERVER_NEW_FD_ADDED(used_fds[i]);      // add the new user to list fd
            break;
        }
    }
}

static void accept_connection(int main_socket, int *used_fds,
    struct sockaddr_in *serv_addr, game_t *game)
{
    int size_address = sizeof(serv_addr);
    int new_socket = accept(main_socket, (struct sockaddr *)serv_addr,
            (socklen_t *)&size_address);
    if (new_socket > 0) {
        add_to_used_fds(new_socket, used_fds, game);
    } else {
        MESS_SERVER_ACCEPT;
    }
}

static bool incoming_connection(server_t *info, game_t *game) {
    if (FD_ISSET(info->socket_desc, &info->rfds)) {
        accept_connection(info->socket_desc, info->used_fds,
        &info->serv_addr, game);
        return true;
    }
    return false;
}

void handle_clients(server_t *info, game_t *game) {
    if (incoming_connection(info, game))
        return;
}
