/*
** EPITECH PROJECT, 2023
** main
** File description:
** main
*/

#include "../include/lemin.h"

int main(int argc, char** argv)
{
    if (argc > 1) {
        return ERROR_EXIT;
    }
    int r = 0;
    r = read_file();
    return r;
}
