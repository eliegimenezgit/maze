/*
** EPITECH PROJECT, 2019
** resolver
** File description:
** main.c
*/

#include "../include/header.h"

int maze_is_good(char *maze, int x, int y)
{
    int i = 0;

    while (maze[i] != '\0') {
        if (maze[i] != '*' && maze[i] != 'X' && maze[i] != '\n') {
            printf("Bad character in the maze\n");
            return (1);
        }
        i = i + 1;
    }
    if (maze[0] != '*') {
        printf("no start in the maze\n");
        return (1);
    }
    if (maze[(x * y) - 2] != '*') {
        printf("no arrival in the maze\n");
        return (1);
    }
    return (0);
}

int help(int nb)
{
    if (nb == 1) {
        printf("the maze is not rectangular\n");
        return (84);
    }
}

int read_maze(FILE *fp)
{
    char *maze = malloc(sizeof(char));
    char *line = NULL;
    size_t len = 0;
    int x = 0;
    int y = 0;
    int rd = 0;

    while ((rd = getline(&line, &len, fp)) != -1) {
        if (x == 0)
            x = rd;
        else if (rd != x)
            return (help(1));
        maze = strcat(maze, line);
        len = 0;
        y = y + 1;
    }
    if (maze_is_good(maze, x, y) == 0)
        return (solver(maze, x, y));
    else
        return (84);
}

int open_file(char *path)
{
    FILE *fp = 0;

    if ((fp = fopen(path, "r")) == NULL)
        return (84);
    else
        return (read_maze(fp));
    return (0);
}

int main(int argc, char **argv)
{
    if (argc == 2) {
        return (open_file(argv[1]));
    } else {
        return (84);
    }
    return (0);
}
