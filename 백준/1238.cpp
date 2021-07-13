#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

const int INF = 2e9;

// 단방향 그래프 일 때에는, 출발지, 목적지 간의 최단경로를 정방향 그래프에서 간선을 반전시킨 역방향 그래프를 형성하여 구할 수 있다.
// v1 -> v2 의 최단경로 (정방향 에서 구하면 된다.)
// v2 -> v1 의 최단경로 (역방향 에서 구하면 된다.)

int N, M ,X;
vector<vector<pii>> g(1001, vector<pii>());
vector<vector<pii>> rg(1001, vector<pii>());

vector<int> dij(vector<vector<pii>> &g) {
	vector<int> dist(1001, INF);
	dist[X] = 0;
    priority_queue < pii, vector<pii>, greater<pii> > pq;
	pq.emplace(0, X);

    while(!pq.empty()) {
        pii hp = pq.top(); pq.pop();
        int hdist = hp.first, here = hp.second;

        if(hdist > dist[here]) {
            continue;
        }

        for(int i = 0; i < g[here].size(); i++) {
            pii tp = g[here][i];
            int there = tp.first, weight = tp.second;

            if(dist[there] > dist[here] + weight) {
                dist[there] = dist[here] + weight;
                pq.emplace(dist[there], there);
            }
        }
    }
	return dist;
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(NULL); cout.tie(NULL);

   cin >> N >> M >> X;

   for(int i = 0; i < M; i++) {
       int s, e, t;
       cin >> s >> e >> t;
       g[s].emplace_back(e, t);
       rg[e].emplace_back(s, t);
   }

   vector<int> res = dij(g);
   vector<int> rres = dij(rg);

    int ans = 0;
   for(int i = 1; i <= N; i++) {
       ans = max(ans, rres[i] + res[i]);
   }
   cout << ans;

   return 0;
}