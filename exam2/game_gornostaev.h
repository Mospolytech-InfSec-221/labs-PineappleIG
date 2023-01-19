#include <iostream>
#include <vector>
using namespace std;

class Goods
{
public:
	int gold;
	int wood;
	int rock;

	int total() {
		return gold + wood + rock;
	}
};

class Advisor 
{
public:
	string name;
	string player_name;

};

class Cubic 
{
public:
	int min;
	int max;
	int value;

	Cubic() {
		min = 1;
		max = 6;
		value = min;
	}

	Cubic(int min_in, int max_in) {
		min = min_in;
		max = max_in;
		value = min;
	}

	void roll();
};

class Building
{
public:
	string name;
};

class Resource 
{
public:
	Goods goods;
	int tokens;
	Cubic cubic[3];
	Cubic cubic_white;
	bool has_cubic_white;
};

class Enemy
{
public:
	int force;
	string name;
	int lost_po;
	Goods lost_goods;
	int got_po;
	int got_goods;
};

class Player 
{

public:
	bool has_messenger;
	int po;
	int military;
	string name;
	Resource resource;
	vector<Building> buildings;
	Advisor advisor;

	void roll_cubices();
	int total_cubices();
};


class game_gornostaev 
{
public:
	game_gornostaev(int num_players);
	void phase1();
	void phase3();
	void phase5();
	void phase7();
	void phase8();
	void phase246();

	vector<Player> players;
	vector<Advisor> advisors;
	int year;
	int phase;
	Enemy enemy;

private:
	void phase246_core();
	void phase246_advisor();
	void advisor_help(const char *advisor_name, Player &player);
	void building(const char *advisor_name, Player &player);
	void select_good(Player &player, int num);
};
