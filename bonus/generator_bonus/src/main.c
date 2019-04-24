/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main of generator
*/

#include "../header.h"

void alloc_maze(int x, int y, int perfect)
{
    char **maze = malloc(sizeof(char *)*y + 1);
    int i = 0;
    int j = 0;

    while (i != y) {
        maze[i] = malloc(sizeof(char)*x + 2);
        while (j != x) {
            maze[i][j] = 'X';
            j = j + 1;
        }
        maze[i][j] = '\n';
        j = 0;
        i = i + 1;
    }
    maze[i] = NULL;
    generator(maze, x, y, perfect);
}

int good_size(int x, int y)
{
    if (x < 3 || y < 3)
        return (1);
    else
        return (0);
}

int main(int argc, char **argv)
{
    if (argc == 3 || argc == 4) {
        if (good_size(atoi(argv[1]), atoi(argv[2])) == 0) {
            if (argc == 3)
                alloc_maze(atoi(argv[1]), atoi(argv[2]), 0);
            else {
                if (strcmp(argv[3], "[perfect]") == 0)
                    alloc_maze(atoi(argv[1]), atoi(argv[2]), 1);
                else
                    return (84);
            }
        } else
            return (84);
    } else
        return (84);
    return (0);
}
