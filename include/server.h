/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** server
*/

#ifndef SERVER_H_
    #define SERVER_H_
    #include "header.h"
    #include "map.h"
    #include <signal.h>

    #define MAX_FDS 1000

// typedef enum {
//     ALIVE,
//     DEAD,
//     INCANTATING,
//     MASTER_INCANTATING,
//     FORKING,
//     EGG,
//     UNAFFECTED
// } player_status_e;

typedef enum {
    N = 1,
    E = 2,
    S = 3,
    W = 4,
} orientation;

typedef struct coordinate_s {
    int x;
    int y;
} coordinate_t;

typedef struct player_s {
    int fd;
    char *team;
    int level;
    coordinate_t coord;
    resources_t inventory;
    // orientation orientation;
    // enum player_status status;
    struct player_s *next;
} player_t;

typedef struct game_s {
    map_infos_t *mp;
    player_t *player;
} game_t;

typedef struct server_s {
    fd_set rfds;
    fd_set wfds;
    int max_fd;
    int socket_desc;
    struct sockaddr_in serv_addr;
    int used_fds[MAX_FDS];
} server_t;

// const handle_command_t CMD[] = {
    // {"/help", help_command},
    // {"/login", login_command},
    // {"/logout", logout_command},
    // {"/users", users_command},
    // {"/user", user_command},
    // {"/send", send_command},
    // {"/messages", messages_command},
// };

/**
 * @brief Server function references 
 */
int run_server(char **params);
void handle_clients(server_t *info, game_t *game);
void map_setup(game_t *game);
void display_array_map(map_t **map, int x, int y);
void handle_events(server_t *info, game_t *game);
void handle_commands(server_t *info);

/**
 * @brief Map linked list setup references
 */
map_t *map_list(size_t x, size_t y);
void display_map(map_t *map);
void free_user_list(map_t **map);

/**
 * @brief Lib function references
 */
int count_elements_array(char **arr);
char **str_tok_word_array(char *str_not_parsed, const char *delim);
void display_array(char **arr);
int count_elements_array(char **arr);

// player_t *player_list(player_t **player, int fd);
player_t *player_list(player_t *player, int fd);

#endif /* !SERVER_H_ */
