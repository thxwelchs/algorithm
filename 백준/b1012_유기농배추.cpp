#include<bits/stdc++.h>

using namespace std;

// 백준 1012 유기농 배추
// https://www.acmicpc.net/problem/1012

int T, M, N, K;
int arr[50][50];
bool v[50][50];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

void dfs(int y, int x, int n, int m) {
    // if(y < 0 || y > n - 1 || x < 0 || x > m - 1 ) return;
    // v[y][x] = true;
    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || ny > n - 1 || nx < 0 || nx > m - 1 || v[ny][nx] || !arr[ny][nx]) continue;
        v[ny][nx] = true;
        dfs(ny, nx, n, m);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> T;

    while(T--) {
        cin >> M >> N >> K;
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                arr[i][j] = 0;
                v[i][j] = false;
            }
        }
        while(K--) {
            int y, x;
            cin >> y >> x;
            arr[x][y] = 1;
        }

        int cnt = 0;
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                if(v[i][j] || !arr[i][j]) continue;
                v[i][j] = true;
                cnt++;

                dfs(i, j, N, M);
            }
        }

        cout << cnt << '\n';
    }

    return 0;
}