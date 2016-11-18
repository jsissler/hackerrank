#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <fstream>
#include <assert.h>
using namespace std;

class MyQueue {
private:
	int popcnt = 0;

public:
	stack<int> stack_newest_on_top, stack_oldest_on_top;

	void push(int x) {
		stack_newest_on_top.push(x);
	}

	void pop() {
		assert(popcnt < stack_newest_on_top.size());

		if (++popcnt == stack_newest_on_top.size()) {
			stack_oldest_on_top = stack<int>();
			stack_newest_on_top = stack<int>();
			popcnt = 0;
		} else if (!stack_oldest_on_top.empty())
			stack_oldest_on_top.pop();
	}

	int front() {
		if (stack_oldest_on_top.empty()) {
			stack<int> tmp = stack_newest_on_top;
			const int n = tmp.size() - popcnt;
			for (int i = 0; i < n; i++) {
				stack_oldest_on_top.push(tmp.top());
				tmp.pop();
			}
		}
		return stack_oldest_on_top.top();
	}
};

int main() {
	clock_t start = clock();
	MyQueue q1;
	int q, type, x;
	ifstream ifs("etc/input06.txt");
	ofstream ofs("etc/run06.txt");

	ifs >> q;

	for (int i = 0; i < q; i++) {
		ifs >> type;
		if (type == 1) {
			ifs >> x;
			q1.push(x);
		} else if (type == 2) {
			q1.pop();
		} else
			ofs << q1.front() << endl;
	}
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	clock_t end = clock();
	double time = (double) (end - start) / CLOCKS_PER_SEC * 1000.0;
	cout << time << "s" << endl;
	return 0;
}

int main2() {
	MyQueue q1;
	int q, type, x;

	cin >> q;

	for (int i = 0; i < q; i++) {
		cin >> type;
		if (type == 1) {
			cin >> x;
			q1.push(x);
		} else if (type == 2) {
			q1.pop();
		} else
			cout << q1.front() << endl;
	}
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	return 0;
}

