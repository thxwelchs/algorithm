#include <bits/stdc++.h>

using namespace std;

int M, N;

int dirY[4] = {-1, 0, 1, 0};
int dirX[4] = {0, 1, 0, -1};
int arr[1001][1001];
int vis[1001][1001];

int ans;

queue<pair<int, int>> q; 

void bfs() {
    while(!q.empty()) {
        pair<int, int> t = q.front();
        q.pop();
        int y = t.first, x = t.second;

        for(int i = 0; i < 4; i++) {
            int ny = y + dirY[i], nx = x + dirX[i];
            if(ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
            if(vis[ny][nx] || arr[ny][nx] != 0) continue;

            arr[ny][nx] = 1;
            vis[ny][nx] = vis[y][x] + 1;
            q.push({ny, nx});
        }
    }
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(NULL); cout.tie(NULL);

   cin >> M >> N;

   int zeroCnt = 0;

   for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> arr[i][j];

            if(arr[i][j] == 1) {
                q.push({i, j});
            } else if(arr[i][j] == 0) {
                zeroCnt++;
            }
        }
   }

   if(!zeroCnt) {
       cout << 0;
   } else {
        bfs();
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                if(arr[i][j] == 0) {
                    cout << - 1;
                    return 0;
                }
                if(vis[i][j]) {
                    ans = max(ans, vis[i][j]);
                }
            }
        }

        cout << ans;
   }

   return 0;
}
