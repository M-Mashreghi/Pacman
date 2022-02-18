
#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <ctime>
#include <conio.h>


using namespace std;

inline int _Pinky_length_pacman(int** co) {
    int l1, l2, l3, l4, l;
    l1 = ((co[2][0] + 1 - co[0][0]) * (co[2][0] + 1 - co[0][0]) + (co[2][1] - co[0][1]) * (co[2][1] - co[0][1]));                                //be dast avardan fasle az pacman dar 4 jahat soul
    l2 = ((co[2][0] - 1 - co[0][0]) * (co[2][0] - 1 - co[0][0]) + (co[2][1] - co[0][1]) * (co[2][1] - co[0][1]));
    l3 = ((co[2][0] - co[0][0]) * (co[2][0] - co[0][0]) + (co[2][1] + 1 - co[0][1]) * (co[2][1] + 1 - co[0][1]));
    l4 = ((co[2][0] - co[0][0]) * (co[2][0] - co[0][0]) + (co[2][1] - 1 - co[0][1]) * (co[2][1] - 1 - co[0][1]));
    if ((l1 <= l2) && (l1 <= l3) && (l1 <= l4))                                       //peyda kardan kotah tarin fasle az pacman
        l = l1;
    if ((l2 <= l1) && (l2 <= l3) && (l2 <= l4))
        l = l2;
    if ((l3 <= l2) && (l3 <= l1) && (l3 <= l4))
        l = l3;
    if ((l4 <= l2) && (l4 <= l3) && (l4 <= l1))
        l = l4;
    if (l == l1)
        l = 0;
    if (l == l2)
        l = 1;
    if (l == l3)
        l = 2;
    if (l == l4)
        l = 3;
    return l;
}

inline void _Pinky_move_AI(int** co, char** map) {
    int l = _Pinky_length_pacman(co);
    switch (l)
    {
    case 0:
        if (map[co[2][0] + 1][co[2][1]] != 'w')         //down soul P
        {
            if (map[co[2][0]][co[2][1]] != 'Y')
                map[co[2][0]][co[2][1]] = ' ';
            if (map[co[2][0] + 1][co[2][1]] != 'Y')
                map[++co[2][0]][co[2][1]] = 'P';
            else
                map[++co[2][0]][co[2][1]] = 'Y';
        }  break;
    case 1:
        if (map[co[2][0] - 1][co[2][1]] != 'w')         //up soul P
        {
            if (map[co[2][0]][co[2][1]] != 'Y')
                map[co[2][0]][co[2][1]] = ' ';
            if (map[co[2][0] - 1][co[2][1]] != 'Y')
                map[--co[2][0]][co[2][1]] = 'P';
            else
                map[--co[2][0]][co[2][1]] = 'Y';
        }break;

    case 2:
        if (map[co[2][0]][co[2][1] + 1] != 'w')          //right soul P
        {
            if (map[co[2][0]][co[2][1]] != 'Y')
                map[co[2][0]][co[2][1]] = ' ';
            if (map[co[2][0]][co[2][1] + 1] != 'Y')
                map[co[2][0]][++co[2][1]] = 'P';
            else
                map[co[2][0]][++co[2][1]] = 'Y';
        }  break;
    case 3:
        if (map[co[2][0]][co[2][1] - 1] != 'w')           //left soul P
        {
            if (map[co[2][0]][co[2][1]] != 'Y')
                map[co[2][0]][co[2][1]] = ' ';
            if (map[co[2][0]][co[2][1] - 1] != 'Y')
                map[co[2][0]][--co[2][1]] = 'P';
            else
                map[co[2][0]][co[2][1]] = 'Y';
        }
    }

}

inline int _Blinky_length_pacman(int** co) {
    int l1, l2, l3, l4, l;
    l1 = ((co[1][0] + 1 - co[0][0]) * (co[1][0] + 1 - co[0][0]) + (co[1][1] - co[0][1]) * (co[1][1] - co[0][1]));
    l2 = ((co[1][0] - 1 - co[0][0]) * (co[1][0] - 1 - co[0][0]) + (co[1][1] - co[0][1]) * (co[1][1] - co[0][1]));
    l3 = ((co[1][0] - co[0][0]) * (co[1][0] - co[0][0]) + (co[1][1] + 1 - co[0][1]) * (co[1][1] + 1 - co[0][1]));
    l4 = ((co[1][0] - co[0][0]) * (co[1][0] - co[0][0]) + (co[1][1] - 1 - co[0][1]) * (co[1][1] - 1 - co[0][1]));
    if ((l1 <= l2) && (l1 <= l3) && (l1 <= l4))
        l = l1;
    if ((l2 <= l1) && (l2 <= l3) && (l2 <= l4))
        l = l2;
    if ((l3 <= l2) && (l3 <= l1) && (l3 <= l4))
        l = l3;
    if ((l4 <= l2) && (l4 <= l3) && (l4 <= l1))
        l = l4;
    if (l == l1)
        l = 0;
    if (l == l2)
        l = 1;
    if (l == l3)
        l = 2;
    if (l == l4)
        l = 3;
    return l;


}

inline void _Blinky_move_AI(int** co, char** map) {
    int l = _Blinky_length_pacman(co);
    switch (l)
    {
    case 0:
        if (map[co[1][0] + 1][co[1][1]] != 'w')
        {
            if (map[co[1][0]][co[1][1]] != 'Y')
                map[co[1][0]][co[1][1]] = ' ';
            if (map[co[1][0] + 1][co[1][1]] != 'Y')
                map[++co[1][0]][co[1][1]] = 'B';
            else
                map[++co[1][0]][co[1][1]] = 'Y';
        }  break;
    case 1:
        if (map[co[1][0] - 1][co[1][1]] != 'w')
        {
            if (map[co[1][0]][co[1][1]] != 'Y')
                map[co[1][0]][co[1][1]] = ' ';
            if (map[co[1][0] - 1][co[1][1]] != 'Y')
                map[--co[1][0]][co[1][1]] = 'B';
            else
                map[--co[1][0]][co[1][1]] = 'Y';
        }break;

    case 2:
        if (map[co[1][0]][co[1][1] + 1] != 'w')
        {
            if (map[co[1][0]][co[1][1]] != 'Y')
                map[co[1][0]][co[1][1]] = ' ';
            if (map[co[1][0]][co[1][1] + 1] != 'Y')
                map[co[1][0]][++co[1][1]] = 'B';
            else
                map[co[1][0]][++co[1][1]] = 'Y';
        }  break;
    case 3:
        if (map[co[1][0]][co[1][1] - 1] != 'w')
        {
            if (map[co[1][0]][co[1][1]] != 'Y')
                map[co[1][0]][co[1][1]] = ' ';
            if (map[co[1][0]][co[1][1] - 1] != 'Y')
                map[co[1][0]][--co[1][1]] = 'B';
            else
                map[co[1][0]][co[1][1]] = 'Y';
        }
    }





}

inline int _Clyde_length_pacman(int** co) {
    int l1, l2, l3, l4, l;
    l1 = ((co[4][0] + 1 - co[0][0]) * (co[4][0] + 1 - co[0][0]) + (co[4][1] - co[0][1]) * (co[4][1] - co[0][1]));
    l2 = ((co[4][0] - 1 - co[0][0]) * (co[4][0] - 1 - co[0][0]) + (co[4][1] - co[0][1]) * (co[4][1] - co[0][1]));
    l3 = ((co[4][0] - co[0][0]) * (co[4][0] - co[0][0]) + (co[4][1] + 1 - co[0][1]) * (co[4][1] + 1 - co[0][1]));
    l4 = ((co[4][0] - co[0][0]) * (co[4][0] - co[0][0]) + (co[4][1] - 1 - co[0][1]) * (co[4][1] - 1 - co[0][1]));
    if ((l1 <= l2) && (l1 <= l3) && (l1 <= l4))
        l = l1;
    if ((l2 <= l1) && (l2 <= l3) && (l2 <= l4))
        l = l2;
    if ((l3 <= l2) && (l3 <= l1) && (l3 <= l4))
        l = l3;
    if ((l4 <= l2) && (l4 <= l3) && (l4 <= l1))
        l = l4;
    if (l == l1)
        l = 0;
    if (l == l2)
        l = 1;
    if (l == l3)
        l = 2;
    if (l == l4)
        l = 3;
    return l;

}

inline void _Clyde_move_AI(int** co, char** map) {
    int l = _Clyde_length_pacman(co);
    switch (l)
    {
    case 0:
        if (map[co[4][0] + 1][co[4][1]] != 'w')
        {
            if (map[co[4][0]][co[4][1]] != 'Y')
                map[co[4][0]][co[4][1]] = ' ';
            if (map[co[4][0] + 1][co[4][1]] != 'Y')
                map[++co[4][0]][co[4][1]] = 'C';
            else
                map[++co[4][0]][co[4][1]] = 'Y';
        }  break;
    case 1:
        if (map[co[4][0] - 1][co[4][1]] != 'w')
        {
            if (map[co[4][0]][co[4][1]] != 'Y')
                map[co[4][0]][co[4][1]] = ' ';
            if (map[co[4][0] - 1][co[4][1]] != 'Y')
                map[--co[4][0]][co[4][1]] = 'C';
            else
                map[--co[4][0]][co[4][1]] = 'Y';
        }break;

    case 2:
        if (map[co[4][0]][co[4][1] + 1] != 'w')
        {
            if (map[co[4][0]][co[4][1]] != 'Y')
                map[co[4][0]][co[4][1]] = ' ';
            if (map[co[4][0]][co[4][1] + 1] != 'Y')
                map[co[4][0]][++co[4][1]] = 'C';
            else
                map[co[4][0]][++co[4][1]] = 'Y';
        }  break;
    case 3:
        if (map[co[4][0]][co[4][1] - 1] != 'w')
        {
            if (map[co[4][0]][co[4][1]] != 'Y')
                map[co[4][0]][co[4][1]] = ' ';
            if (map[co[4][0]][co[4][1] - 1] != 'Y')
                map[co[4][0]][--co[4][1]] = 'C';
            else
                map[co[4][0]][co[4][1]] = 'Y';
        }
    }


}

inline int _Inky_length_pacman(int** co)
{
    int l1, l2, l3, l4, l;
    l1 = ((co[3][0] + 1 - co[0][0]) * (co[3][0] + 1 - co[0][0]) + (co[3][1] - co[0][1]) * (co[3][1] - co[0][1]));
    l2 = ((co[3][0] - 1 - co[0][0]) * (co[3][0] - 1 - co[0][0]) + (co[3][1] - co[0][1]) * (co[3][1] - co[0][1]));
    l3 = ((co[3][0] - co[0][0]) * (co[3][0] - co[0][0]) + (co[3][1] + 1 - co[0][1]) * (co[3][1] + 1 - co[0][1]));
    l4 = ((co[3][0] - co[0][0]) * (co[3][0] - co[0][0]) + (co[3][1] - 1 - co[0][1]) * (co[3][1] - 1 - co[0][1]));
    if ((l1 <= l2) && (l1 <= l3) && (l1 <= l4))
        l = l1;
    if ((l2 <= l1) && (l2 <= l3) && (l2 <= l4))
        l = l2;
    if ((l3 <= l2) && (l3 <= l1) && (l3 <= l4))
        l = l3;
    if ((l4 <= l2) && (l4 <= l3) && (l4 <= l1))
        l = l4;
    if (l == l1)
        l = 0;
    if (l == l2)
        l = 1;
    if (l == l3)
        l = 2;
    if (l == l4)
        l = 3;
    return l;



}

inline void _Inky_move_AI(int** co, char** map) {
    int l = _Inky_length_pacman(co);
    switch (l)
    {
    case 0:
        if (map[co[3][0] + 1][co[3][1]] != 'w')
        {
            if (map[co[3][0]][co[3][1]] != 'Y')
                map[co[3][0]][co[3][1]] = ' ';
            if (map[co[3][0] + 1][co[3][1]] != 'Y')
                map[++co[3][0]][co[3][1]] = 'I';
            else
                map[++co[3][0]][co[3][1]] = 'Y';
        }  break;
    case 1:
        if (map[co[3][0] - 1][co[3][1]] != 'w')
        {
            if (map[co[3][0]][co[3][1]] != 'Y')
                map[co[3][0]][co[3][1]] = ' ';
            if (map[co[3][0] - 1][co[3][1]] != 'Y')
                map[--co[3][0]][co[3][1]] = 'I';
            else
                map[--co[3][0]][co[3][1]] = 'Y';
        }break;

    case 2:
        if (map[co[3][0]][co[3][1] + 1] != 'w')
        {
            if (map[co[3][0]][co[3][1]] != 'Y')
                map[co[3][0]][co[3][1]] = ' ';
            if (map[co[3][0]][co[3][1] + 1] != 'Y')
                map[co[3][0]][++co[3][1]] = 'I';
            else
                map[co[3][0]][++co[3][1]] = 'Y';
        }  break;
    case 3:
        if (map[co[3][0]][co[3][1] - 1] != 'w')
        {
            if (map[co[3][0]][co[3][1]] != 'Y')
                map[co[3][0]][co[3][1]] = ' ';
            if (map[co[3][0]][co[3][1] - 1] != 'Y')
                map[co[3][0]][--co[3][1]] = 'I';
            else
                map[co[3][0]][co[3][1]] = 'Y';
        }
    }
}

inline void _Clyde_moves_random_(int** co, char** map) {
    int x;
    x = rand() % 4;

    switch (x)
    {
    case 0:                       //down soul C
        if (map[co[4][0] + 1][co[4][1]] != 'w')
        {
            if (map[co[4][0]][co[4][1]] != 'Y')
                map[co[4][0]][co[4][1]] = ' ';
            if (map[co[4][0] + 1][co[4][1]] != 'Y')
                map[++co[4][0]][co[4][1]] = 'C';
            else
                map[++co[4][0]][co[4][1]] = 'Y';
        }
        break;
    case 1:                       //left soul C
        if (map[co[4][0]][co[4][1] - 1] != 'w')
        {
            if (map[co[4][0]][co[4][1]] != 'Y')
                map[co[4][0]][co[4][1]] = ' ';
            if (map[co[4][0]][co[4][1] - 1] != 'Y')
                map[co[4][0]][--co[4][1]] = 'C';
            else
                map[co[4][0]][--co[4][1]] = 'Y';
        }

        break;
    case 2:                       //up soul c
        if (map[co[4][0] - 1][co[4][1]] != 'w')
        {
            if (map[co[4][0]][co[4][1]] != 'Y')
                map[co[4][0]][co[4][1]] = ' ';
            if (map[co[4][0] - 1][co[4][1]] != 'Y')
                map[--co[4][0]][co[4][1]] = 'C';
            else
                map[--co[4][0]][co[4][1]] = 'Y';
        }
        break;
    case 3:                      //right soul C
        if (map[co[4][0]][co[4][1] + 1] != 'w')
        {
            if (map[co[4][0]][co[4][1]] != 'Y')
                map[co[4][0]][co[4][1]] = ' ';
            if (map[co[4][0]][co[4][1] + 1] != 'Y')
                map[co[4][0]][++co[4][1]] = 'C';
            else
                map[co[4][0]][++co[4][1]] = 'Y';
        }
        break;
    }
}

inline void _Pinky_moves_random_(int** co, char** map) {
    int x = rand() % 4;
    switch (x)
    {
    case 0:                       //down soul P
        if (map[co[2][0] + 1][co[2][1]] != 'w')
        {
            if (map[co[2][0]][co[2][1]] != 'Y')
                map[co[2][0]][co[2][1]] = ' ';
            if (map[co[2][0] + 1][co[2][1]] != 'Y')
                map[++co[2][0]][co[2][1]] = 'P';
            else
                map[++co[2][0]][co[2][1]] = 'Y';
        }
        break;
    case 1:                       //left soul P
        if (map[co[2][0]][co[2][1] - 1] != 'w')
        {
            if (map[co[2][0]][co[2][1]] != 'Y')
                map[co[2][0]][co[2][1]] = ' ';
            if (map[co[2][0]][co[2][1] - 1] != 'Y')
                map[co[2][0]][--co[2][1]] = 'P';
            else
                map[co[2][0]][--co[2][1]] = 'Y';
        }

        break;
    case 2:                       //up soul P
        if (map[co[2][0] - 1][co[2][1]] != 'w')
        {
            if (map[co[2][0]][co[2][1]] != 'Y')
                map[co[2][0]][co[2][1]] = ' ';
            if (map[co[2][0] - 1][co[2][1]] != 'Y')
                map[--co[2][0]][co[2][1]] = 'P';
            else
                map[--co[2][0]][co[2][1]] = 'Y';
        }
        break;
    case 3:                      //right soul P
        if (map[co[2][0]][co[2][1] + 1] != 'w')
        {
            if (map[co[2][0]][co[2][1]] != 'Y')
                map[co[2][0]][co[2][1]] = ' ';
            if (map[co[2][0]][co[2][1] + 1] != 'Y')
                map[co[2][0]][++co[2][1]] = 'P';
            else
                map[co[2][0]][++co[2][1]] = 'Y';
        }
        break;
    }




}

inline void _Inky_moves_random_(int** co, char** map) {
    int x = rand() % 4;
    switch (x)
    {
    case 0:                       //down soul I
        if (map[co[3][0] + 1][co[3][1]] != 'w')
        {
            if (map[co[3][0]][co[3][1]] != 'Y')
                map[co[3][0]][co[3][1]] = ' ';
            if (map[co[3][0] + 1][co[3][1]] != 'Y')
                map[++co[3][0]][co[3][1]] = 'I';
            else
                map[++co[3][0]][co[3][1]] = 'Y';
        }
        break;
    case 1:                       //left soul I
        if (map[co[3][0]][co[3][1] - 1] != 'w')
        {
            if (map[co[3][0]][co[3][1]] != 'Y')
                map[co[3][0]][co[3][1]] = ' ';
            if (map[co[3][0]][co[3][1] - 1] != 'Y')
                map[co[3][0]][--co[3][1]] = 'I';
            else
                map[co[3][0]][--co[3][1]] = 'Y';
        }

        break;
    case 2:                       //up soul I
        if (map[co[3][0] - 1][co[3][1]] != 'w')
        {
            if (map[co[3][0]][co[3][1]] != 'Y')
                map[co[3][0]][co[3][1]] = ' ';
            if (map[co[3][0] - 1][co[3][1]] != 'Y')
                map[--co[3][0]][co[3][1]] = 'I';
            else
                map[--co[3][0]][co[3][1]] = 'Y';
        }
        break;
    case 3:                      //right soul I
        if (map[co[3][0]][co[3][1] + 1] != 'w')
        {
            if (map[co[3][0]][co[3][1]] != 'Y')
                map[co[3][0]][co[3][1]] = ' ';
            if (map[co[3][0]][co[3][1] + 1] != 'Y')
                map[co[3][0]][++co[3][1]] = 'I';
            else
                map[co[3][0]][++co[3][1]] = 'Y';
        }
        break;
    }



}

inline void _Blinky_moves_random_(int** co, char** map) {
    int  x = rand() % 4;
    switch (x)
    {
    case 0:                       //down soul B
        if (map[co[1][0] + 1][co[1][1]] != 'w')
        {
            if (map[co[1][0]][co[1][1]] != 'Y')
                map[co[1][0]][co[1][1]] = ' ';
            if (map[co[1][0] + 1][co[1][1]] != 'Y')
                map[++co[1][0]][co[1][1]] = 'B';
            else
                map[++co[1][0]][co[1][1]] = 'Y';
        }
        break;
    case 1:                       //left soul B
        if (map[co[1][0]][co[1][1] - 1] != 'w')
        {
            if (map[co[1][0]][co[1][1]] != 'Y')
                map[co[1][0]][co[1][1]] = ' ';
            if (map[co[1][0]][co[1][1] - 1] != 'Y')
                map[co[1][0]][--co[1][1]] = 'B';
            else
                map[co[1][0]][--co[1][1]] = 'Y';
        }
        break;
    case 2:                       //up soul B
        if (map[co[1][0] - 1][co[1][1]] != 'w')
        {
            if (map[co[1][0]][co[1][1]] != 'Y')
                map[co[1][0]][co[1][1]] = ' ';
            if (map[co[1][0] - 1][co[1][1]] != 'Y')
                map[--co[1][0]][co[1][1]] = 'B';
            else
                map[--co[1][0]][co[1][1]] = 'Y';
        }
        break;
    case 3:                      //right soul B
        if (map[co[1][0]][co[1][1] + 1] != 'w')
        {
            if (map[co[1][0]][co[1][1]] != 'Y')
                map[co[1][0]][co[1][1]] = ' ';
            if (map[co[1][0]][co[1][1] + 1] != 'Y')
                map[co[1][0]][++co[1][1]] = 'B';
            else
                map[co[1][0]][++co[1][1]] = 'Y';
        }
        break;
    }

}