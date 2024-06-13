/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** messages
*/

#ifndef MESSAGES_H_
    #define MESSAGES_H_
    #define MESS_SERVER_INIT_SUCCESS(port) ({printf(SERVER_INIT_MESS, port);})
    #define MESS_SERVER_NEW_FD_ADDED(fd) ({dprintf(fd, SERVER_NEW_FD_MESS);})
    #define MESS_SERVER_ACCEPT ({printf(SERVER_NEW_FD_MESS);})

static const char SERVER_INIT_MESS[] = "Server start on port [%s].\n";
static const char SERVER_NEW_FD_MESS[] = "Success.\n";
static const char SERVER_ACCEPT_MESS[] = "Error accept().\n";
#endif /* !MESSAGES_H_ */
