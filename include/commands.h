/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** commands
*/

#ifndef COMMANDS_H_
    #define COMMANDS_H_
    #include "header.h"
    #include "server.h"

    #define NEW_INPUT ((FD_ISSET(info->used_fds[i], &info->rfds) && \
    info->used_fds[i] > 0))

typedef struct handle_commands_s {
    const char *command;
    bool (*cmd)(char **, int *, server_t *);
} handle_command_t;

static const handle_command_t ALL_CMD[] = {
};

#endif /* !COMMANDS_H_ */
