#include <bits/stdc++.h>

using namespace std;

int N;
int arr[26][26];

int dirY[4] = { -1, 0, 1, 0 };
int dirX[4] = { 0, 1, 0, -1 };
int vis[26][26];

vector<int> ans;

void bfs(int y, int x) {
	queue<tuple<int, int> > q;
	/*memset(vis, 0, sizeof(vis));*/

	vis[y][x] = 1;
	q.push({ y, x });

	int cnt = 1;
	while (!q.empty()) {
		tuple<int, int> t = q.front(); q.pop();

		int py = get<0>(t);
		int px = get<1>(t);
		
		for (int i = 0; i < 4; i++) {
			int ny = py + dirY[i];
			int nx = px + dirX[i];

			if (ny < 0 || ny >= N || nx < 0 || nx >= N) 
				continue;
			if (arr[ny][nx] == 0)
				continue;
			if (vis[ny][nx])
				continue;

			vis[ny][nx] = 1;
			cnt++;
			
			q.push({ ny, nx });
		}
	}
	
	ans.push_back(cnt);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < N; j++) {
			arr[i][j] = s[j] - '0';
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j] != 0 && !vis[i][j]) {
				bfs(i, j);
			}
		}
	}

	sort(ans.begin(), ans.end());

	cout << ans.size() << '\n';
	for (int _n : ans) {
		cout << _n << '\n';
	}

	return 0;
}