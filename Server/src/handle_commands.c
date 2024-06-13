/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** handle_commands
*/

#include "../../include/server.h"
#include "../../include/commands.h"
#include "../../include/zappy.h"

static void commands_management(char **args, int *client_fd, server_t *info)
{
    if (count_elements_array(args) == 0)
        return;
    for (size_t i = 0; i < sizeof(ALL_CMD) / sizeof(ALL_CMD[0]); i++) {
        if (strncmp(ALL_CMD[i].command, args[0],
        strlen(ALL_CMD[i].command)) == 0) {
            ALL_CMD[i].cmd(args + 1, client_fd, info);
            break;
        }
    }
}

static void trim_str(char *str)
{
    int len = strlen(str);
    bool outside_quotes = true;

    for (int i = 0; i < len; i++) {
        if (outside_quotes && str[i] == ' ')
            str[i] = '\t';
        if (str[i] == '"')
            outside_quotes = (!outside_quotes);
    }
}

static void format_input(int *client_fd, char ***args)
{
    char input[MAX_COMMAND_LENGTH];
    int len = read((*client_fd), input, MAX_COMMAND_LENGTH);

    input[len] = '\0';
    trim_str(input);
    (*args) = str_tok_word_array(input, "\"\t\n");
}

void handle_commands(server_t *info)
{
    char **args = NULL;

    for (int i = 0; i < MAX_FDS; i += 1) {
        if (NEW_INPUT) {
            format_input(&info->used_fds[i], &args);
            commands_management(args, &info->used_fds[i], info);
        }
    }
}
