/*
** EPITECH PROJECT, 2018
** navy.h
** File description:
** header for Navy
*/



#ifndef NAVY
#define NAVY

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <ucontext.h>
#include "get_next_line.h"

typedef struct global_s {
    int signalPid;
    int sign1;
    int sign2;
    int exit_cond;
    int is_hit;
    int win;
} global_t;

global_t gbl;

// program from lib
int my_strcmp(char const *s1, char const *s2);
int my_putstr(char *str);
void my_put_err(char *str);
int my_strlen(char *str);
int my_putnbr_base(int nb, char *base);
int my_putnbr_base_error(int nb, char *base);
void putchar_err(char c);
void my_putchar(char c);
char **my_str_to_tab(char *str, char sep);
int my_getnbr(char const *str);
int ttyconnect(int ac, char **av, char **pos);
int my_str_isnum(char *str);
char *my_strcat(char *dest, char *src);
global_t reset_gbl(global_t gbl);
void putstr_nbr(char *str, int number);

// getnextline
char *my_strcat(char *dest, char *src);
char *get_next_line(int fd);

// Checkmap.c
int is_num(char c);
int is_alph(char c);
int verif_map(char **map);
char **check_map(int ac, char **av);
char **column(char **map, char **pos, int i);
char **line(char **map, char **pos, int i);
char *swap(char *str, int index_1, int index_2);
int number(char **map);
int verif_line_col(char *map);

//Map Gesture
char **create_map(void);
void disp_map(char **map);
char **setmap(char **map, char **pos);
void first_display(char **my_map, char **enemy_map);
int error_boat(void);

//Players turn
int playertwo(char **my_map, char **enemy_map, int signalPID);
int playerone(char **my_map, char **enemy_map, int signalPID);
void modify_mymap(char **my_map);
void handler(int i);
int wincond(char **my_map);

//modifymap.c
void modify_enemymap(char **enemy_map);

#endif /*   NAVY    */