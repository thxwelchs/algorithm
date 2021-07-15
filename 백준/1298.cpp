#include <bits/stdc++.h>

using namespace std;

int N, M;

const int MA = 101;

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

int main() {
   ios::sync_with_stdio(false);
   cin.tie(NULL); cout.tie(NULL);

   cin >> N >> M;

   for(int i = 0; i < M; i++) {
       int a, b;
       cin >> a >> b;
       g[a].push_back(b);
   }

   int ans = 0;

   for(int i = 1; i <= N; i++) {
       memset(vis, 0, sizeof(vis));
       if(dfs(i)) {
           ans++;
       }
   }

   cout << ans;

   return 0;
}