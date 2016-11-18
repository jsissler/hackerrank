#include <iostream>
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

/*
 Detect a cycle in a linked list. Note that the head pointer may be 'NULL' if the list is empty.

 A Node is defined as:
 struct Node {
 int data;
 struct Node* next;
 }
 */

struct Node {
	int data;
	struct Node* next;
};

bool has_cycle(Node* head) {
	set<Node*> visited;
	while (head && visited.size() <= 100) {
		if (visited.find(head) != visited.end())
			return true;
		visited.insert(head);
		head = head->next;
	}
	return false;
}

int main() {
	cout << has_cycle(0) << endl;
	Node* one = new Node;
	one->data = 1;
	Node* two = new Node;
	two->data = 2;
	one->next = two;
	Node* three = new Node;
	three->data = 3;
	two->next = three;
	three->next = two;
	cout << has_cycle(one) << endl;
}
