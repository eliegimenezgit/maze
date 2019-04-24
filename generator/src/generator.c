/*
** EPITECH PROJECT, 2019
** generator.c
** File description:
** gene
*/

#include "../header.h"

void set_val(struct maze *val, int x_max, int y_max, int eval)
{
    if (eval == 0) {
        val->x = 0;
        val->y = 0;
        val->x_max = x_max;
        val->y_max = y_max;
    }
    val->right = 0;
    val->down = 0;
    val->left = 0;
    val->up = 0;
}

int disp_maze(char **maze, int y_max)
{
    int i = 0;
    int j = 0;

    while (maze[i] != NULL)
    {
        while (maze[i][j] != '\0') {
            if (maze[i][j] == '\n' && i == y_max - 1) {
                return (0);
            } else
                printf("%c", maze[i][j]);
            j = j + 1;
        }
        j = 0;
        i = i + 1;
    }
    return (0);
}

void prepare(char **maze, int x_max, int y_max, struct maze *val)
{
    int i = 0;
    int j = 0;

    while (maze[i] != NULL) {
        if (i % 2 == 0) {
            while (maze[i][j] != '\n') {
                if (j % 2 == 0)
                    maze[i][j] = '.';
                j = j + 1;
            }
        }
        j = 0;
        i = i + 1;
    }
    maze[0][x_max - 1] = '.';
    maze[y_max - 1][0] = '.';
    maze[y_max - 1][x_max - 1] = '.';
    set_val(val, x_max, y_max, 0);
}

void generator(char **maze, int x_max, int y_max, int perfect)
{
    struct maze val;

    srand(time(NULL));
    prepare(maze, x_max, y_max, &val);
    while (rand_move(maze, &val) == 0) {
    }
    if (x_max % 2 == 0 || y_max % 2 == 0)
        join_maze(maze, &val);
    if (perfect == 0)
        add_passage(maze, &val);
    disp_maze(maze, y_max);
}
