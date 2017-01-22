#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stdlib.h>
using namespace std;

struct Player {
	string name;
	int score;
};

static inline int compare(const Player& a, const Player& b) {
	const int result = a.score - b.score;
	if (result == 0)
		return b.name.compare(a.name);
	else
		return result;
}

static int partition(vector<Player>& players, int left, int right,
		const Player pivot) {
	while (left <= right) {
		while (compare(players[left], pivot) > 0)
			left++;
		while (compare(players[right], pivot) < 0)
			right--;
		if (left <= right) {
			swap(players[left], players[right]);
			left++;
			right--;
		}
	}
	return left;
}

static void qsort(vector<Player>& players, int left, int right) {
	if (left >= right)
		return;
	const int index = partition(players, left, right,
			players[(left + right) / 2]);
	qsort(players, left, index - 1);
	qsort(players, index, right);
}

vector<Player> comparator(vector<Player> players) {
	qsort(players, 0, players.size() - 1);
	return players;
}

int main() {
	int n;
	cin >> n;
	vector<Player> players;
	string name;
	int score;
	for (int i = 0; i < n; i++) {
		cin >> name >> score;
		Player p1;
		p1.name = name, p1.score = score;
		players.push_back(p1);
	}
	vector<Player> answer = comparator(players);
	for (unsigned i = 0; i < answer.size(); i++) {
		cout << answer[i].name << " " << answer[i].score << endl;
	}
	return 0;
}
