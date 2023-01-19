#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#include "game_gornostaev.h"

void Cubic::roll() {
	value = rand() % (max - min + 1) + min;
}

void Player::roll_cubices() //������ �������
{
	setlocale(LC_ALL, "Russian");
	cout << "����� " << name << " ������ �������:" << endl;

	for (int i = 1; i <= 3; i++) {
		resource.cubic[i].roll();
		cout << "    ����� " << i << ": " << resource.cubic[i].value << endl;
	}

	if (resource.has_cubic_white) {
		resource.cubic_white.roll();
		cout << "    ����� ������: " << resource.cubic_white.value << endl;
	}
}

int Player::total_cubices()
{
	int res = 0;

	for (int i = 0; i < 3; i++) {
		res += resource.cubic[i].value;
	}

	if (resource.has_cubic_white) {
		res += resource.cubic_white.value;
	}

	return res;
}

game_gornostaev::game_gornostaev(int num_players)
{
	year = 1;
	phase = 1;
	players = vector<Player>(num_players);
}

void game_gornostaev::phase1()
{
	int min_resources = INT_MAX;
	int min_building = INT_MAX;
	vector<int> min_players;

	for (int i = 0; i < players.size(); i++) {
		if (players[i].buildings.size() < min_building) {
			min_building = players[i].buildings.size();
			min_players.clear();
			min_players.push_back(i);
			min_resources = players[i].resource.goods.total();
		}
		else if (players[i].buildings.size() == min_building) {
			int total_res = players[i].resource.goods.total();
			if (total_res < min_resources) {
				min_resources = total_res;
				min_players.clear();
				min_players.push_back(i);
			}
			else if (total_res == min_resources) {
				min_players.push_back(i);
			}
		}
	}

	if (min_players.size() == 1) {
		int index = min_players[0];
		players[index].resource.has_cubic_white = true;
	}
	else {
		setlocale(LC_ALL, "Russian");
		for (int i = 0; i < min_players.size(); i++) {
			int index = min_players[i];
			int res;

			cout << "    1. ������" << endl;
			cout << "    2. ������" << endl;
			cout << "    3. ������" << endl;
			cout << "����� " << players[index].name << " �������� ������ (1 - 3): ";
			cin >> res;
			if (res == 1) {
				players[index].resource.goods.gold++;
			}
			else if (res == 2) {
				players[index].resource.goods.wood++;
			}
			else if (res == 3) {
				players[index].resource.goods.rock++;
			}
			else {
				cout << "�������� ����" << endl;
			}
		}
	}

	phase = 2;
}

void game_gornostaev::phase3()
{
	int max_building = INT_MIN;
	vector<int> max_players;

	for (int i = 0; i < players.size(); i++) {
		if (players[i].buildings.size() > max_building) {
			max_building = players[i].buildings.size();
			max_players.clear();
			max_players.push_back(i);
		}
		else if (players[i].buildings.size() == max_building) {
			max_players.push_back(i);
		}
	}

	for (int i = 0; i < max_players.size(); i++) {
		int index = max_players[i];
		players[i].po++;
	}

	phase = 4;
}

void game_gornostaev::phase5()
{
	int min_resources = INT_MAX;
	int min_building = INT_MAX;
	vector<int> min_players;

	for (int i = 0; i < players.size(); i++) {
		players[i].has_messenger = false;

		if (players[i].buildings.size() < min_building) {
			min_building = players[i].buildings.size();
			min_players.clear();
			min_players.push_back(i);
			min_resources = players[i].resource.goods.total();
		}
		else if (players[i].buildings.size() == min_building) {
			int total_res = players[i].resource.goods.total();
			if (total_res < min_resources) {
				min_resources = total_res;
				min_players.clear();
				min_players.push_back(i);
			}
			else if (total_res == min_resources) {
				min_players.push_back(i);
			}
		}
	}
	setlocale(LC_ALL, "Russian");

	if (min_players.size() == 1) {
		int index = min_players[0];
		cout << "����� " << players[index].name << " ������� �����" << endl;
		players[index].has_messenger = true;
	}

	phase = 6;
}

void game_gornostaev::phase7()
{
	setlocale(LC_ALL, "Russian");
	for (int i = 0; i < players.size(); i++) {
		int total_res = players[i].resource.goods.total();

		if (total_res >= 2) {
			int military_num;
			cout << "������� ������� ������ (maximum " << total_res / 2 << "): ";
			cin >> military_num;

			if (military_num > (total_res / 2)) {
				cout << "�������� ����" << endl;
				return;
			}

			int gold = 0, wood = 0, rock = 0;
			cout << "������� " << military_num * 2 << " ������:" << endl;

			if (players[i].resource.goods.gold) {
				cout << "������ (" << players[i].resource.goods.gold << "): ";
				cin >> gold;
			}

			if (players[i].resource.goods.wood) {
				cout << "������ (" << players[i].resource.goods.wood << "): ";
				cin >> wood;
			}

			if (players[i].resource.goods.rock) {
				cout << "������ (" << players[i].resource.goods.rock << "): ";
				cin >> rock;
			}

			if ((gold + wood + rock) != (military_num * 2)) {
				cout << "�������� ����" << endl;
				return;
			}

			players[i].resource.goods.gold -= gold;
			players[i].resource.goods.wood -= wood;
			players[i].resource.goods.rock -= rock;
		}
	}
	phase = 8;
}

bool player_cmp(Player& a, Player& b)
{
	return a.total_cubices() < b.total_cubices();
};

void game_gornostaev::phase246_core()
{
	setlocale(LC_ALL, "Russian");
	for (int i = 0; i < players.size(); i++) {
		players[i].roll_cubices();
	}

	sort(players.begin(), players.end(), player_cmp);

	cout << "����� ������� �����:" << endl;
	for (int i = 0; i < players.size(); i++) {
		cout << "     " << i + 1 << ". " << players[i].name << endl;
	}
}

void game_gornostaev::phase246_advisor() //��������
{
}

void game_gornostaev::select_good(Player &player, int num) //����� ������
{
	setlocale(LC_ALL, "Russian");
	for (int i = 0; i < num; i++) {
		int select;

		cout << "    1. ������" << endl;
		cout << "    2. ������" << endl;
		cout << "    3. ������" << endl;

		cin >> select;
		if (select == 1) {
			player.resource.goods.gold++;
		}
		else if (select == 2) {
			player.resource.goods.wood++;
		}
		else if (select == 3) {
			player.resource.goods.rock++;
		}
	}
}
void game_gornostaev::advisor_help(const char *advisor_name, Player &player) //����� ���������
{
	setlocale(LC_ALL, "Russian");
	if (advisor_name == "���") {
		player.po++;
	}
	else if (advisor_name == "����������") {
		player.resource.goods.gold++;
	}
	else if (advisor_name == "����������") {
		player.resource.goods.wood++;
	}
	else if (advisor_name == "�����") {
		int select;

		cout << "��������:" << endl;
		cout << "    1. ������" << endl;
		cout << "    2. ������" << endl;
		cin >> select;

		if (select == 1) {
			player.resource.goods.gold++;
		} else {
			player.resource.goods.wood++;
		}
	}
	else if (advisor_name == "�������") {
		player.military++;
	}
	else if (advisor_name == "�������") {
		int select;

		cout << "�������� ����� ��� ������:" << endl;
		if (player.resource.goods.gold) {
			cout << "    1. ������ (available " << player.resource.goods.gold << endl;
		}

		if (player.resource.goods.wood) {
			cout << "    2. ������ (available " << player.resource.goods.wood << endl;
		}

		if (player.resource.goods.rock) {
			cout << "    3. ������ (available " << player.resource.goods.rock << endl;
		}

		cin >> select;
		if (select == 1) {
			player.resource.goods.gold--;
		}
		else if (select == 2) {
			player.resource.goods.wood--;
		}
		else if (select == 3) {
			player.resource.goods.rock--;
		}

		cout << "�������� �����:" << endl;
		select_good(player, 2);
	}
	else if (advisor_name == "��������") {
		cout << "�������� �����:" << endl;
		select_good(player, 1);
	}
	else if (advisor_name == "����������� ��������") {
		player.resource.goods.gold += 2;
	}
	else if (advisor_name == "�������") {
		int select;

		cout << "�������� �����:" << endl;
		cout << "    1. 1 ������ � 1 ������" << endl;
		cout << "    2. 1 ������ � 1 ������" << endl;

		cin >> select;
		if (select == 1) {
			player.resource.goods.gold++;
			player.resource.goods.wood++;
		}
		else if (select == 2) {
			player.resource.goods.wood++;
			player.resource.goods.rock++;
		}
	}
	else if (advisor_name == "�������") {
		player.military += 2;
	}
	else if (advisor_name == "������") {
		int select;

		cout << "�������� �����:" << endl;
		cout << "    1. 1 ������ � 1 ������" << endl;
		cout << "    2. 1 ������ � 1 ������" << endl;

		cin >> select;
		if (select == 1) {
			player.resource.goods.rock++;
			player.resource.goods.wood++;
		}
		else if (select == 2) {
			player.resource.goods.gold++;
			player.resource.goods.rock++;
		}
	}
	else if (advisor_name == "���������") {
		cout << "�������� �����:" << endl;
		select_good(player, 2);
	}
	else if (advisor_name == "�������") {
		player.resource.goods.wood += 3;
	}
	else if (advisor_name == "�������������") {
		cout << "�������� �����:" << endl;
		select_good(player, 3);
		player.po--;
	}
	else if (advisor_name == "������������") {
		player.resource.goods.gold++;
		player.resource.goods.wood++;
		player.resource.goods.rock++;
	}
	else if (advisor_name == "��������") {
		cout << "�������� �����:" << endl;
		select_good(player, 2);
		player.po += 3;
	}
	else if (advisor_name == "������") {
		player.resource.goods.gold++;
		player.resource.goods.wood++;
		player.resource.goods.rock++;
		player.military++;
	}
}

void game_gornostaev::building(const char *advisor_name, Player &player) // ��������
{
}

void game_gornostaev::phase246() //3 ���� � �����
{
	phase246_core();
	phase246_advisor();

	for (int i = 0; i < players.size(); i++) {
		if (players[i].advisor.name.empty()) {
			advisor_help(players[i].advisor.name.c_str(), players[i]);
		}
	}

	for (int i = 0; i < players.size(); i++) {
		building(players[i].advisor.name.c_str(), players[i]);
	}
}

void game_gornostaev::phase8()
{
	phase = 1;
	year++;
}

void defense_level(const char* enemy_name, int king_help, Player &player)
{
}
