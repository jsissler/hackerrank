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
#include <time.h>

using namespace std;

int number_needed(string a, string b) {
	auto count = 0;
	vector<int> freq(26, 0);
	for (auto c : a) {
		++freq[c - 'a'];
	}
	for (auto c : b) {
		--freq[c - 'a'];
	}
	for (auto val : freq) {
		count += abs(val);
	}
	return count;
}

// Non-brute force.
int number_needed2(string a, string b) {
	if (a.size() == 0 || b.size() == 0 || a.size() > 1e4 || b.size() > 1e4)
		throw "strings must be of length 1-1e4";

	int deletions = 0;

	vector<char> asort(a.begin(), a.end());
	sort(asort.begin(), asort.end());

	vector<char> bsort(b.begin(), b.end());
	sort(bsort.begin(), bsort.end());

	vector<char>::iterator ait = asort.begin();
	vector<char>::iterator bit = bsort.begin(), last_bit = bit;

	while (ait != asort.end() && bit != bsort.end()) {
		const char c = *ait;

		bit = lower_bound(bit, bsort.end(), c);

		// If c is not in "b" then delete all occurrences of c in "a".
		if (bit == bsort.end() || *bit != c) {
			while (*ait == c) {
				ait++;
				deletions++;
			}
		}
		// c is in "b".
		else {
			// Delete all characters from last_bit to bit as these
			// are in "b" but not in "a".
			deletions += bit - last_bit;

			// Move past common c in both "a" and "b".
			while (*ait == c && ait != asort.end() && *bit == c
					&& bit != bsort.end()) {
				ait++;
				bit++;
			}

			// Delete excess c in either "a" or "b".
			if (*ait == c) {
				while (ait != asort.end() && *ait == c) {
					deletions++;
					ait++;
				}
			} else {
				while (bit != bsort.end() && *bit == c) {
					deletions++;
					bit++;
				}
			}

			last_bit = bit;
		}
	}

	// Any characters left in "b" are not in "a".
	deletions += bsort.end() - bit;

	// Any characters left in "a" are not in "b".
	deletions += asort.end() - ait;

	return deletions;
}

int main() {
	string a;
	cin >> a;
	string b;
	cin >> b;
	cout << number_needed(a, b) << endl;

	clock_t start, end;
	double cpu_time_used;

	start = clock();
	for (int i = 0; i < 1000000; i++)
		number_needed(a, b);
	end = clock();
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	cout << "cpu_time_used: " << cpu_time_used << endl;
	return 0;
}
