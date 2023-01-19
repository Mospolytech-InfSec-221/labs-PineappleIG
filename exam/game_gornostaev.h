#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class game_gornostaev
{
private:
    int count_players;
    string enemy = "";
    int phase;
    int year;
    struct player
    {
        string name;
        int ochered_hoda;
        int gold;
        int wood;
        int rock;
        int coins;
        int cubic1;
        int cubic2;
        int cubic3;
        int additional_cubic;
        bool adviser;
        int reestr;
        int points;
        vector<int> buildings;
    };

public:
    game_gornostaev() {};
    game_gornostaev(int count_players) {};
    ~game_gornostaev() {};

    void cube_roll() {}
    void phase1() {};
    void phase2() {};
    void phase3() {};
    void phase4() {};
    void phase5() {};
    void phase6() {};
    void phase7() {};
    void phase8() {};
    void defense_level(const char* enemy_name, int king_help) {};

};