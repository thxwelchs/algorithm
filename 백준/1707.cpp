#include <bits/stdc++.h>

using namespace std;

using pii = pair<int, int>;

const int MA = 2e4 + 1;
int vis[MA]; // 0이면 방문 안 함, 1이면 Group 1을 배정했음, 2이면 Group 2를 배정했음
vector<int> g[MA];

bool bfs(int st){
    queue<int> q;
    q.push(st);
    vis[st] = 1;

    while (!q.empty())
    {
        int n = q.front();
        int group = vis[n];
        q.pop();

        for(int i = 0; i < g[n].size(); i++) {
            int nn = g[n][i];
            if(vis[nn] == vis[n]) {
                return false;
            }

            if(vis[nn]) {
                continue;
            }
            vis[nn] = vis[n] == 1 ? 2 : 1;

            q.push(nn);
        }
    }

    return true;
}

void solve() {
    int V, E;
    cin >> V >> E;

    memset(vis, 0, sizeof(vis));
    for(int i = 1; i <= V; i++) {
        g[i].clear();
    }

    for(int i = 0; i < E; i++) {
        int v1, v2;
        cin >> v1 >> v2;

        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }

    for (int i = 1; i <= V; i++) {
        if(!vis[i] && !bfs(i)) {
            cout << "NO" << '\n';
            return;
        }
    }

    cout << "YES" << '\n';
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(NULL); cout.tie(NULL);

   int K;
   cin >> K;

   while(K--) {
       solve();
   }

   return 0;
}