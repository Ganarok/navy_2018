/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main for the navy
*/

#include "include/navy.h"

int error_on_args(int ac)
{
    my_put_err("Error on argument(s).\n");
    my_putnbr_base_error(ac - 1, "0123456789");
    my_put_err(" argument(s) given when 1 (or 2 for the 2nd player)");
    my_put_err(" is (are) needed.\n");
    return (84);
}

int error_map(char **map)
{
    if (map == NULL)
        my_put_err("Map file cannot be accessed.\n");
    else
        my_put_err("Wrong format for the map.\n");
    return (84);
}

int usage(void)
{
    my_putstr("USAGE\n\t./navy [first_player_pid] navy_positions\n");
    my_putstr("DESCRIPTION\n\tfirst_player_pid:  only for the 2nd player. ");
    my_putstr("pid of the first player.\n\tnavy_positions:  ");
    my_putstr("file representing the positionsof the ships.\n");
    return (0);
}

global_t reset_gbl(global_t gbl)
{
    gbl.sign1 = 0;
    gbl.sign2 = 0;
    gbl.exit_cond = 0;
    gbl.is_hit = 0;
    return (gbl);
}

int main(int ac, char **av)
{
    char **map;

    gbl = reset_gbl(gbl);
    gbl.win = 0;
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == 0)
        return (usage());
    if (ac < 2 || ac > 3)
        return (error_on_args(ac));
    map = check_map(ac, av);
    if (map == NULL || map[0] == NULL)
        return (error_map(map));
    return (ttyconnect(ac, av, map));
}