#include <bits/stdc++.h>

using namespace std;

// 축사배정과 아예 동일하나, 최대 정점 번호만 달라진다.
const int MA = 1001;

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
        for(int j = 0; j < 2; j++) {
            memset(vis, 0, sizeof(vis));
            if(dfs(i)) {
                ans++;
            }
        }
    }

    cout << ans;

   return 0;
}