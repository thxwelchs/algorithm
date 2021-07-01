#include <bits/stdc++.h>

using namespace std;

// 전형적인 트리의 부모를 찾는 문제, 아마 두고두고 쓰게 될듯?

const int MA = 100000;
int N;

vector<int> v[MA + 1];
int vis[MA + 1];
int par[MA + 1];

void dfs(int n) {
	for (int _n : v[n]) {
		if (vis[_n]) continue;
		vis[_n] = 1;
		par[_n] = n;
		dfs(_n);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;

	for (int i = 0; i < N - 1; i++) {
		int v1, v2;

		cin >> v1 >> v2;

		v[v1].push_back(v2);
		v[v2].push_back(v1);
	}

	vis[1] = 1;
	dfs(1);

	for (int i = 2; i <= N; i++) {
		cout << par[i] << '\n';
	}

	return 0;
}