#include <bits/stdc++.h>

using namespace std;

const int MAX = 1001;

int N, M, K;
int mp[MAX][MAX];
int vis[MAX][MAX][11][2];

int dirY[] = {-1, 0, 1, 0};
int dirX[] = {0, 1, 0, -1};

struct Node {
    int y, x, k, isNight;
    Node(int _y, int _x, int _k, int _isNight) : y(_y) , x(_x), k(_k), isNight(_isNight){} // 멤버 이니셜라이저 : 1번 방법
};

void bfs() {
    queue<Node> q;

    q.emplace(1, 1, 0, 0);
    vis[1][1][0][0] = 1;

    while(!q.empty()) {
        Node n = q.front();
        q.pop();

        auto &here = vis[n.y][n.x][n.k][n.isNight];

        if(n.y == N && n.x == M) {
            cout << here;
            return;
        }

        if(!vis[n.y][n.x][n.k][1 - n.isNight]) {
            q.emplace(n.y, n.x, n.k, 1 - n.isNight);
            vis[n.y][n.x][n.k][1 - n.isNight] = here + 1;
        }f

        for(int i = 0; i < 4; i++) {
            int ny = n.y + dirY[i];
            int nx = n.x + dirX[i];

            if (ny > N || ny < 1 || nx > M || nx < 1)
            {
                continue;
            }
            if(vis[ny][nx][n.k][1 - n.isNight]) {
                continue;
            }

            if(mp[ny][nx] && n.k < K && !n.isNight) {
                q.emplace(ny, nx, n.k + 1, 1 - n.isNight);
                // q.push_back({ny, nx, n.k+1, 1-n.isNight}); : 2번 방법
                vis[ny][nx][n.k + 1][1 - n.isNight] = here + 1;
                continue;
            }

            if(!mp[ny][nx]) {
                q.emplace(ny, nx, n.k, 1 - n.isNight);
                vis[ny][nx][n.k][1 - n.isNight] = here + 1;
            }
        }
    }

    cout << -1;
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(NULL); cout.tie(NULL);

   cin >> N >> M >> K;

   for(int i = 1; i <= N; i++) {
       string s;
       cin >> s;
       for(int j = 1; j <= M; j++) {
           mp[i][j] = s[j - 1] - '0';
       }
   }

   bfs();
   return 0;
}