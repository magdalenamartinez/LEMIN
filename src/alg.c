/*
** EPITECH PROJECT, 2023
** alg
** File description:
** ak
*/

#include "../include/lemin.h"


void algoritmo(anthill_t* ah, int end_id)
{
    int i = 0;
    int distances[ah->n_rooms];
    int visited[ah->n_rooms];
    for (i = 0; i < ah->n_rooms; i++) {
        distances[i] = 1000;
        visited[i] = 0;
    }
    distances[end_id] = 0;
    bool_alg(ah, end_id, distances, visited);
}

void bool_alg(anthill_t* ah, int end_id, int* distances, int* visited)
{
    int i = 0, j = 0;
    for (i = 0; i < ah->n_rooms - 1; i++) {
        ah->min_dis = 1000;
        ah->min_index = -1;
        bucle1(ah, visited, distances);
        visited[ah->min_index] = 1;
        bucle2(ah, visited, distances);
    }
    for (i = 0; i < ah->n_rooms; i++) {
        ah->rooms[i]->distance = distances[i];
    }
    simulation(ah, ah->start_id, ah->end_id);
}

int all_end(anthill_t* anthill, int *ant_positions)
{
    int i = 0;
    while (i < anthill->num_ants) {
        if (ant_positions[i] != anthill->end_id) {
            return 0;
        }
        i++;
    }
    return 1;
}

void bucle1(anthill_t* ah, int* vis, int *dis)
{
    for (int j = 0; j < ah->n_rooms; j++) {
        if (vis[j] != 1 && dis[j] <= ah->min_dis) {
            ah->min_dis = dis[j];
            ah->min_index = j;
        }
    }
}

void bucle2(anthill_t* ah, int* vis, int *dis)
{
    for (int j = 0; j < ah->rooms[ah->min_index]->num_tunnels; j++) {
        int tunnel_id = ah->rooms[ah->min_index]->tunnels_id[j];
        if (vis[tunnel_id] != 1 && dis[ah->min_index] != 1000 &&
        dis[ah->min_index] + 1 < dis[tunnel_id]) {
            dis[tunnel_id] = dis[ah->min_index] + 1;
        }
    }
}
