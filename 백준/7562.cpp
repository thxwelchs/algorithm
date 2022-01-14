#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

int T;
int l;
int y, x, y2, x2;
int vis[301][301];
int dy[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
int dx[8] = {-2, -1, 1, 2, -2, -1, 1, 2};

void bfs() {
    queue<pii> q;
    q.push({y, x});
    vis[y][x] = 1;

    while(!q.empty()) {
        pii p = q.front(); q.pop();

        int cy = p.first, cx = p.second;

        if(cy == y2 && cx == x2) {
            cout << vis[cy][cx] - 1 << '\n';
            return;
        }

        for(int i = 0; i < 8; i++) {
            int ny = cy + dy[i], nx = cx + dx[i];

            if(ny < 0 || ny >= l || nx < 0 || nx >= l) 
                continue;
            if(vis[ny][nx]) 
                continue;
            
            vis[ny][nx] = vis[cy][cx] + 1;
            q.push({ny, nx});
        }
    }

    cout << 0 << '\n';
}

void solve() {
    cin >> l;
    cin >> y >> x >> y2 >> x2;

    for(int i = 0; i < l; i++)
        for(int j = 0; j < l; j++)
            vis[i][j] = 0;
    bfs();
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(NULL); cout.tie(NULL);

   cin >> T;

   while(T--) {
       solve();
   }

   return 0;
}