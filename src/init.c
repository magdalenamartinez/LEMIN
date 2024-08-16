/*
** EPITECH PROJECT, 2023
** init
** File description:
** init
*/

#include "../include/lemin.h"

anthill_t* init_anthill(void)
{
    anthill_t* new = malloc(sizeof(anthill_t));
    new->num_ants = 0;
    new->n_rooms = 0;
    new->start_id = -1;
    new->end_id = -1;
    new->rooms = NULL;
    return new;
}

rooms_t* init_room(void)
{
    rooms_t* new = malloc(sizeof(rooms_t));
    new->tunnels_id = NULL;
    new->num_tunnels = 0;
    new->distance = 0;
    new->name = NULL;
    new->end = 0;
    new->id = 0;
    new->start = 0;
    new->num_tunnels = 0;
    new->x = 0;
    new->y = 0;
    return new;
}

rooms_t* create_room(char* name)
{
    rooms_t* new_room = init_room();
    new_room->id = 0;
    int name_length = my_strlen(name) + 1;
    new_room->name = malloc(name_length * sizeof(char));
    for (int i = 0; i < name_length; i++) {
        new_room->name[i] = name[i];
    }
    new_room->name[name_length - 1] = '\0';
    return new_room;
}

void add_room(anthill_t* ah, rooms_t* new_room, int b)
{
    rooms_t** new_rooms = malloc((ah->n_rooms + 1) * sizeof(rooms_t*));
    for (int i = 0; i < ah->n_rooms; i++) {
        new_rooms[i] = ah->rooms[i];
    }
    free(ah->rooms);
    ah->rooms = new_rooms;

    ah->rooms[ah->n_rooms] = new_room;
    ah->n_rooms++;

    if (b == 1) {
        ah->start_id = ah->n_rooms - 1;
        new_room->start = 1;
    }
    if (b == 2) {
        ah->end_id = ah->n_rooms - 1;
        new_room->end = 1;
    }
}

void new_room(char* name, anthill_t* ah, int b)
{
    rooms_t* new_room = create_room(name);
    add_room(ah, new_room, b);
}
