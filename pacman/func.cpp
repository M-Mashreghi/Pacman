#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <ctime>
#include <conio.h>
using namespace std;

inline void _print_map_(char** map)
{
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            cout << map[i][j];
        }
        cout << endl;
    }
}

inline void _print_map_(char map[20][20])
{
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            cout << map[i][j];
        }
        cout << endl;
    }
}

inline int _select_map_menu_(char map1[20][20], char map2[20][20], char map3[20][20])
{
    int selected_map;
    //Choosing a map
    cout << "Pls choose a map:" << endl << "1." << endl;
    _print_map_(map1);
    cout << "2." << endl;
    _print_map_(map2);
    cout << "3." << endl;
    _print_map_(map3);
    cin >> selected_map;                                          //getting map number
    while ((selected_map != 1) && (selected_map != 2) && (selected_map != 3))
    {
        cout << "map varede sahih nist" << endl << "map digari ra entekhab konid." << endl;
        cin >> selected_map;
    }

    system("cls");
    return selected_map;
}

inline void _installing_selected_map(char** map, char map1[20][20], char map2[20][20], char map3[20][20], int selected_map)
{
    //installing map
    switch (selected_map) {
    case 1:
        system("cls");
        for (int i = 0; i < 20; i++)
        {
            for (int j = 0; j < 20; j++)
                map[i][j] = map1[i][j];
        }
        break;
    case 2:
        system("cls");
        for (int i = 0; i < 20; i++)
        {
            for (int j = 0; j < 20; j++)
                map[i][j] = map2[i][j];
        }
        break;
    case 3:
        system("cls");
        for (int i = 0; i < 20; i++)
        {
            for (int j = 0; j < 20; j++)
                map[i][j] = map3[i][j];
        }
    }
}

inline int _select_mode_()
{
    int mode;
    // choosing the mode 
    cout << "pls choose the mode:" << endl << "1.easy" << endl << "2.normal" << endl << "3.hard" << endl;

    cin >> mode;
    while ((mode != 1) && (mode != 2) && (mode != 3))
    {
        cout << "the entry doesn't exists" << endl << "pls choose another one." << endl;
        cin >> mode;
    }
    system("cls");
    return mode;
}

inline void _installing_ghost_and_pacman_coordinate_(char** map, int** co, int score)
{
    co[2][0] = 6; co[2][1] = 7; co[0][0] = 1; co[0][1] = 1; co[3][0] = 6; co[3][1] = 12; co[4][0] = 13; co[4][1] = 7; co[1][0] = 13; co[1][1] = 12;//first coordinate
    map[co[0][0]][co[0][1]] = 'M';
    map[co[2][0]][co[2][1]] = 'P';
    map[co[3][0]][co[3][1]] = 'I';
    map[co[4][0]][co[4][1]] = 'C';
    map[co[1][0]][co[1][1]] = 'B';
}

inline void _print_table_(char finall[20][22]) {
    system("cls");
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 22; j++)
            cout << finall[i][j];
        cout << endl;
    }
}

inline void _reasone_of_lose_(int** co) {
    if ((co[0][0] == co[2][0] && co[0][1] == co[2][1]))
    {
        cout << "you got caught by pinky";

    }
    if ((co[0][0] == co[3][0] && co[0][1] == co[3][1]))
    {
        cout << "you got caught by Inky";

    }
    if ((co[0][0] == co[1][0] && co[0][1] == co[1][1]))
    {
        cout << "you got caught by Blinky";

    }
    if ((co[0][0] == co[4][0] && co[0][1] == co[4][1]))
    {
        cout << "you got caught by Clyde";
    }

 }


inline void _printing_finall_(char bord[20][22], char bakht[20][22], int score, int** co)
{

    cout << "score:  " << score << endl;
    if (score == 10) { _print_table_(bord); cout << "you won !!" << endl; }
    else { _print_table_(bakht); _reasone_of_lose_(co); }
}

inline int _play_again_() {
    int temp;
    cout << "Do you want to play again ?" << endl << "1.yes" << endl << "2.no" << endl;
    cin >> temp;
    while (temp != 1 && temp != 2)
    {
        cin >> temp;
    }
    return temp;
}

inline void _print_map_and_details(char** map, int score, int** co) {
    system("cls");
    _print_map_(map);
    cout << "score:" << score << "           " << "Pacman:(" << co[0][0] << ")" << "(" << co[0][1] << ")" << endl;
    cout << "Blinky:(" << co[1][0] << ")" << "(" << co[1][1] << ")" << "   " << "Pinky:(" << co[2][0] << ")" << "(" << co[2][1] << ")" << endl;
    cout << "Inky:(" << co[3][0] << ")" << "(" << co[3][1] << ")" << "      " << "Clyde:(" << co[4][0] << ")" << "(" << co[4][1] << ")" << endl;
}

