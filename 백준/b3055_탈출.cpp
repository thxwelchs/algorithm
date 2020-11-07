#include<iostream>
#include<queue>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

using namespace std;

// 백준 3055 탈출
// https://www.acmicpc.net/problem/3055

const int MAX = 51;

int R, C;
char forest[MAX][MAX];
bool visit[MAX][MAX] = { false, };
queue<pair<int, int>> water;
queue<pair<int, int>> start;
int end_x, end_y;
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0 ,0 };

int BFS() {
	int cnt = 0;
	while (!start.empty()) {
		cnt++;
		int water_size = water.size();
		for (;water_size--;) {
			int x = water.front().first;
			int y = water.front().second;
			water.pop();

			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
				if (forest[nx][ny] == 'X' || forest[nx][ny] == 'D' || forest[nx][ny] == '*') continue;
				water.push(make_pair(nx, ny));
				forest[nx][ny] = '*';
			}
		}

		int start_size = start.size();
		for (;start_size--;) {
			int x = start.front().first;
			int y = start.front().second;
			start.pop();

			visit[x][y] = true;
			if (x == end_x && y == end_y) {
				cout << cnt - 1 << endl;
				return 0;
			}

			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
				if (forest[nx][ny] == 'X' || forest[nx][ny] == '*' || visit[nx][ny]) continue;
				visit[nx][ny] = true;
				start.push(make_pair(nx, ny));
			}
		}
	}
	cout << "KAKTUS" << endl;
	return 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> R >> C;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> forest[i][j];
			if (forest[i][j] == 'S') start.push(make_pair(i, j));
			else if (forest[i][j] == 'D') { end_x = i; end_y = j; }
			else if (forest[i][j] == '*') water.push(make_pair(i, j));
		}
	}

	BFS();
	return 0;
}