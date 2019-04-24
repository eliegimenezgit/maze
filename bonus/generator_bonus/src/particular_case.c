/*
** EPITECH PROJECT, 2019
** cas particulier
** File description:
** pair maze
*/

#include "../header.h"

void join_maze(char **maze, struct maze *val)
{
    if (val->x_max % 2 == 0 && val->y_max % 2 == 0) {
        maze[0][val->x_max - 1] = '*';
        maze[val->y_max - 1][val->x_max - 1] = '*';
        maze[val->y_max - 1][0] = '*';
        maze[val->y_max - 1][val->x_max - 2] = '*';
    } else {
        if (val->x_max % 2 == 0) {
            maze[0][val->x_max - 1] = '*';
            maze[val->y_max - 1][val->x_max - 1] = '*';
        }
        if (val->y_max % 2 == 0) {
            maze[val->y_max - 1][0] = '*';
            maze[val->y_max - 1][val->x_max - 1] = '*';
        }
    }
}

void add_passage(char **maze, struct maze *val)
{
    int i = 0;
    int j = 0;
    int nb_rand = 0;

    while (maze[i] != NULL) {
        while (maze[i][j] != '\n') {
            if (maze[i][j] == 'X') {
                nb_rand = rand() / (RAND_MAX / (val->x_max - 1));
                if (nb_rand == 0)
                    maze[i][j] = '*';
            }
            j = j + 1;
        }
        j = 0;
        i = i + 1;
    }
}
