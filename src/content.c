/*
** EPITECH PROJECT, 2023
** cont
** File description:
** cont
*/

#include "../include/lemin.h"

void study_content(char* buffer)
{
    anthill_t* anthill = init_anthill();
    int i = 0, j = 0, b = 0;
    i = get_numants(buffer, anthill);
    char line[127];
    while (buffer[i] != '\0') {
        if (buffer[i] == '\n') {
            line[j] = '\0';
            j = 0;
            b = study_line(line, anthill, b);
        } else {
            line[j++] = buffer[i];
        }
        i++;
    }
    line[j] = buffer[i];
    study_line(line, anthill, 0);
    algoritmo(anthill, anthill->end_id);
}

int find_id(char* name, anthill_t* ah)
{
    int i = 0, found = -1;
    while (found == -1 && i < ah->n_rooms) {
        if (my_strcmp(name, ah->rooms[i]->name) == 0) {
            found = i;
            break;
        }
        i++;
    }
    return found;
}

void save_num(char* num, anthill_t* anthill, int counter, int b)
{
    switch (counter) {
        case 0:
            new_room(num, anthill, b);
            break;
        case 1:
            anthill->rooms[anthill->n_rooms - 1]->x = my_getnbr(num);
            break;
        case 2:
            anthill->rooms[anthill->n_rooms - 1]->y = my_getnbr(num);
            break;
        default:
            my_printf("Error saving data\n");
    }
}

int get_numants(char* buffer, anthill_t* anthill)
{
    int i = 0, j = 0;
    char num[1024];
    while (buffer[i] > 47 && buffer[i] < 58) {
        num[j++] = buffer[i++];
    }
    num[j] = '\0';
    anthill->num_ants = my_getnbr(num);
    return i;
}
