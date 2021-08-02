#include <bits/stdc++.h>

using namespace std;

using pii = pair<int, int>;

const int MAX = 1001;
const int INF = 2e9;

int N, M;
vector<pii> g[MAX];
int dist[MAX];
int recover[MAX];
int K;

void dij() {
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    for(int i = 2; i <= N; i++) {
        dist[i] = INF;
    }
    pq.push({0, 1});

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
                // 내가 다음에 가려고 할 정점의 거리가 그 전에 계산했던 값보다 현재 정점을 경유해서 가는 경유가 더 최단경로 일 경우 갱신
                // 다음에 가려고 할 정점의 최단경로 간선을 복구
                // 왜냐하면 1번(슈퍼컴퓨터) 정점에서 갈 수 있는 경로 중 최단경로로 간선을 살려야 하는데, 
                // 최단경로 간선이라는것은? 다익스트라에서 갱신될 때의 경로를 의미한다.

                // 도착 정점의 최단경로가 아직 정해지지 않은 경우에만 K를 세어준다.
                // 도착 정점의 최단경로가 현재 정점보다 이후에 다른 정점을 경유해 갱신되어질 때도 세어지면 중복으로 세어지기 때문에
                if(!recover[there]) {
                    K++;
                }

                // 회선을 살려야 할 정보 저장 (이것은 there에 대해 여러번 갱신되더라도 here값이 결국 가장 최단경로 일 때 마지막 갱신이 될 것)
                recover[there] = here;

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
       int A, B, C;
       cin >> A >> B >> C;

       g[A].push_back({B, C});
       g[B].push_back({A, C});
   }

   dij();

   cout << K << '\n';

   for(int i = 1; i <= N; i++) {
       if(recover[i]) {
           cout << i << ' ' << recover[i] << '\n';
       }
   }

   return 0;
}