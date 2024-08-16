/*
** EPITECH PROJECT, 2023
** sim
** File description:
** sim
*/

#include "../include/lemin.h"

void simulation(anthill_t* ah, int start_id, int end_id)
{
    int n_ants = ah->num_ants;
    int *ant_pos = malloc(sizeof(int) * n_ants);
    int *prev_pos = malloc(sizeof(int) * n_ants);
    for (int i = 0; i < n_ants; i++) {
        ant_pos[i] = start_id;
        prev_pos[i] = start_id;
    }
    my_printf("\n#moves\n");
    bucle_sim(ah, ant_pos, prev_pos);

}

void bucle_sim(anthill_t* ah, int* ant_pos, int* prev_pos)
{
    while (all_end(ah, ant_pos) == 0) {
        save_before(ant_pos, prev_pos, ah);
        move_ants(ah, ant_pos);
        print_ants_lap(ant_pos, ah->num_ants, ah, prev_pos);
        my_printf("\n");
    }
}

void print_ants_lap(int* ant_pos, int n_ants, anthill_t* ah, int* prev_pos)
{
    for (int i = 0; i < n_ants; i++) {
        if (ant_pos[i] != prev_pos[i]) {
            my_printf("P%i-", i + 1);
            my_printf("%s ", ah->rooms[ant_pos[i]]->name);
        }
    }
}

void save_before(int* ant_pos, int* prev_pos, anthill_t* ah)
{
    for (int i = 0; i < ah->num_ants; i++) {
        prev_pos[i] = ant_pos[i];
    }
}

void move_ants(anthill_t* ah, int* ant_pos)
{
    int end_room = ah->end_id;
    for (int i = 0; i < ah->num_ants; i++) {
        int act_room = ant_pos[i];
        if (act_room == end_room) {
            continue;
        }
        int next_room = find_next(ah, act_room, end_room, ant_pos);
        if (next_room != -1) {
            ant_pos[i] = next_room;
        }
    }
}
