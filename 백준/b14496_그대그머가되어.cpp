#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

// 백준 14496 그대 그머가 되어
// https://www.acmicpc.net/problem/14496

// 단순 BFS로는 풀었으나, 다익스트라로는 풀지 못했음
// 다익스트라로 푸는 중

const int MAX = 1001;

int a, b, N, M;
vector<pair<int, int> > d[MAX];
int dis[MAX];
bool v[MAX];

void dijkstra(int start) {
    dis[start] = 0;
    priority_queue<pair<int, int> > pq; // { 노드번호, 간선 가중치 }
    pq.push({start, 0});

    while(!pq.empty()) {
        int current = pq.top().first;
        int distance = -pq.top().second;
        pq.pop();

        // 이동하고자 하는 노드의 간선 값이 이미 구했던 최단거리보다 클 경우 넘어간다.
        if(dis[current] < distance) continue;

        for(int i = 0; i < d[current].size(); i++) {
            int next = d[current][i].first;

            // 선택된 노드를 인접 노드로 거쳐서 가는 비용
            int nextDistance = distance + d[current][i].second;

            // 기존에 구했던 비용보다 작으면 교체 
            if(nextDistance < dis[next]) {
                dis[next] = nextDistance;
                pq.push({next, -nextDistance});
            }
        }
    }
}

int main() {
    cin >> a >> b >> N >> M;

    for(int i = 0; i <= N; i++) {
        dis[i] = MAX * MAX + 1;
    }


    while(M--) {
        int p1, p2;
        cin >> p1 >> p2;
        d[p1].push_back({p2, 1});
        d[p2].push_back({p1, 1});
    }

    dijkstra(a);

    cout << dis[b] << "\n";
    
    return 0;
}