/*
** EPITECH PROJECT, 2019
** modifymap.c
** File description:
** Modify the map after taking enemy signals
*/

#include "../include/navy.h"

int verif_line_col(char *map)
{
    if (map[2] != map[5] && map[3] != map[6])
        return (1);
    if (map[2] == map[5] && map[3] == map[6])
        return (1);
    return (0);
}

void first_display(char **my_map, char **enemy_map)
{
    my_putstr("my positions :\n");
    disp_map(my_map);
    my_putstr("\nenemy's position:\n");
    disp_map(enemy_map);
}

void modify_mymap(char **my_map)
{
    gbl.exit_cond = 0;
    if (is_num(my_map[1 + gbl.sign2][gbl.sign1 * 2]) == 1) {
        my_putstr("hit\n\n");
        my_map[1 + gbl.sign2][gbl.sign1 * 2] = 'x';
        kill(gbl.signalPid, SIGUSR2);
    } else {
        my_putstr("missed\n\n");
        my_map[1 + gbl.sign2][gbl.sign1 * 2] = 'o';
    }
    gbl = reset_gbl(gbl);
}

void modify_enemymap(char **enemy_map)
{
    if (gbl.is_hit)
        enemy_map[1 + gbl.sign2][gbl.sign1 * 2] = 'x';
    else
        enemy_map[1 + gbl.sign2][gbl.sign1 * 2] = 'o';
}