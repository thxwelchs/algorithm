#include <bits/stdc++.h>

using namespace std;

int N, M;
char arr[51][51];
int vis[51][51][64];
// 방문을 하긴 하되.. y, x 뿐만 아니라 어떤 key를 가진 상태로 방문하는지까지 체크되어야 한다.
// 1 1 1 1 1 1 (63) key 보유 표현
// a b c d e f
int dirY[4] = { -1, 0, 1, 0};
int dirX[4] = { 0, 1, 0, -1};
queue<tuple<int, int, int>> q;

void bfs() {
    while(!q.empty()) {
        tuple<int, int, int> t = q.front();
        q.pop();

        int y = get<0>(t);
        int x = get<1>(t);
        int key = get<2>(t);

        if(arr[y][x] == '1') {
            cout << vis[y][x][key] - 1;
            return;
        } 

        for(int i = 0; i < 4; i++) {
            int ny = y + dirY[i];
            int nx = x + dirX[i];

            if(ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
            if(vis[ny][nx][key]) continue;
            if(arr[ny][nx] == '#') continue;

            // key를 보유하고 있지 않다면 다음 경로로 탐색할 수 없다.
            if(arr[ny][nx] >= 'A' && arr[ny][nx] <= 'F' && !(key & (1 << (arr[ny][nx] - 'A')))) continue;

            int nextKey = key;

            // key를 만나면 해당 key까지 보유한 상태로 갱신하고, 다음 경로로 탐색
            if(arr[ny][nx] >= 'a' && arr[ny][nx] <= 'f') {
                nextKey = key | (1 << (arr[ny][nx] - 'a'));
            } 

            vis[ny][nx][nextKey] = vis[y][x][key] + 1;
            q.push({ny, nx, nextKey});
        }
    }

    cout << -1;
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(NULL); cout.tie(NULL);

   cin >> N >> M;

   for(int i = 0; i < N; i++) {
       for(int j = 0; j < M; j++) {
           cin >> arr[i][j];

           if(arr[i][j] == '0') {
               q.push({i, j, 0});
               vis[i][j][0] = 1;
           }
       }
   }

   bfs();

   return 0;
}