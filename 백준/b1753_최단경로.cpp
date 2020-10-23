#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

// 백준 1753 최단경로
// https://www.acmicpc.net/problem/1753

int V, E;
int K;
vector<pair<int, int> > nodes[20001];
int ds[20001];
const int INF = 2147000000;

// Min Heap 우선순위큐를 활용하는 다익스트라
void dijkstra(int start) {
    priority_queue<pair<int, int> > pq;
    pq.push({0, start});
    ds[start] = 0;

    while(!pq.empty()) {
        int distance = -pq.top().first;
        int current = pq.top().second; // start -> current 까지의 거리 비용
        pq.pop();

        // 현재 노드까지 오는 거리 비용이 미리 구해놓았던 비용보다 저렴하다면
        // 교체하지 않는다.
        if(ds[current] < distance) continue;

        // 다음 인접 노드 중에서 비용이 가장 저렴한 노드로 가기 위한 큐잉
        for(int i = 0; i < nodes[current].size(); i++) {
            int next = nodes[current][i].first;
            int nextDistance = distance + nodes[current][i].second;

            // 다음 노드까지 갈 비용이 기존에 구해놓았던 비용보다 저렴하다면 저렴한 비용으로 교체한다. 
            if(nextDistance < ds[next]) {
                ds[next] = nextDistance;
                pq.push({-nextDistance, next});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> V >> E;
    cin >> K;

    for(int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        nodes[u].push_back({v, w});
    }

    for(int i = 1; i<= V; i++) {
        ds[i] = INF;
    }
    
    dijkstra(K);

    for(int i = 1; i <= V; i++) {
        if(ds[i] == INF) cout << "INF" << '\n';
        else cout << ds[i] << '\n';
    }
    
    return 0;
}