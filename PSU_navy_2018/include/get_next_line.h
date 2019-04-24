/*
** EPITECH PROJECT, 2018
** getnextline.h
** File description:
** header for getnextline
*/

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

#ifndef GET_NEXT_LINE
#   define GET_NEXT_LINE
    void my_putchar(char c);
    int my_putstr (char *str);
    int my_strlen(char *str);
    char *my_strcat(char *dest, char *src);
    char *my_strncpy(char *dest, char const *src, int n);

    #ifndef READ_SIZE
    #   define READ_SIZE (1)
    #endif /* READ_SIZE */
#endif /* GET_NEXT_LINE */