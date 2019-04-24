/*
** EPITECH PROJECT, 2018
** my_putstr.c
** File description:
** my_putstr.c
*/

#include "../include/navy.h"

int my_strlen(char *str);

void my_put_err(char *str)
{
    write(2, str, my_strlen(str));
}

int my_putstr(char *str)
{
    write(1, str, my_strlen(str));
    return (1);
}

void putstr_nbr(char *str, int number)
{
    my_putstr(str);
    my_putnbr_base(number, "0123456789");
    my_putchar('\n');
}