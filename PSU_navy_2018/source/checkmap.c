/*
** EPITECH PROJECT, 2018
** checkmap.c
** File description:
** Checking the Navy's map
*/

#include "../include/navy.h"

int verif_length(char *line)
{
    if ((line[6] - line[3] + 1) == (line[0] - '0') ||
    - (line[6] - line[3] - 1) == (line[0] - '0')) {
        if (!((line[5] - line[2] + 1) == (line[0] - '0') ||
        - (line[5] - line[2] - 1) == (line[0] - '0')))
            return (0);
    }
    if ((line[5] - line[2] + 1) == (line[0] - '0') ||
    - (line[5] - line[2] - 1) == (line[0] - '0')) {
        if (!((line[6] - line[3] + 1) == (line[0] - '0') ||
        - (line[6] - line[3] - 1) == (line[0] - '0')))
            return (0);
    }
    return (1);
}

int is_num(char c)
{
    if (c >= '1' && c <= '9')
        return (1);
    return (0);
}

int is_alph(char c)
{
    if (c >= 'A' && c <= 'H')
        return (1);
    return (0);
}

int verif_map(char **map)
{
    int i = 0;

    for (; map[i]; i++) {
        if (my_strlen(map[i]) != 7 || number(map))
            return (1);
        if (!is_num(map[i][0]) || !is_num(map[i][3]) || !is_num(map[i][6]))
            return (1);
        if (!is_alph(map[i][2]) || !is_alph(map[i][5]))
            return (1);
        if (map[i][1] != ':' || map[i][4] != ':')
            return (1);
        if (map[i][0] < '2' || map[i][0] > '5')
            return (1);
        if (map[i][3] < '1' || map[i][3] > '8' ||
        map[i][6] < '1' || map[i][6] > '8')
            return (1);
        if (verif_length(map[i]) || verif_line_col(map[i]))
            return (1);
    }
    return (i == 4 ? 0 : 1);
}

char **check_map(int ac, char **av)
{
    int fd;
    char *str;
    char **map;

    if (ac == 3)
        fd = open(av[2], O_RDONLY);
    else
        fd = open(av[1], O_RDONLY);
    if (fd == -1)
        return (NULL);
    str = malloc(sizeof(char) * 35);
    for (int i = 0; i < 35; i++)
        str[i] = 0;
    read(fd, str, 34);
    map = my_str_to_tab(str, '\n');
    if (verif_map(map))
        map[0] = NULL;
    return (map);
}