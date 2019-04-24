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
        if (maze[i] == 'a')
            maze[i] = 'o';
        if (maze[i] == '.')
            maze[i] = '*';
        if (maze[i] == '0')
            maze[i] = '*';
        i = i + 1;
    }
    maze[(v->x * v->y) - 2] = 'o';
    maze[0] = 'o';
}

void verif(char *maze, struct solv *v)
{
    v->pos = 0;
    v->psb = 0;
    if (maze[(v->x * v->y) - 2] == '.') {
        while (maze[(v->x * v->y) - 2] == '.') {
            v->pos = move_with_psb(maze, v, '.', 'a');
        }
    } else {
        while (v->pos != (v->x * v->y) - 3) {
            v->pos = move_with_psb(maze, v, '.', 'a');
            maze[v->pos] = 'a';
        }
    }
}

void disp_maze(char *maze, int max)
{
    int i = 0;

    while (i != max - 1) {
        printf("%c", maze[i]);
        i = i + 1;
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
        }
    }
    while (val.pos != 1 && val.pos != val.x) {
        val.pos = move_with_psb_reverse(maze, &val, 'o', '.');
        maze[val.pos] = '.';
    }
    verif(maze, &val);
    modif_maze(maze, &val);
    disp_maze(maze, y*x);
    return (0);
}
