/*
** EPITECH PROJECT, 2023
** tunel
** File description:
** tunel
*/

#include "../include/lemin.h"

int function_c(char* line, int i, int c)
{
    if (c != 1) {
        return i;
    }
    int f = 0;
    while (line[i] != '\0' && f == 0) {
        if (line[i] > 47 && line[i] < 59) {
            f = 1;
            break;
        }
        i++;
    }
    if (f == 0) {
        return -1;
    }
    return i;
}

void second_part(char* num1, char* num2, anthill_t* ah)
{
    int id1 = find_id(num1, ah);
    int id2 = find_id(num2, ah);
    if (id1 == -1 || id2 == -1) {
        return;
    }
    add_tunnel(id1, id2, ah);
    add_tunnel(id2, id1, ah);
}

void tunnels_function(char* line, anthill_t* ah, int c)
{
    int i = 0, j = 0;
    char num1[1024], num2[1024];
    i = function_c(line, i, c);
    if (i == -1) {
        return;
    }
    while (line[i] != '-' && line[i] != '\0') {
        num1[j++] = line[i++];
    }
    num1[j] = '\0';
    j = 0;
    if (line[i] == '-') {
        i++;
        while (line[i] != '\0') {
            num2[j++] = line[i++];
        }
        num2[j] = '\0';
    }
    second_part(num1, num2, ah);
}

void add_tunnel(int i, int value, anthill_t* ah)
{
    int a = sizeof(int) * (ah->rooms[i]->num_tunnels + 1);
    int* temp = malloc(a);
    for (int j = 0; j < ah->rooms[i]->num_tunnels; j++) {
        temp[j] = ah->rooms[i]->tunnels_id[j];
    }
    free(ah->rooms[i]->tunnels_id);
    ah->rooms[i]->tunnels_id = temp;
    ah->rooms[i]->tunnels_id[ah->rooms[i]->num_tunnels] = value;
    ah->rooms[i]->num_tunnels++;
}

int tunnels_study(char* line, anthill_t* anthill, int c, int i)
{
    while (line[i] != '\0') {
        if (line[i] == '-') {
            tunnels_function(line, anthill, c);
            return 0;
        }
        i++;
    }
    return 1;
}
