#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <queue>
#include <functional>
using namespace std;

double median(vector<int> &v) {
	size_t n = v.size() / 2;
	nth_element(v.begin(), v.begin() + n, v.end());
	int vn = v[n];
	if (v.size() % 2 == 1) {
		return vn;
	} else {
		nth_element(v.begin(), v.begin() + n - 1, v.end());
		return 0.5 * (vn + v[n - 1]);
	}
}

double median(int value, double& median,
		priority_queue<int, vector<int>, greater<int> >& minh,
		priority_queue<int, vector<int>, less<int> >& maxh) {
	/* If the new element is greater than the current median, it goes to the min-heap.
	 * If it is less than the current median, it goes to the max heap.
	 */
	if (value >= median)
		minh.push(value);
	else if (value < median)
		maxh.push(value);
	/*
	 * If the sizes of the heaps differ by more than one element,
	 * extract the min/max from the heap with more elements and
	 * insert it into the other heap.
	 * */
	if ((minh.size() - maxh.size()) == 2) {
		maxh.push(minh.top());
		minh.pop();
	} else if ((maxh.size() - minh.size()) == 2) {
		minh.push(maxh.top());
		maxh.pop();
	}
	/*
	 * When the min-heap contains one more element than the max-heap,
	 * the median is in the top of the min-heap.
	 * And when the max-heap contains one more element than the min-heap,
	 * the median is in the top of the max-heap.
	 */
	if ((minh.size() - maxh.size()) == 1)
		median = minh.top();
	else if ((maxh.size() - minh.size()) == 1)
		median = maxh.top();
	else
		median = (double(minh.top()) + double(maxh.top())) / 2.0;

	return median;
}

int main() {
	int n;
	cin >> n;
	vector<int> a;
	priority_queue<int, vector<int>, greater<int> > minh;
	priority_queue<int, vector<int>, less<int> > maxh;
	double m = 0.0;
	for (int a_i = 0; a_i < n; a_i++) {
		int j;
		cin >> j;
		a.push_back(j);
		printf("%.1f\n", median(a));
		printf("%.1f\n", median(j, m, minh, maxh));
	}
	return 0;
}
