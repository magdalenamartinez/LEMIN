/*
** EPITECH PROJECT, 2023
** sim
** File description:
** sim
*/

#include "../include/lemin.h"

int find_next(anthill_t* ah, int current_room, int end_room, int* ant_pos)
{
    int next_room = -1;
    rooms_t* act_room = ah->rooms[current_room];
    int n_tun = ah->rooms[current_room]->num_tunnels;
    int *tuns = ah->rooms[current_room]->tunnels_id;
    for (int i = 0; i < n_tun; i++) {
        int room = tuns[i];
        next_room = change_next(next_room, ah, room, ant_pos);
    }
    return next_room;
}

int change_next(int next_room, anthill_t* ah, int room, int* ant_pos)
{
    if (is_occupied(room, ant_pos, ah->num_ants, ah->end_id) == 0) {
        if (next_room == -1 || get_dis(ah, room) < get_dis(ah, next_room)) {
            next_room = room;
        }
    }
    return next_room;
}

int is_occupied(int room, int* ant_pos, int n_ants, int end)
{
    for (int i = 0; i < n_ants; i++) {
        if (ant_pos[i] == room && room != end) {
            return 1;
        }
    }
    return 0;
}

int get_dis(anthill_t* ah, int room)
{
    return ah->rooms[room]->distance;
}
