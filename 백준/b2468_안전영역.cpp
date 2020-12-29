#include<bits/stdc++.h>

using namespace std;

// 백준 2468 안전 영역
// https://www.acmicpc.net/problem/2468

int N;
int answer = 0;
int arr[100][100];
bool v[100][100];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

void dfs(int y, int x, int r) {
    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || ny > N - 1 || nx < 0 || nx > N - 1 || v[ny][nx] || arr[ny][nx] <= r) continue;
        v[ny][nx] = true;
        dfs(ny, nx, r);
    }

}

void go(int r) {
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            v[i][j] = false;
        }
    }

    int cnt = 0;

    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            if(arr[i][j] <= r || v[i][j]) continue;
            v[i][j] = true;
            cnt++;
            dfs(i, j, r);
        }
    }

    answer = max(answer, cnt);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            cin >> arr[i][j];
        }
    }

    for(int i=0;i<=100;i++) {
        go(i);
    }

    cout << answer;
    
    return 0;
}