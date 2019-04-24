/*
** EPITECH PROJECT, 2019
** ttyconnect.c
** File description:
** Connection between TTY 1 and 2
*/
#include "../include/navy.h"

void get_pid(int sig, siginfo_t *info, void *context)
{
    gbl.signalPid = info->si_pid;
    (void) sig;
    (void) context;
}

int ttypos1(void)
{
    int pid = getpid();
    struct sigaction act;

    my_putstr("my_pid: ");
    my_putnbr_base(pid, "0123456789");
    my_putstr("\n");
    act.sa_flags = SA_SIGINFO;
    act.sa_sigaction = get_pid;
    sigaction(SIGUSR1, &act, NULL);
    my_putstr("waiting for enemy connection...\n");
    pause();
    usleep(1000);
    kill(gbl.signalPid, SIGUSR2);
    my_putstr("\nenemy connected\n\n");
    return (gbl.signalPid);
}

int ttypos2(char **av)
{
    int enemyid = my_getnbr(av[1]);
    struct sigaction act;

    kill(enemyid, SIGUSR1);
    act.sa_flags = SA_SIGINFO;
    act.sa_sigaction = get_pid;
    sigaction(SIGUSR2, &act, NULL);
    usleep(10000);
    if (gbl.signalPid != enemyid) {
        my_put_err("Seems that you entered a wrong PID ");
        my_put_err("(No response with that PID).\nExiting...\n");
        return (84);
    }
    my_putstr("successfully connected\n\n");
    return (0);
}

int ttyconnect(int ac, char **av, char **pos)
{
    char **my_map = create_map();
    char **enemy_map = create_map();
    int pid2;

    my_map = setmap(my_map, pos);
    if (my_map == NULL)
        return (error_boat());
    if (ac == 2)
        pid2 = ttypos1();
    else if (ac == 3) {
        putstr_nbr("my_pid: ", getpid());
        if (ttypos2(av))
            return (84);
    }
    if (!my_getnbr(av[1]))
        return (playerone(my_map, enemy_map, pid2));
    else {
        first_display(my_map, enemy_map);
        return (playertwo(my_map, enemy_map, my_getnbr(av[1])));
    }
}