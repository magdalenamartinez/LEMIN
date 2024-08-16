/*
** EPITECH PROJECT, 2023
** write
** File description:
** write
*/

#include "../include/lemin.h"

void write_content3(char* c, int i)
{
    int f = 0;
    my_printf("#tunnels");
    while (c[i] != '\0') {
        if (c[i] == '#' && (c[i + 1] != '#' && c[i - 1] != '#')) {
            i = if_function(c, i);
        } else {
            else_function(c, i, f);
            my_putchar(c[i]);
            f = 1;
        }
        i++;
    }
}

void else_function(char* content, int i, int f)
{
    if (f == 0) {
        if (content[i] != '\n') {
            my_printf("\n");
        }
    }
}

int if_function(char* content, int i)
{
    while (content[i] != '\n') {
        i++;
    }
    return i;
}

int get_k(char* content, int k)
{
    while (content[k] != '-') {
        k++;
    }
    while (content[k] != '\n') {
        k--;
    }
    return k;
}

int write_content2(int i, char* c)
{
    if (c[i] == '#' && (c[i + 1] != '#' && c[i - 1] != '#')) {
        while (c[i] != '\n') {
            i++;
        }
    } else {
        my_putchar(c[i]);
    }
    i++;
    return i;
}
