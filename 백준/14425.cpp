#include <bits/stdc++.h>

const int SIZE = 30;
const int INF = 2000000000;

using namespace std;

typedef long long int ll;

struct Trie {
	Trie *node[SIZE];
	bool is_finish, is_child;

	Trie() {
		fill(node, node + SIZE, nullptr);
		is_finish = is_child = false;
	}

	~Trie() {
		for (int i = 0; i < SIZE; i++) {
			if (node[i])
				delete node[i];
		}
	}

	void insert(const string &word, int word_size, int index) {
		if (index >= word_size) {
			is_finish = true;
			return;
		}

		int word_index = word.at(index) - 'a';
		if (node[word_index] == NULL) {
			node[word_index] = new Trie();
			is_child = true;
		}
		node[word_index]->insert(word, word_size, index + 1);
	}

	bool find(const string &word, int word_size, int index) {
		bool res = false;
		if (index >= word_size) {
			if (is_finish)
				return true;
			else
				return false;
		}
		else if (index < word_size) {
			int word_index = word.at(index) - 'a';
			if (node[word_index] == NULL || is_finish == true || is_child == false) {
				return false;
			}

			res = node[word_index]->find(word, word_size, index + 1);
		}

		return res;
	}
};

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	Trie root;
	int N, M; cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string word; cin >> word;
		root.insert(word, word.size(), 0);
	}

	int cnt = 0;
	for (int i = 0; i < M; i++) {
		string word; cin >> word;
		if (root.find(word, word.size(), 0)) {
			cnt++;
		}
	}

	cout << cnt;

}