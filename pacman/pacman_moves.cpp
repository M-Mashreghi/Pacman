#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <ctime>
#include <conio.h>


using namespace std;

inline void _move_up_(char** map, int** co, int* score, int* t) {
    if (map[co[0][0] - 1][co[0][1]] == 'w')
    {
        *t = 0;
        cout << "no move";
    }
    else
    {
        if (map[co[0][0] - 1][co[0][1]] == 'Y')
            ++* score;
        {map[co[0][0]][co[0][1]] = ' ';
        map[--co[0][0]][co[0][1]] = 'M';
        *t = 0; }
    }
}

inline void _move_down_(char** map, int** co, int* score, int* t) {

    if (map[co[0][0] + 1][co[0][1]] == 'w')
    {
        *t = 0;
        cout << "no move";
    }
    else
    {
        if (map[co[0][0] + 1][co[0][1]] == 'Y')
            ++* score;
        {map[co[0][0]][co[0][1]] = ' ';
        map[++co[0][0]][co[0][1]] = 'M';
        *t = 0; }
    }
}

inline void _move_right_(char** map, int** co, int* score, int* t) {
    if (map[co[0][0]][co[0][1] + 1] == 'w')
    {
        *t = 0;
        cout << "no move";
    }
    else
    {
        if (map[co[0][0]][co[0][1] + 1] == 'Y')
            ++* score;
        {map[co[0][0]][co[0][1]] = ' ';
        map[co[0][0]][++co[0][1]] = 'M';
        *t = 0; }
    }
}

inline void _move_left_(char** map, int** co, int* score, int* t) {
    if (map[co[0][0]][co[0][1] - 1] == 'w')
    {
        *t = 0;
        cout << "no move";
    }
    else
    {
        if (map[co[0][0]][co[0][1] - 1] == 'Y')                                                                                //nahvaye afzayesh emtiaz 
            ++* score;
        {map[co[0][0]][co[0][1]] = ' ';
        map[co[0][0]][--co[0][1]] = 'M';
        *t = 0; }
    }





}