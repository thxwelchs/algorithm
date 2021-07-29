#include <bits/stdc++.h>

using namespace std;

using pii = pair<int, int>;

const int MAX = 1001;
const int INF = 2e9;

int N, M;
int ST, EN;

vector<pii> g[MAX];
int dist[MAX];

void dij() {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    for(int i = 1; i <= N; i++) {
        if(i == ST) {
            continue;
        }
        dist[i] = INF;
    }

    pq.push({0, ST});

    while(!pq.empty()) {
        pii hp = pq.top(); pq.pop();
        int hdist = hp.first;
        int here = hp.second;

        if(hdist > dist[here]) {
            continue;
        }

        for(int i = 0; i < g[here].size(); i++) {
            pii tp = g[here][i];
            int there = tp.first;
            int weight = tp.second;

            if(dist[there] > dist[here] + weight) {
                dist[there] = dist[here] + weight;
                pq.push({dist[there], there});
            }
        }
    }

}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(NULL); cout.tie(NULL);

   cin >> N >> M;

   for(int i = 0; i < M; i++) {
       int s, e, w;
       cin >> s >> e >> w;

       g[s].push_back({e, w});
   }

   cin >> ST >> EN;

   dij();

   cout << dist[EN];

   return 0;
}