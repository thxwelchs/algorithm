#include<bits/stdc++.h>

using namespace std;

// 백준 2178 미로 탐색
// https://www.acmicpc.net/problem/2178

int N, M;
int arr[100][100];
bool v[100][100];

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

bool isInRange(int y, int x) {
    return y < N && y >= 0 && x < M && x >= 0 && arr[y][x];
}

int bfs() {
    int cnt = 1000000;
    queue<pair<int, pair<int, int>>> q;
    q.push(make_pair(1, make_pair(0, 0)));
    v[0][0] = true;

    while(!q.empty()) {
        int c = q.front().first;
        int y = q.front().second.first;
        int x = q.front().second.second;
        q.pop();

        if(y == N - 1 && x == M - 1) {
            cnt = min(cnt, c);
        }

        for(int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(!isInRange(ny, nx) || v[ny][nx]) continue;

            q.push(make_pair(c + 1, make_pair(ny, nx)));
            v[ny][nx] = true;
        }
    }

    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;

    for(int i = 0; i < N; i++) {
        string a;
        cin >> a;
        for(int j = 0; j < M; j++) {
            // cin >> arr[i][j];
            arr[i][j] = a[j] - '0';
        }
    }

    cout << bfs();
    
    return 0;
}