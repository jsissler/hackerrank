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

vector<int> array_left_rotation(vector<int> a, int n, int k) {
	assert(a.size() == n);
	vector<int> rotated = vector<int>(n);
	for (int i = 0; i < n; i++) {
		rotated[i] = a[(i + k) % n];
	}
	return rotated;
}

int main() {
	int status = 0;

	try {
		int n;
		int k;

		cin >> n >> k;

		if (n <= 0 || n > 1e5) {
			throw "n must be >= 1 and <= 10**5";
		}

		if (k <= 0 || k > n) {
			throw "k must be >= 1 and <= n";
		}

		vector<int> a(n);
		for (int a_i = 0; a_i < n; a_i++) {
			cin >> a[a_i];
		}

		vector<int> output = array_left_rotation(a, n, k);
		for (int i = 0; i < n; i++)
			cout << output[i] << " ";
		cout << endl;
	} catch (const char* msg) {
		cerr << "ERROR: " << msg << endl;
		status = 1;
	} catch (const exception& e) {
		cerr << "ERROR: " << e.what() << endl;
		status = 1;
	} catch (...) {
		cerr << "ERROR!" << endl;
		status = 1;
	}
	return status;
}
