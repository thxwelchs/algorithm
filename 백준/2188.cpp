#include <bits/stdc++.h>

using namespace std;

const int MA = 201;

int N, M;
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

   for(int i = 1; i <= N; i++) {
       int s;
       cin >> s;

       for(int j = 0; j < s; j++) {
           int ii;
           cin >> ii;
           g[i].push_back(ii);
       }
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