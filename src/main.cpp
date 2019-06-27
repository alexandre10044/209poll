/*
** EPITECH PROJECT, 2019
** Work
** File description:
** main
*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <math.h>
#include <iomanip>
#include <cmath>
#include <sys/time.h>
#include <vector>

bool check_possible_double_num(const char *str)
{
    bool allow = true;

    for (int i = 0; str[i]; i++)
        if ((str[i] <= '9' && str[i] >= '0') || str[i] == '.')
            continue;
        else {
            allow = false;
            break;
        }
    return (allow);
}

bool check_int_num(const char *str)
{
    bool allow = true;

    for (int i = 0; str[i]; i++)
        if ((str[i] <= '9' && str[i] >= '0'))
            continue;
        else {
            allow = false;
            break;
        }
    return (allow);
}

int main(int ac, char **av)
{
    if (ac >= 2 && (!strcmp(av[1], "-h") || !strcmp(av[1], "-help"))) {
        std::cout << "USAGE" << std::endl;
        std::cout << "\t" << av[0] << " pSize sSize p" << std::endl << std::endl;
        std::cout << "DESCRIPTION" << std::endl;
        std::cout << "\tpSize\tsize of the population" << std::endl;
        std::cout << "\tsSize\tsize of the sample (supposed to be representative)" << std::endl;
        std::cout << "\tp\tpercentage of voting intentions for a specific candidate" << std::endl;
        return (0);
    }
    if (ac != 4) {
        std::cerr << "Bad usage." << std::endl;
        return (84);
    }
    for (int i = 1; i < ac; i++)
        if (i < 3 && (!check_int_num(av[i]) || atof(av[i]) <= 0)) {
            std::cerr << "Bad usage." << std::endl;
            return (84);
        } else if (i == 3 && (!check_possible_double_num(av[i]) || atof(av[i]) <= 0)) {
            std::cerr << "Bad usage." << std::endl;
            return (84);
        }
    double sp = atof(av[1]);
    double ss = atof(av[2]);
    double purcent = atof(av[3]) / 100;
    double var = ((purcent * (1 - purcent)) / ss) * ((sp - ss) / (sp - 1));
    double pred_f = (2 * 1.96 * sqrt(var)) / 2 * 100;
    double pred_s = (2 * 2.58 * sqrt(var)) / 2 * 100;

    printf("Population size:\t %d\n", (int)sp);
    printf("Sample size:\t\t %d\n", (int)ss);
    printf("Voting intentions:\t %.2f%%\n", atof(av[3]));
    printf("Variance:\t\t %.6f\n", var);
    printf("95%% confidence interval: [");
    (purcent * 100 - pred_f) <= 0 ? printf("O%%") : printf("%0.2f%%", (purcent * 100 - pred_f));
    printf("; ");
    (purcent * 100 + pred_f) >= 100 ? printf("100%%") : printf("%0.2f%%", (purcent * 100 + pred_f));
    printf("]\n");
    printf("99%% confidence interval: [");
    (purcent * 100 - pred_s) <= 0 ? printf("O%%") : printf("%0.2f%%", (purcent * 100 - pred_s));
    printf("; ");
    (purcent * 100 + pred_s) >= 100 ? printf("100%%") : printf("%0.2f%%", (purcent * 100 + pred_s));
    printf("]\n");
    return (0);
}
