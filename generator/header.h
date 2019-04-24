/*
** EPITECH PROJECT, 2018
** header.h
** File description:
** header file
*/

#ifndef MY_HEADER_
#define MY_HEADER_

#include <time.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/stat.h>
#include <fcntl.h>

typedef struct maze
{
    int up;
    int down;
    int right;
    int left;
    int x;
    int y;
    int x_max;
    int y_max;
} maze;

int main(int argc, char **argv);
void generator(char **maze, int x_max, int y_max, int perfect);
int rand_move(char **maze, struct maze *val);
void join_maze(char **maze, struct maze *val);
void add_passage(char **maze, struct maze *val);
void set_val(struct maze *val, int, int, int);

int my_getnbr(char const *str);

#endif /*MY_HEADER_*/
