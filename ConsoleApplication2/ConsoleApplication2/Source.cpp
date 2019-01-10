#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <string.h>
#include <conio.h>
#include <math.h>
#include <fstream>
#include <Windows.h>
#include <mmsystem.h>
#include "Files.h"
#include "TestCases.h"
#define  del cin.clear();cin.ignore(100000, '\n');
using namespace std;
standing scoreboard[10];
int biggest_size = 0;
void check_nhighscore(int place, int final_score, string winner);
/*bool checker = 1, p = 1, ops = 1;
float num_columns, sum = 0;
char table[20][26], check_table[20][26], Variable;
int pieces_of_column[26];
string player1, player2, n_col;
char valid;
bool isMisere = 0, isValid = 1, Sound = true;
map<char, long long>mp;
int num_pieces, num_Rpieces;
char index;*/

void new_score(string winner) {
	int place = -1, final_score = 0;
	for (int i = 0; i < 10; i++) {
		if (scoreboard[i].name == winner) {
			if (isMisere)
				scoreboard[i].score += 5;
			else
				scoreboard[i].score += 3;
			final_score = scoreboard[i].score;
			place = i;
			break;
		}
		if (final_score == 0) {
			if (isMisere)
				final_score = 5;
			else
				final_score = 3;
		}
	}
	check_nhighscore(place, final_score, winner);
}
void check_nhighscore(int place, int final_score, string winner) {
	if (place != -1) {
		for (int i = place - 1; i >= 0 && scoreboard[i].score < final_score; i--) {
			swap(scoreboard[i].name, scoreboard[place].name);
			swap(scoreboard[i].score, scoreboard[place].score);
			place = i;
		}
	}
	else {
		pair <string, int> temp;
		for (int i = 0; i < 10; i++) {
			if (scoreboard[i].score < final_score) {
				temp.first = scoreboard[i].name;
				temp.second = scoreboard[i].score;
				scoreboard[i].name = winner;
				scoreboard[i].score = final_score;
				if (winner.size() > biggest_size)
					biggest_size = winner.size();
				for (int j = i + 1; j < 10; j++) {
					swap(scoreboard[j].name, temp.first);
					swap(scoreboard[j].score, temp.second);
				}
				break;
			}
		}
	}
	save_scoreboard(scoreboard);
}

void reset() {
	for (int i = 0; i < 10; i++) {
		scoreboard[i].name = "---"; 
		scoreboard[i].score = 0;
	}
	save_scoreboard(scoreboard);
}

void view_scoreboard() {
	
	while (true) {
		system("CLS"); {
			cout << "\t\t\t\t\t\t\t\t\t    " << "S C O R E B O A R D" << endl << endl;
			for (int i = 0; i < 10; i++) {
				if (i < 9)
					cout << "\t\t\t\t\t\t\t\t\t" << i + 1 << "  - " << scoreboard[i].name;
				else
					cout << "\t\t\t\t\t\t\t\t\t" << i + 1 << " - " << scoreboard[i].name;
				for (int j = 0; j < biggest_size - scoreboard[i].name.size(); j++) {
					cout << " ";
				}
				cout << "\t\t\t" << scoreboard[i].score << "\n\n\n";
			}

			char back;
			cout << "\t\t\t\t\t\t\t\t" << "Press R to reset, any other key to go back\n";
			back = _getch();
			if (back == 'R' || back == 'r')
				reset();
			else
				break;
		}
	}

		
}



void input_data()
{
	system("CLS");
	isMisere = 0;
	char version;
	version = Choose_Version();
	if (version == '2') {
		isMisere = 1;
	}
	cout << "Player 1 name: ";
	do {
		getline(cin, player1);
	} while (player1.empty());
	cout << "Player 2 name: ";
	do {
		getline(cin, player2);
	} while (player2.empty());
	check_player(player1, player2);
	cout << "Number of columns: ";
	checker = 1, p = 1;
	n_col.clear();
	check_col();
	//num_columns = check_columns(num_columns);
}

void creating_empty_table() {
	char index = 'A';
	system("CLS"); {
		for (int i = 0; i < 20; i++)
		{
			for (int j = 0; j < num_columns; j++)
			{
				table[i][j] = '.';
				cout << table[i][j] << "   ";
			}
			cout << endl;
		}
		for (int i = 1; i <= num_columns; i++, index++)
		{
			cout << index << "   ";

		}
		cout << endl;
	}
}

void view_table() {
	for (int i = 0; i < 20; i++)
		{
			for (int j = 0; j < num_columns; j++)
			{
				cout << table[i][j] << "   ";
			}
			cout << endl;
		}
		char indexx = 'A';
		for (int i = 1; i <= num_columns; i++, indexx++)
		{
			cout << indexx << "   ";
		}
		cout << endl;
}

void setting_table(int num_columns)
{
	sum = 0; //the sum of pieces if the game
	creating_empty_table();
	index = 'A';
	for (int j = 0; j < num_columns; j++)
	{
		cout << "Enter the number of pieces of column " << index << ": ";
		check_pec();                           //entering and checking the number of pieces
		mp[index] = num_pieces;               //linking between the index and the number of pieces in it (in uppercase form)
		mp[tolower(index)] = num_pieces;     //linking between the index and the number of pieces in it (in lowercase form)

		/*that will help us to check the validation of the number of the pieces the player wants to remove
		during the game also to avoid errors if he enters the index in a lowercase form*/

		//num_pieces = check_pieces(num_pieces);
		sum += num_pieces;
		system("CLS");
		{
			for (int i = 19, w = 0; w < num_pieces; w++, i--)
			{
				table[i][j] = 'O';
				pieces_of_column[j]++;
			}
			index++;
		}
		view_table();
	}
}


void play(int sum)
{
	int turn = 1, removed_pieces = 0;
	bool PL1 = 1; //to check if it's player1's turn or not
	while (true)
	{
		system("CLS");
		{
			view_table();
			if (sum == 0)
			{
				system("cls");
				{
					if (isMisere) {
						if (turn == 1)
							PL1 = 0;
						else
							PL1 = 1;
					}
					if (PL1) {
						new_score(player1); //storing new score in the scoreboard if it has a place in it
						cout << "\t\t" << player1 << " WINS!\n"
							<< "---------------------------------------------------------\n"
							<< "Press \"M\" for Main Menu , \"E\" to Exit: ";
						do {
							valid = _getch();
						} while (valid != 'M'&&valid != 'm'&&valid != 'e'&&valid != 'E');
						ops = 1;
						break;
					}
					else {
						new_score(player2);
						cout << "\t\t" << player2 << " WINS!\n"
							<< "---------------------------------------------------------\n"
							<< "Press \"M\" for Main Menu , \"E\" to Exit: ";
						do {
							valid = _getch();
						} while (valid != 'M'&&valid != 'm'&&valid != 'e'&&valid != 'E');
						ops = 1;
						break;
					}
				}
			}
			if (PL1) {
				cout << player1 << "'s turn:\n";
			}
			else {
				cout << player2 << "'s turn:\n";
			}
			cout << "Type the index of the column to remove from:";
			//cin >> index;
			check_index(); //entering and checking the validation of index
			//index = check_index(index, num_columns, pieces_of_column);
			int column = (toupper(index) - 'A');
			cout << "How many pieces do you want to remove:";
			//cin >> num_Rpieces;
			check_npec(column); // entering and checking the validation of the number of removed pieces
			//num_Rpieces = check_Rpieces(num_Rpieces, pieces_of_column[column]);
			mp[index] -= num_Rpieces;
			for (int i = 20 - pieces_of_column[column]; removed_pieces < num_Rpieces; i++)
			{
				if (table[i][column] == '.')
				{
					continue;
				}
				else
				{
					table[i][column] = '.';
					removed_pieces++;
				}
			}
			pieces_of_column[column] -= num_Rpieces;

			removed_pieces = 0;
			sum -= num_Rpieces;
			if (sum == 0)
				continue;
			if (turn == 1) {
				turn = 2;
				PL1 = 0;
			}
			else {
				turn = 1;
				PL1 = 1;
			}
		}
	}
}


int main()
{
	retain_scoreboard(scoreboard, biggest_size);
	while (true) {
		if (ops) {
			system("CLS"); {
				Nim_Game();
				if (Sound) {
					PlaySound(TEXT("Data\\Nim_Game.wav"), NULL, SND_SYNC);
				}
				menu();
				ops = 0;
			}
		}
		Variable = _getch();
		if (Variable == '1') {
			input_data();
			setting_table(num_columns);
			play(sum);
			ops = 1;
			if (valid == 'E' || valid == 'e') {
				break;
			}
		}
		else if (Variable == '2') {
			system("CLS");
			Instructions();
			ops = 1;
		}
		else if (Variable == '3') {
			system("CLS");
			Credits();
			ops = 1;
		}
		else if (Variable == '4') {
			system("CLS");
			view_scoreboard();
			ops = 1;
		}
		else if (Variable == '5') {
			break;
		}
		Sound = false;
	}
	system("CLS"); {
		End_Game();
		PlaySound(TEXT("Data\\End_Game.wav"), NULL, SND_SYNC);
	}
	return 0;
}
