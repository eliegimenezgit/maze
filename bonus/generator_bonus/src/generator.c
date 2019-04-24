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
    val->r = 0;
    val->down = 0;
    val->l = 0;
    val->up = 0;
}

void disp_maze(char **maze)
{
    int i = 0;
    int j = 0;

    while (maze[i] != NULL) {
        while (maze[i][j] != '\0') {
            if (maze[i][j] == '0') {
                printf("\033[41m%c\033[0m", ' ');
            } else if (maze[i][j] == '*') {
                printf("\033[47m%c\033[0m", ' ');
            } else {
                if (maze[i][j] == 'X')
                    printf("\033[40m%c\033[0m", ' ');
                else if (maze[i][j] == '.')
                    printf("\033[40m%c\033[0m", ' ');
                else
                    printf("%c" , maze[i][j]);
            } j = j + 1;
        } j = 0;
        i = i + 1;
    }
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

void disp_backspace(int nb)
{
    nb = 40 - nb;
    while (nb != 0) {
        printf("\n");
        nb = nb - 1;
    }
}

void generator(char **maze, int x_max, int y_max, int perfect)
{
    struct maze val;

    srand(time(NULL));
    prepare(maze, x_max, y_max, &val);
    while (rand_move(maze, &val) == 0) {
        disp_maze(maze);
        usleep(20000);
        disp_backspace(y_max);
    }
    if (x_max % 2 == 0 || y_max % 2 == 0)
        join_maze(maze, &val);
    if (perfect == 0)
        add_passage(maze, &val);
    disp_maze(maze);
}
