/*
** EPITECH PROJECT, 2019
** playertwo.c
** File description:
** P2 navy
*/

#include "../include/navy.h"

void takingsignals(void)
{
    signal(SIGUSR1, handler);
    signal(SIGUSR2, handler);
    while (!gbl.exit_cond);
    while (gbl.exit_cond != 2);
    my_putstr("\n");
    my_putnbr_base(gbl.sign1, "AABCDEFGH");
    my_putnbr_base(gbl.sign2, "012345678");
    my_putstr(":  ");
}

int playertwo(char **my_map, char **enemy_map, int pid2)
{
    my_putstr("waiting for enemy's attack...");
    gbl = reset_gbl(gbl);
    takingsignals();
    modify_mymap(my_map);
    if (wincond(my_map)) {
        my_putstr("Enemy won\n");
        for (int i = 0; i < 100; i++)
            kill(pid2, SIGUSR2);
        return (1);
    }
    return (playerone(my_map, enemy_map, pid2));
}