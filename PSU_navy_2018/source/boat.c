/*
** EPITECH PROJECT, 2019
** boat.c
** File description:
** verification boat on the same place
*/

#include "../include/navy.h"

char **column(char **map, char **pos, int i)
{
    int dist;

    if (pos[i][5] - pos[i][2] < 0)
        pos[i] = swap(pos[i], 5, 2);
    dist = (pos[i][5] - pos[i][2]);
    for (int j = 2, a = 0; a <= dist; a++, j += 2) {
        if (is_num(map[pos[i][3] - '0' + 1][j + (pos[i][2] - 'A') * 2]))
            return (NULL);
        map[pos[i][3] - '0' + 1][j + (pos[i][2] - 'A') * 2] = pos[i][0];
    }
    return (map);
}

char **line(char **map, char **pos, int i)
{
    int dist;

    if (pos[i][6] - pos[i][3] < 0)
        pos[i] = swap(pos[i], 3, 6);
    dist = (pos[i][6] - pos[i][3]);
    for (int j = 2, a = 0; a <= dist; a++, j++){
        if (is_num(map[j + pos[i][3] - '1']\
        [(pos[i][2] - 'A' + 1) * 2]))
            return (NULL);
        map[j + pos[i][3] - '1'][(pos[i][2] - 'A' + 1) * 2] = pos[i][0];
    }
    return (map);
}

int number(char **map)
{
    for (int i = 0; map[i]; i++) {
        for (int j = i + 1; map[j]; j++) {
            if (map[i][0] == map[j][0])
                return (1);
        }
    }
    return (0);
}