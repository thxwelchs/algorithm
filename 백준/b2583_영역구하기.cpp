#include<bits/stdc++.h>

using namespace std;

// 백준 2583 영역 구하기
// https://www.acmicpc.net/problem/2583

int M, N, K;
int arr[100][100];
bool v[100][100];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
vector<int> a;
queue<pair<int, int> > q;

int bfs(int y, int x) {
    int c = 0;
    // c++;
    q.push(make_pair(y, x));
    v[y][x] = true;
    // for(int i = 0; i < 4; i++) {
    //     int ny = y + dy[i];
    //     int nx = x + dx[i];
    //     if(ny < 0 || ny > M - 1 || nx < 0 || nx > N - 1 || v[ny][nx] || arr[ny][nx]) continue;
    //     v[ny][nx] = true;
    //     dfs(ny, nx);
    // }
    while(!q.empty()) {
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();
        c++;

        for(int i = 0; i < 4; i++) {
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            if(ny < 0 || ny > M - 1 || nx < 0 || nx > N - 1 || v[ny][nx] || arr[ny][nx]) continue;
            v[ny][nx] = true;
            q.push(make_pair(ny, nx));
        }
    }

    return c;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> M >> N >> K;

    for(int i = 0; i < K; i++) {
        int lx, ly, rx, ry;
        cin >> lx >> ly >> rx >> ry;

        int si = M - max(ly, ry);
        int ei = si + abs(ly - ry);

        int sj = min(lx, rx);
        int ej = max(lx, rx);

        for(int j = si; j < ei; j++) {
            for(int k = sj; k < ej; k++) {
                arr[j][k] = 1;
            }
        }
    }

    int cnt = 0;

    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            if(v[i][j] || arr[i][j]) continue;
            v[i][j] = true;
            cnt++;
            // c = 0;
            a.push_back(bfs(i, j));
            // a.push_back(c);
        }
    }

    sort(a.begin(), a.end());

    cout << cnt << '\n';
    for(int i = 0; i < a.size(); i++) {
        cout << a[i] << ' ';
    }
    
    return 0;
}