/*
** EPITECH PROJECT, 2018
** my_strcmp
** File description:
** Task05Day06
*/

#include <unistd.h>

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;
    int same = 0;

    while ((s1[i] != '\0') && (s2[i] != '\0')) {
        if (s1[i] == s2[i])
            same++;
        i++;
    }
    return (same - i);
}
