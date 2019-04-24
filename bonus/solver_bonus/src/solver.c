/*
** EPITECH PROJECT, 2019
** solver.c
** File description:
** solver
*/

#include "../include/header.h"

void modif_maze(char *maze, struct solv *v)
{
    int i = 0;

    while (maze[i] != '\0') {
        if (maze[i] == 'o')
            maze[i] = '*';
        if (maze[i] == '.')
            maze[i] = '*';
        if (maze[i] == 'a')
            maze[i] = 'o';
        if (maze[i] == '0')
            maze[i] = '*';
        i = i + 1;
    }
    maze[(v->x * v->y) - 2] = 'o';
    maze[0] = 'o';
}

void disp_color(char *maze, int i, int nb)
{
    while (maze[i] != '\0') {
        if (maze[i] == '0') {
            printf("\033[41m%c\033[0m" , ' ');
        } else if (maze[i] == '.' || maze[i] == 'o') {
            if (nb == 0)
                printf("\033[44m%c\033[0m", ' ');
            else
                printf("\033[42m%c\033[0m", ' ');
        } else {
            if (maze[i] == 'X')
                printf("\033[40m%c\033[0m" , ' ');
            else if (maze[i] == '*') {
                printf("\033[47m%c\033[0m" , ' ');
            } else
                printf("%c" , maze[i]);
        }
        i = i + 1;
    }
    usleep(14000);
}

void disp_maze(char *maze, int y, int nb)
{
    int i = 0;

    while ((y = y + 1) != 50) {
        printf("\n");
    }
    disp_color(maze , i, nb);
}

void verif(char *maze, struct solv *v)
{
    v->pos = 0;
    v->psb = 0;
    if (maze[(v->x * v->y)-2] == '.') {
        while (maze[(v->x * v->y)-2] == '.') {
            v->pos = move_with_psb(maze, v, '.', 'a');
        }
    } else {
        while (v->pos != (v->x * v->y) - 3) {
            v->pos = move_with_psb(maze, v, '.', 'a');
            maze[v->pos] = 'a';
        }
    }
}

int solver(char *maze, int x , int y)
{
    struct solv val;

    init_val(&val, x, y);
    while (maze[(val.x * val.y) - 2] == '*') {
        if ((val.psb = possib(maze, &val, '*')) != 0) {
            val.pos = move_with_psb(maze, &val, '*', 'o');
        } else if ((val.psb = possib(maze, &val, 'o')) != 0) {
            val.pos = move_with_psb_reverse(maze, &val, 'o', '0');
        } else {
            return (84);
        } disp_maze(maze, y, 0);
    }
    while (val.pos != 1 && val.pos != val.x) {
        val.pos = move_with_psb_reverse(maze, &val, 'o', '.');
        maze[val.pos] = '.';
    } disp_maze(maze, y, 0);
    verif(maze, &val);
    modif_maze(maze, &val);
    disp_maze(maze, y, 1);
    return (0);
}
