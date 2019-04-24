/*
** EPITECH PROJECT, 2019
** printmap.c
** File description:
** print board
*/

#include "../include/navy.h"

char **create_map(void)
{
    int line = -1;
    char **map = malloc(sizeof(char *) * 11);

    for (int i = 0; i < 10; i++)
        map[i] = malloc(sizeof(char) * 19);
    for (; line <= 8; line++) {
        if (line == -1)
            map[line + 1] = " |A B C D E F G H\0";
        if (line == 0)
            map[line + 1] = "-+---------------\0";
        if (line > 0) {
            map[line + 1][0] = line + '0';
            map[line + 1][1] = 0;
            map[line + 1] = my_strcat(map[line + 1], "|. . . . . . . .\0");
        }
    }
    map[line + 1] = NULL;
    return (map);
}

void disp_map(char **map)
{
    for (int i = 0; map[i]; i++)
        my_putstr(my_strcat(map[i], "\n"));
    my_putchar('\n');
}

char *swap(char *str, int index_1, int index_2)
{
    char tmp = str[index_1];

    str[index_1] = str[index_2];
    str[index_2] = tmp;
    return (str);
}

char **setmap(char **map, char **pos)
{
    for (int i = 0; pos[i]; i++) {
        if (pos[i][3] - pos[i][6] == 0) {
            map = column(map, pos, i);
            if (map == NULL)
                return (NULL);
        } else {
            map = line(map, pos, i);
            if (map == NULL)
                return (NULL);
        }
    }
    return (map);
}

int error_boat(void)
{
    my_put_err("Error on map (2 boats at the same place)\n");
    return (84);
}