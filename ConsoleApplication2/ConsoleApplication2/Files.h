#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include <conio.h>
#include <fstream>
#include <Windows.h>
#include <mmsystem.h>

using namespace std;
struct standing {
	string name;
	int score;
};

void Nim_Game() {    // view the name of game
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	int i = 10;
	string nim_data;
	fstream file;
	file.open("Data\\nim.txt");
	while (!file.eof()) {
		getline(file, nim_data);
		if (nim_data.find("_") != -1) {
			i += 2;
		}
		SetConsoleTextAttribute(h, i);
		cout << nim_data << endl;

	}

}

void retain_scoreboard(standing scoreboard[], int &biggest_size) {
	int i = 0;
	fstream file;
	file.open("Data\\Scoreboard.txt");
	while (!file.eof()) {
		file >> scoreboard[i].name >> scoreboard[i].score;
		if (scoreboard[i].name.size() > biggest_size)
			biggest_size = scoreboard[i].name.size();
		i++;
	}
}

void menu() {  //view the menu of the game
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	int i = 14;
	string nim_data;
	fstream file;
	file.open("Data\\menu.txt");
	while (!file.eof()) {
		getline(file, nim_data);
		SetConsoleTextAttribute(h, i);
		cout << nim_data << endl;
	}

}

void Instructions() { // give information about(nim game)
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	int i = 11;
	string nim_data;
	fstream file;
	file.open("Data\\instructions.txt");
	while (!file.eof()) {
		getline(file, nim_data);
		SetConsoleTextAttribute(h, i);
		cout << nim_data << endl;

	}
	char back;
	back = _getch();
}

void Credits() {

	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	int i = 8;
	string nim_data;
	fstream file;
	file.open("Data\\credits.txt");
	while (!file.eof()) {
		getline(file, nim_data);
		SetConsoleTextAttribute(h, i);
		cout << nim_data << endl;

	}
	char back;
	back = _getch();
}
char Choose_Version() {// choose a version you want to paly
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	int i = 13;
	char version;
	string nim_data;
	fstream file;
	file.open("Data\\version.txt");
	while (!file.eof()) {
		getline(file, nim_data);
		SetConsoleTextAttribute(h, i);
		cout << nim_data << endl;

	}
	while (true) {
		version = _getch();
		if (version == '1' || version == '2')
			break;
	}
	system("CLS"); {};
	return version;
}
void save_scoreboard(standing scoreboard[]) {
	fstream file;
	file.open("Data\\Scoreboard.txt", ios::out);
	for (int i = 0; i < 10; i++) {
		file << scoreboard[i].name << " " << scoreboard[i].score << endl;
	}
}


void End_Game() {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	int i = 6;
	string nim_data;
	fstream file;
	file.open("Data\\end.txt");
	while (!file.eof()) {
		getline(file, nim_data);
		SetConsoleTextAttribute(h, i);
		cout << nim_data << endl;
	}

}
