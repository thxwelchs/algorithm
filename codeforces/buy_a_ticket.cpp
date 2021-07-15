#include <bits/stdc++.h>

using namespace std;

// 여러 시작 정점에 대해 최단경로가 필요 할 땐? 임의의 시작정점을 만들고, 각 원래 시작정점들과 연결시켜준 채로, 임의의 시작정점으로부터의 다익스트라 진행
// 여기서는 콘서트 비용이 각 정점에 대해 비용이 발생하므로, 임의의 시작정점에서 원래의 시작정점으로의 간선에 콘서트 비용을 추가해준다.

typedef long long ll;

const int MA = 2e5 + 1;
const ll INF = 2e17 + 100;
typedef pair<int, ll> pill;
typedef pair<ll, int> plli;

int N, M;
ll W[MA];
ll dist[MA];
vector<pill> g[MA];

void dij() {
    priority_queue<plli, vector<plli>, greater<plli>> pq;
    // 임의의 시작정점 0, (초기비용, 0 에서 0으로 가는 비용은 0)
    pq.emplace(0, 0);

    while(!pq.empty()) {
        plli p = pq.top(); pq.pop();

        ll hdist = p.first;
        int here = p.second;

        if(hdist > dist[here]) {
            continue;
        }

        for(int i = 0; i < g[here].size(); i++) {
            pill tp = g[here][i];
            int there = tp.first;
            ll weight = tp.second;

            if(dist[there] > dist[here] + weight) {
                dist[there] = dist[here] + weight;
                pq.emplace(dist[there], there);
            }
        }
    }
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(NULL); cout.tie(NULL);

   cin >> N >> M;

   for(int i = 0; i < M; i++) {
       int u, v;
       ll w;
       cin >> u >> v >> w;

       g[u].emplace_back(v, w * 2);
       g[v].emplace_back(u, w * 2); // u -> v에 애초에 왕복 이동 비용을 설정해주었는데 역방향도 해주어야 하는가? 
   }

   for(int i = 1; i <= N; i++) {
       cin >> W[i];
       g[0].emplace_back(i, W[i]);
       g[i].emplace_back(0, W[i]);
   }

   for(int i = 1; i <= N; i++) {
       dist[i] = INF;
   }

   dij();

   for(int i = 1; i <= N; i++) {
       cout << dist[i] << ' ';
   }

   return 0;
}