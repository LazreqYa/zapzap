/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** count_elements_arr
*/

#include <stdlib.h>

int count_elements_array(char **arr)
{
    int nb_elements;

    for (nb_elements = 0; arr[nb_elements] != NULL; nb_elements++);
    return nb_elements;
}
