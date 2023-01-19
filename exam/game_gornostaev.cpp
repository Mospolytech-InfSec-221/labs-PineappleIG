#include "Game_gornostaev.h"

void game_gornostaev::cube_roll()
{
    int cube1;
    int cube2;
    int cube3;
    int bonus_cube;

    srand(time(NULL));

    char cubesides[6] = { '1', '2', '3', '4','5','6' };
    int roll = rand() % 5;
    cout << cubesides[roll];
}

void game_gornostaev::phase1()
{
    this->phase = 1;
}

void game_gornostaev::phase2()
{
    this->phase = 2;
}

void game_gornostaev::phase3()
{
    this->phase = 3;
}

void game_gornostaev::phase4()
{
    this->phase = 4;
}

void game_gornostaev::phase5()
{
    this->phase = 5;
}

void game_gornostaev::phase6()
{
    this->phase = 6;
}

void game_gornostaev::phase7()
{
    this->phase = 7;
}

void game_gornostaev::phase8()
{
    this->phase = 8;
}
