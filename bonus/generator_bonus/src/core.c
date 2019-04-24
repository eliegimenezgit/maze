/*
** EPITECH PROJECT, 2019
** core.c
** File description:
** core of maze
*/

#include "../header.h"

void eval_posib(char **maze, struct maze *val, char c, int d)
{
    if (val->x < val->x_max - 2 && maze[val->y][val->x + d] == c) {
        val->r = 1;
    }
    if (val->x > 1 && maze[val->y][val->x - d] == c) {
        val->l = 1;
    }
    if (val->y < val->y_max - 2 && maze[val->y + d][val->x] == c) {
        val->down = 1;
    }
    if (val->y > 1 && maze[val->y - d][val->x] == c) {
        val->up = 1;
    }
}

void choise(int nb_posib, struct maze *val)
{
    if (val->r == 1) {
        if (nb_posib != 0)
            val->r = 0;
        nb_posib = nb_posib - 1;
    }
    if (val->l == 1) {
        if (nb_posib != 0)
            val->l = 0;
        nb_posib = nb_posib - 1;
    }
    if (val->down == 1) {
        if (nb_posib != 0)
            val->down = 0;
        nb_posib = nb_posib - 1;
    }
    if (val->up == 1) {
        if (nb_posib != 0)
            val->up = 0;
        nb_posib = nb_posib - 1;
    }
}

void write_the_move(char **maze, struct maze *val, char c)
{
    if (val->r == 1) {
        maze[val->y][val->x] = c;
        maze[val->y][val->x + 1] = c;
        val->x = val->x + 2;
    }
    if (val->l == 1) {
        maze[val->y][val->x] = c;
        maze[val->y][val->x - 1] = c;
        val->x = val->x - 2;
    }
    if (val->down == 1) {
        maze[val->y][val->x] = c;
        maze[val->y + 1][val->x] = c;
        val->y = val->y + 2;
    }
    if (val->up == 1) {
        maze[val->y][val->x] = c;
        maze[val->y - 1][val->x] = c;
        val->y = val->y - 2;
    }
}

void move_with_rand(char **maze, struct maze *val, char c)
{
    int nb_posib = val->r + val->l + val->up + val->down;

    nb_posib = rand() / (RAND_MAX / nb_posib);
    choise(nb_posib, val);
    write_the_move(maze, val, c);
    set_val(val, 0, 0, 1);
}

int rand_move(char **maze, struct maze *val)
{
    eval_posib(maze, val, '.', 2);
    if (val->r == 1 || val->l == 1 || val->up == 1 || val->down == 1) {
        move_with_rand(maze, val, '0');
    } else {
        eval_posib(maze, val, '0', 1);
        if (val->r == 1 || val->l == 1 || val->up == 1 || val->down == 1) {
            move_with_rand(maze, val, '*');
        } else {
            maze[val->y][val->x] = '*';
            return (1);
        }
    }
    return (0);
}
