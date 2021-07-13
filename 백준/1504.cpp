#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

const int MA = 800;
const int INF = 2e9;

int N, E, v1, v2;
vector<pii> v[MA + 1];

// 여러 경로를 거쳐야 하는 최단경로 라면?
// s -> v1 -> v2 -> e
// 다익스트라(s, v1) + 다익스트라(v1, v2) + 다익스트라(v2, e) 이런식의 여러번의 다익스트라로 구할 수 있다
// 어차피 같은 그래프 상에서 최단경로 끼리의 합이기 때문에 결론적으로는 최단경로이다.

vector<int> dij(int start) {
    vector<int> dist(N + 1, INF);
    dist[start] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.emplace(0, start);

    while(!pq.empty()) {
        pii hp = pq.top(); pq.pop();

        int hdist = hp.first, here = hp.second;
        if(hdist > dist[here]) {
            continue;
        }

        for(int i = 0; i < v[here].size(); i++) {
            pii tp = v[here][i];
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

   cin >> N >> E;

   for(int i = 0; i < E; i++) {
       int a, b, c;
       cin >> a >> b >> c;
       v[a].emplace_back(b, c);
       v[b].emplace_back(a, c);
   }

   cin >> v1 >> v2;

   vector<int> res = dij(1);

   if(res[v1] == INF || res[v2] == INF) {
       cout << -1;
   } else {
        cout << min(res[v1] + dij(v1)[v2] + dij(v2)[N], res[v2] + dij(v2)[v1] + dij(v1)[N]); 
   }
   
   return 0;
}