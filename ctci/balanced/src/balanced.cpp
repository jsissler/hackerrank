#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <assert.h>
#include <stack>
using namespace std;

bool is_balanced(string s) {
	static const string BRACKETS("[]{}()");

	assert(s.size() >= 1 && s.size() <= 1e3);
	for (auto& c : s) {
		assert(BRACKETS.find(c) != string::npos);
	}

	stack<char> cstack;

	for (auto& c : s) {
		if (cstack.empty())
			cstack.push(c);
		else {
			int top = BRACKETS.find(cstack.top());
			int newtop = BRACKETS.find(c);

			if (newtop == top + 1 && (top % 2) == 0)
				cstack.pop();
			else
				cstack.push(c);
		}
	}

	return cstack.empty();
}

int main() {
	int status = 0;
	try {
		unsigned n = 0;
		cin >> n;
		assert(n >= 1 && n <= 1e3);
		vector<string> tests;
		static const string BRACKETS("[]{}()");
		for (unsigned i = 0; i < n; i++) {
			string s;
			cin >> s;
			assert(s.size() >= 1 && s.size() <= 1e3);
			for (auto& c : s) {
				assert(BRACKETS.find(c) != string::npos);
			}
			tests.push_back(s);
		}

		for (auto& s : tests) {
			if (is_balanced(s))
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}
	} catch (...) {
		cerr << "exception!" << endl;
		status = 1;
	}
	return status;
}
