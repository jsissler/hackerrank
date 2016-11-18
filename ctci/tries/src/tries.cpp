#include <map>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
	char data;
	bool word;
	int word_count;
	map<char, Node*> children;
};

void add(Node* root, string word) {
	unsigned i = 0;
	vector<Node*> traversed;
	// Walk tree until character is not found. Remember
	// traversed nodes as we want to increment word counts if
	// word is not a duplicate.
	for (; i < word.size(); i++) {
		map<char, Node*>::iterator it = root->children.find(word[i]);
		if (it == root->children.end())
			break;
		else {
			root = it->second;
			traversed.push_back(root);
		}
	}
	// If not a duplicate, increment word counts of traversed nodes.
	if (i < word.size() || !root->word) {
		for (auto p : traversed)
			p->word_count++;
	}
	// Add new Node for each remaining character of word.
	for (; i < word.size(); i++) {
		Node* node = new Node;
		node->data = word[i];
		node->word = i == word.size() - 1;
		node->word_count = 1;
		root->children[node->data] = node;
		root = node;
	}
}

int find(Node* root, string pattern) {
	int words = 0;
	for (auto c : pattern) {
		map<char, Node*>::const_iterator it = root->children.find(c);
		if (it == root->children.end())
			return 0;
		else {
			root = it->second;
			words = root->word_count;
		}
	}
	return words;
}

int main() {
	Node* root = new Node();
	int n;

	cin >> n;

	for (int i = 0; i < n; i++) {
		string cmd, arg;
		cin >> cmd;
		cin >> arg;
		if (cmd == "add") {
			add(root, arg);
		} else if (cmd == "find") {
			int matches = find(root, arg);
			cout << matches << endl;
		}
	}
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	return 0;
}
