#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <time.h>
#include "game_gornostaev.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	int players_num;

	srand(time(NULL));

	cout << "Введите количество игроков (от 2 до 5): ";
	cin >> players_num;

	if (players_num < 2 || players_num > 5) {
		cout << "Неверный ввод" << endl;
		return 0;
	}

	game_gornostaev game(players_num);

	for (int i = 0; i < game.players.size(); i++) {
		cout << "Игрок " << i + 1 << " Имя: ";
		cin >> game.players[i].name;
	}
	
	for (int year = 1; year <= 5; year++) {
		game.phase1();

		game.phase246();

		game.phase3();

		game.phase246();

		game.phase5();

		game.phase246();

		game.phase7();

		game.phase8();
	}

	vector<Player> win_players;
	int max_po = INT_MIN;

	for (int i = 0; i < game.players.size(); i++) {
		if (game.players[i].po > max_po) {
			win_players.clear();
			win_players.push_back(game.players[i]);
			max_po = game.players[i].po;
		}
		else if (game.players[i].po == max_po) {
			win_players.push_back(game.players[i]);
		}
	}

	vector<Player> players_copy = win_players;
	int max_resource = INT_MIN;

	for (int i = 0; i < players_copy.size(); i++) {
		int total = players_copy[i].resource.goods.total();

		if (total > max_resource) {
			win_players.clear();
			win_players.push_back(players_copy[i]);
			max_resource = total;
		}
		else if (total == max_resource) {
			win_players.push_back(players_copy[i]);
		}
	}

	players_copy = win_players;
	int max_building = INT_MIN;

	for (int i = 0; i < players_copy.size(); i++) {

		if (players_copy[i].buildings.size() > max_building) {
			win_players.clear();
			win_players.push_back(players_copy[i]);
			max_building = players_copy[i].buildings.size();
		}
		else if (players_copy[i].buildings.size() == max_building) {
			win_players.push_back(players_copy[i]);
		}
	}

	cout << "Победившие игроки:" << endl;
	for (int i = 0; i < win_players.size(); i++) {
		cout << "    " << win_players[i].name << endl;
	}

	return 0;
}
