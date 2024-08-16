/*
** EPITECH PROJECT, 2022
** include/my.h
** File description:
** funcion which
*/
#ifndef LEMIN_H_
    #define LEMIN_H_
    #include "my.h"
    #include <unistd.h>
    #include <stdio.h>
    #include <stdlib.h>
    #define BUFFER_SIZE 1024
    typedef struct rooms_st {
        char *name;
        int num_tunnels;
        int id;
        int* tunnels_id;
        int start;
        int end;
        int x;
        int y;
        int distance;
        int is_part_of_path;
    } rooms_t;
    typedef struct hormiguero {
        int num_ants;
        int ant_pos;
        int start_id;
        int end_id;
        int n_rooms;
        int** distances;
        int min_dis;
        int min_index;
        rooms_t **rooms;
    } anthill_t;
int c_funct2(char* line , int i);
int c_funct(char* line, int c, int i);
int check_c(char* line);
int compare_b(char* line, int b);
int study_tunnels(char* line, anthill_t* anthill, int c, int i);
void bucle_line(int i, char* line, anthill_t* anthill, int b);
int study_line(char* line, anthill_t* anthill, int b);
int tunnels_study(char* line, anthill_t* anthill, int c, int i);
    void write_content(char* content);
void write_content3(char* content, int i);
void else_function(char* content, int i, int f);
int if_function(char* content, int i);
int get_k(char* content, int k);
int function_c(char* line, int i, int c);
void second_part(char* num1, char* num2, anthill_t* ah);
void tunnels_function(char* line, anthill_t* ah, int c);
void add_tunnel(int i, int value, anthill_t *ah);
int find_id(char* name, anthill_t* ah);
int write_content2(int i, char* content);
    void bucle_sim(anthill_t* ah, int* ant_pos, int* prev_pos);
    void simulation(anthill_t* ah, int start_id, int end_id);
    void print_ants_lap(int* ant_pos, int n_ants, anthill_t* ah, int* prev_pos);
    void save_before(int* ant_pos, int* prev_pos, anthill_t* ah);
    void move_ants(anthill_t* ah, int* ant_pos);
    int find_next(anthill_t* ah, int current_room, int end_room, int* ant_pos);
    int change_next(int next_room, anthill_t* ah, int room, int* ant_pos);
    int is_occupied(int room, int* ant_pos, int n_ants, int end);
    int get_dis(anthill_t* ah, int room);
    int all_end(anthill_t* anthill, int *ant_positions);
    void algoritmo(anthill_t* ah, int end_id);
    void bool_alg(anthill_t* ah, int end_id, int* distances, int* visited);
    void bucle1(anthill_t* ah, int* vis, int *dis);
    void bucle2(anthill_t* ah, int* vis, int *dis);
    void tunnels_function(char* line, anthill_t* anthill, int c);
    int read_file(void);
    void new_room(char* name, anthill_t* ah, int b);
    void save_num(char* num, anthill_t* anthill, int counter, int b);
    int read_file2(ssize_t read_bytes, char* content, size_t longt);
    void study_content(char* buffer);
    int study_line(char* line, anthill_t* anthill, int b);
    void save_num(char* num, anthill_t* anthill, int counter, int b);
    int get_numants(char* buffer, anthill_t* anthill);
    void add_tunnel(int i, int value, anthill_t *ah);
    anthill_t* init_anthill(void);
#endif /* LEMIN_H_ */
