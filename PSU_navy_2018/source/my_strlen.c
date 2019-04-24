/*
** EPITECH PROJECT, 2018
** my_strlen.c
** File description:
** send the length of a str
*/

#include <stdio.h>

int my_strlen(char *str)
{
    int i = 0;

    for (i = 0; str[i] != '\0'; i++);
    return (i);
}