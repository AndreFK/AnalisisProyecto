// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <algorithm>

#include <iostream>
#include <queue>

using namespace std;

int T = 0;
int eval = 0;
int list = 0;

vector<pair<int, int>> santaList;

void add(int id, int gT) {
	santaList.push_back(make_pair(id, gT));
}

int isGood(int goodThings, int badThings) {
	if (goodThings - badThings > T) {
		return 1;
	}
	else {
		return 0;
	}
}

void replaceValue(int id, int val) {
	for (auto & n : santaList) {
		if (n.first == id) {
			n.second = val;
		}
	}
}

int find(int x) {
	for (pair<int, int>& n : santaList) {
		if (n.first == x) {
			return n.second;
		}
	}
}

int main()
{
	int vectorSize = 0;
	cin >> T;
	cin >> vectorSize;
	for (int i = 0; i < vectorSize; i++) {
		int id = 0;
		int goodT = 0;
		cin >> id;
		cin >> goodT;
		add(id, goodT);
	}
	int checkIfGood = 0;
	cin >> checkIfGood;
	for (int i = 0; i < checkIfGood; i++) {
		int bId = 0;
		int badT = 0;
		cin >> bId;
		cin >> badT;
		cout << isGood(find(bId), badT);
		replaceValue(bId, (isGood(find(bId), badT)));
	}

	return 0;
}

