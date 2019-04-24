/*
** EPITECH PROJECT, 2018
** getnextline
** File description:
** getnextline
*/

#include "../include/navy.h"

char *my_strcat(char *dest, char *src)
{
    int i = 0;
    char *to_return;

    to_return = malloc(sizeof(char) * (my_strlen(dest) + my_strlen(src) + 2));
    if (to_return == NULL)
        return (NULL);
    for (; i < my_strlen(dest); i++)
        to_return[i] = dest[i];
    for (int j = 0; j < my_strlen(src); j++, i++)
        to_return[i] = src[j];
    to_return[i] = 0;
    return (to_return);
}

char *copy_end(char *src, char *dest, int end)
{
    int i = 0;

    for (; end < my_strlen(src); end++, i++)
        dest[i] = src[end];
    dest[i] = 0;
    return (dest);
}

char *bouclinf(char *s, char *save, int verif_second, int fd)
{
    int verif;
    char *second_s = malloc(sizeof(char) * (READ_SIZE + 1));

    if (second_s == NULL)
        return (NULL);
    while (1) {
        for (int i = 0; i < my_strlen(s); i++)
            if (s[i] == '\n') {
                save = copy_end(s, save, i + 1);
                s[i] = 0;
                return (s);
            }
        verif = read(fd, second_s, READ_SIZE);
        second_s[READ_SIZE] = 0;
        if (verif == 0 && verif_second != 0)
            return (s);
        if (verif < 0 || (verif == 0 && verif_second == 0))
            return (NULL);
        s = my_strcat(s, second_s);
    }
}

char *get_next_line(int fd)
{
    char *s = malloc(sizeof(char) * (READ_SIZE + 1));
    static char *save = NULL;
    int verif;
    int verif_second;

    if (s == NULL || fd == -1)
        return (NULL);
    for (int i = 0; i < READ_SIZE + 1; i++)
        s[i] = '\0';
    verif = read(fd, s, READ_SIZE);
    if (verif == -1)
        return (NULL);
    verif_second = verif;
    if (save == NULL) {
        save = malloc(sizeof(char) * (READ_SIZE + 1));
        save[0] = '\0';
    }
    if (save == NULL)
        return (NULL);
    return (bouclinf(my_strcat(save, s), save, verif_second, fd));
}