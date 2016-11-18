#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <assert.h>

using namespace std;

bool ransom_note(vector<string> magazine, vector<string> ransom) {
	map<string, int> count;
	for (auto s : magazine) {
		if (count.find(s) == count.end())
			count[s] = 0;
		count[s]++;
	}
	for (auto s : ransom) {
		if (count.find(s) == count.end() || --count[s] < 0)
			return false;
	}
	return true;
}

int main() {
	int m;
	int n;
	cin >> m >> n;
	assert(1 <= m && m <= 30000 && 1 <= n && n <= 30000);
	vector<string> magazine(m);
	for (int magazine_i = 0; magazine_i < m; magazine_i++) {
		cin >> magazine[magazine_i];
		assert(
				1 <= magazine[magazine_i].size()
						&& magazine[magazine_i].size() <= 5);
	}
	vector<string> ransom(n);
	for (int ransom_i = 0; ransom_i < n; ransom_i++) {
		cin >> ransom[ransom_i];
		assert(1 <= ransom[ransom_i].size() && ransom[ransom_i].size() <= 5);
	}
	if (ransom_note(magazine, ransom))
		cout << "Yes\n";
	else
		cout << "No\n";
	return 0;
}
