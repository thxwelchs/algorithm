#include <bits/stdc++.h>

using namespace std;

using pii = pair<int, int>;

const int MAX = 300001;

int N, M, K, X;

vector<pii> g[MAX];
int dist[MAX];
const int INF = 2e9;

void dij() {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    for(int i = 1; i <= N; i++) {
        if(i == X) {
            continue;
        }
        dist[i] = INF;
    }

    pq.push({0, X});

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
            int tdist = tp.second;

            if(dist[there] > dist[here] + tdist) {
                dist[there] = dist[here] + tdist;
                pq.push({dist[there], there});
            }
        }
    }
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(NULL); cout.tie(NULL);

   cin >> N >> M >> K >> X;

   for(int i = 0; i < M; i++) {
       int A, B;
       cin >> A >> B;
       g[A].push_back({B, 1});
   }

   dij();

   int isKDistCities = 0;
   for(int i = 1; i <= N; i++) {
       if(dist[i] == K) {
           isKDistCities++;
           cout << i << '\n';
       }
   }

   if(!isKDistCities) {
       cout << -1;
   }

   return 0;
}