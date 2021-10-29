#include <bits/stdc++.h>

using namespace std;

struct Trie {
    bool finish;
    Trie *children[26];

    Trie() : finish(false) {
		fill(children, children + 26, nullptr);
    }

    ~Trie() {
        for (int i = 0; i < 26; i++) {
            if (children[i]) delete children[i];
        }
    }

    void insert(const char *c) {
        if (*c == 0) {
            finish = 1;
            return;
        }

        int idx = *c- 'a';

        if (!children[idx]) {
			children[idx] = new Trie();
		}

        children[idx] -> insert(c + 1);
    }

    bool find(const char *c) {
        if (*c == 0) return finish;

        int idx = *c- 'a';

        if (!children[idx]) {
			return false;
		}

        bool ret = children[idx] -> find(c+ 1);

        return ret;
    }
};

int main() {
    int N, M; 
	cin >> N >> M;

    Trie *root = new Trie();

    while (N--) {
		char w[501];
		cin >> w;

        root -> insert(w);
    }
    int ans = 0;

    while (M--) {
        char w[501]; 
		cin >> w;
        if (root -> find(w)) ans++;
    }

	cout << ans;
}