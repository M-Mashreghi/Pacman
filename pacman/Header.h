#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <ctime>
#include <conio.h>



#define up 72                      //move via arrow key
#define down 80
#define left 75
#define  right 77



int _Inky_length_pacman(int** co);

void _Inky_move_AI(int** co, char** map);

void _Clyde_moves_random_(int** co, char** map);

void _Pinky_moves_random_(int** co, char** map);


void _Inky_moves_random_(int** co, char** map);


void _Blinky_moves_random_(int** co, char** map);




int _Pinky_length_pacman(int** co);
void _Pinky_move_AI(int** co, char** map);





int _Blinky_length_pacman(int** co);
void _Blinky_move_AI(int** co, char** map);

int _Clyde_length_pacman(int** co);
void _Clyde_move_AI(int** co, char** map);




int _Inky_length_pacman(int** co);
void _Inky_move_AI(int** co, char** map);






void _move_right_(char** map, int** co, int* score, int* t);
void _move_left_(char** map, int** co, int* score, int* t);
void _move_up_(char** map, int** co, int* score, int* t);
void _move_down_(char** map, int** co, int* score, int* t);

void _printing_finall_(char bord[20][22], char bakht[20][22], int score, int** co);
int _play_again_();
void _reasone_of_lose_(int** co);
void _print_table_(char finall[20][22]);
void _installing_ghost_and_pacman_coordinate_(char** map, int** co, int score);
int _select_mode_();
void _installing_selected_map(char** map, char map1[20][20], char map2[20][20], char map3[20][20], int selected_map);
void _print_map_(char map[20][20]);
int _select_map_menu_(char map1[20][20], char map2[20][20], char map3[20][20]);

void _print_map_and_details(char** map1, int score, int** co);
