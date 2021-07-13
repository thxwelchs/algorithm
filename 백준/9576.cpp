#include <bits/stdc++.h>

using namespace std;

const int MA = 1001;

int T, N, M;
vector<int> g[MA];
int bm[MA];
int vis[MA];

int dfs(int x) {

    for(int i = 0; i < g[x].size(); i++) {
        int an = g[x][i];

        if(vis[an]) {
            continue;
        }
        vis[an] = 1;

        if(!bm[an] || dfs(bm[an])) {
            bm[an] = x;
            return 1;
        }
    }

    return 0;
}

void solve() {
    cin >> N >> M;

    memset(bm, 0, sizeof(bm));
    memset(vis, 0, sizeof(vis));
    for(int i = 1; i <= M; i++) {
        g[i].clear();
    }

    for(int i = 1; i <= M; i++) {
        int a, b;
        cin >> a >> b;

        for(int j = a; j <= b; j++) {
            g[i].push_back(j);
        }
    }

    int ans = 0;
    for(int i = 1; i <= M; i++) {
        memset(vis, 0, sizeof(vis));
        if(dfs(i)) {
            ans++;
        }
    }

    cout << ans << '\n';
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