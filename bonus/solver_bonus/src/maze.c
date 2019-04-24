/*
** EPITECH PROJECT, 2019
** solver.c
** File description:
** solver
*/

#include "../include/header.h"

int possib(char *maze, struct solv *v, char c)
{
    int psb = 0;

    if (maze[v->pos + 1] == c) {
        psb = psb + 1;
    }
    if (((v->pos + v->x) < (v->x * v->y)) && maze[v->pos + v->x] == c) {
        psb = psb + 1;
    }
    if (((v->pos - 1) > 0) && maze[v->pos - 1] == c) {
        psb = psb + 1;
    }
    if (((v->pos - v->x) > 0) && maze[v->pos - v->x] == c) {
        psb = psb + 1;
    }
    return (psb);
}

void init_val(struct solv *val, int x, int y)
{
    val->x = x;
    val->y = y;
    val->psb = 0;
    val->pos = 0;
}

int move_with_psb(char *maze, struct solv *v, char c, char d)
{
    maze[v->pos] = d;
    if (maze[v->pos + 1] == c) {
        return (v->pos + 1);
    }
    if (((v->pos + v->x) < (v->x * v->y)) && maze[v->pos + v->x] == c) {
        return (v->pos + v->x);
    }
    if (((v->pos - 1) > 0) && maze[v->pos - 1] == c) {
        return (v->pos - 1);
    }
    if (((v->pos - v->x) > 0) && maze[v->pos - v->x] == c) {
        return (v->pos - v->x);
    }
}

int move_with_psb_reverse(char *maze, struct solv *v, char c, char d)
{
    maze[v->pos] = d;
    if (((v->pos - v->x) > 0) && maze[v->pos - v->x] == c) {
        return (v->pos - v->x);
    }
    if (((v->pos - 1) > 0) && maze[v->pos - 1] == c) {
        return (v->pos - 1);
    }
    if (((v->pos + v->x) < (v->x * v->y)) && maze[v->pos + v->x] == c) {
        return (v->pos + v->x);
    }
    if (maze[v->pos + 1] == c) {
        return (v->pos + 1);
    }
}