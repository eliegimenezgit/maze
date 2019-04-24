/*
** EPITECH PROJECT, 2018
** header.h
** File description:
** header file
*/

#ifndef MY_HEADER_
#define MY_HEADER_

#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/stat.h>
#include <fcntl.h>

typedef struct solv
{
    int x;
    int y;
    int psb;
    int pos;
} solv;

int main(int argc, char **argv);

int solver(char *maze, int x, int y);
int possib(char *maze, struct solv *v, char c);
void init_val(struct solv *val, int x, int y);
int move_with_psb(char *maze, struct solv *v, char c, char d);
int move_with_psb_reverse(char *maze, struct solv *v, char c, char d);

#endif /*MY_HEADER_*/
