/*
** EPITECH PROJECT, 2023
** line
** File description:
** line
*/

#include "../include/lemin.h"

int compare_b(char* line, int b)
{
    if (my_strcmp(line, "##start") == 0) {
        b = 1;
    }
    if (my_strcmp(line, "##end") == 0) {
        b = 2;
    }
    return b;
}

int check_c(char* line)
{
    int c = 0;
    if (line[0] == '#') {
        c = 1;
    }
    return c;
}

int c_funct(char* line, int c, int i)
{
    if (c == 1) {
        int f = 0;
        while (line[i] != '\0' && f == 0) {
            f = c_funct2(line, i);
            i++;
        }
        if (f == 0) {
            return -1;
        }
    }
    return i;
}

void bucle_line(int i, char* line, anthill_t* anthill, int b)
{
    char *num = malloc(sizeof(char) * my_strlen(line));
    int counter = 0, j = 0;
    while (line[i] != '\0') {
        if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n') {
            num[j++] = line[i];
        } else {
            num[j] = '\0';
            save_num(num, anthill, counter, b);
            counter++;
            j = 0;
        }
        i++;
    }
    if (num[0] != '\0' && j > 0) {
        num[j] = '\0';
        save_num(num, anthill, counter, b);
    }
    free(num);
}

int study_line(char* line, anthill_t* anthill, int b)
{
    int i = 0, j = 0, counter = 0;
    int aux = compare_b(line, b);
    if (aux != b) {
        return aux;
    }
    int c = check_c(line);
    if (tunnels_study(line, anthill, c, i) == 0) {
        return 0;
    }
    i = c_funct(line, c, i);
    if (i == -1) {
        return 0;
    }
    bucle_line(i, line, anthill, b);
    return 0;
}
