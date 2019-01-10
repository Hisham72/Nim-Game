#pragma once
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
#define  del cin.clear();cin.ignore(100000, '\n');
using namespace std;


bool checker = 1, p = 1, ops = 1, isTheSame = true, isMisere = 0, isValid = 1, Sound = true;
int num_columns, sum = 0, pieces_of_column[26], num_pieces, num_Rpieces;
char table[20][26], Variable, index, valid;
string player1, player2, n_col;
map<char, long long>mp;




void check_col() {
	do {
		if (!checker) {
			cout << "Ops! Invalid input .. Number of columns must be from 1 to 26 .Please re - enter the number of columns : " << endl;
			n_col.clear();
		}
		checker = 0;
		getline(cin, n_col);
		for (int i = 0; i < n_col.size(); i++) {
			if (n_col[i] < '1' || n_col[i] > '9') {
				if (n_col[i] != '0') {
					p = 1;
					break;
				}
			}
			p = 0;
		}
		if (!p) {
			num_columns = stoll(n_col);
			if (num_columns > 26 || num_columns <= 0) {
				p = 1;
			}
		}
	} while (p);
}

void check_pec() {
	p = 1, n_col.clear(), checker = 1;
	do {
		if (!checker) {
			cout << "Ops! Invalid input .. Number of pieces must be from 1 to 20 .Please re - enter the number of pieces : " << endl;
			n_col.clear();
		}
		checker = 0;
		getline(cin, n_col);
		for (int i = 0; i < n_col.size(); i++) {
			if (n_col[i] < '1' || n_col[i]>'9') {
				if (n_col[i] != '0') {
					p = 1;
					break;
				}
			}
			p = 0;
		}
		if (!p) {
			num_pieces = stoll(n_col);
			if (num_pieces > 20 || num_pieces <= 0) {
				p = 1;
			}
		}
	} while (p);
}

void check_index() {
	p = 1, n_col.clear(), checker = 1;
	do {
		if (!checker) {
			cout << "Ops! Invalid input .. Enter new index" << endl;
			n_col.clear();
		}
		checker = 0;
		getline(cin, n_col);
		if (n_col.size() == 1) {
			for (int i = 0; i < n_col.size(); i++) {
				if (n_col[i] >= 'A' && n_col[i] <= 'Z' || n_col[i] >= 'a' && n_col[i] <= 'z') {
					p = 0;
				}
				else {
					p = 1;
					break;
				}
			}
		}
		if (!p) {
			if (n_col[0] >= 'A'&&n_col[0] <= 'Z' || n_col[0] >= 'a'&&n_col[0] <= 'z') {
				if (mp[n_col[0]] != '0') {
					index = n_col[0];
				}
				else {
					p = 1;
				}
			}
			else {
				p = 1;
			}
		}
	} while (p);
}


void check_player(string &player1, string &player2) {
	int player1_size = player1.size(), player2_size = player2.size();
	if (player1_size == player2_size) {
		for (int i = 0; i < player1_size; i++) {
			if (player1[i] != player2[i]) {
				isTheSame = false;
				break;
			}
		}
		if (isTheSame) {
			cout << " The player can't have the same names\n please re-enter the names again";
			cout << " Player1 name:";
			getline(cin, player1);
			cout << " Player2 name:";
			getline(cin, player2);
			check_player(player1, player2);
		}
		else {
			isTheSame = true;
		}
	}


}



void check_npec(int column) {
	checker = 1, n_col.clear(), p = 1;
	do {
		if (!checker) {
			cout << "Ops! Invalid input ... Please re - enter the number of pieces : " << endl;
			n_col.clear();
		}
		checker = 0;
		getline(cin, n_col);
		for (int i = 0; i < n_col.size(); i++) {
			if (n_col[i] < 48 || n_col[i]>57) {
				if (n_col[i] != '0') {
					p = 1;
					break;
				}
			}
			p = 0;
		}
		if (!p) {
			num_Rpieces = stoll(n_col);
			if (num_Rpieces > pieces_of_column[column] || num_Rpieces <= 0) {
				p = 1;
			}
		}
	} while (p);
}
