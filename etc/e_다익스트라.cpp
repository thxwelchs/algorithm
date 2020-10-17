#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<pair<int, int>> a[7];
int d[7];

// 1. 출발노드를 설정
// 2. 출발 노드를 기준으로 각 노드의 최소 비용을 저장
// 3. 방문하지 않은 노드 중에서 가장 비용이 적은 노드를 선택
//    - 인접노드를 N번만큼 탐색하여 최소값 찾는 방법
//    - Min Heap 우선순위큐를 활용, 하는 방법)
// 4. 위 과정에서 3 ~ 4번을 반복
void dijkstar(int start) {
    d[start] = 0;
    priority_queue<pair<int, int> > pq;

    pq.push(make_pair(start, 0));

    while(!pq.empty()) {
        int current = pq.top().first;
        int distance = -pq.top().second;
        pq.pop();

        if(d[current] < distance) continue;
        for(int i = 0; i < a[current].size(); i++) {
            int next = a[current][i].first;

            int nextDistance = distance + a[current][i].second;

            if(nextDistance < d[next]) {
                d[next] = nextDistance;
                pq.push(make_pair(next, -nextDistance));
            }
        }
    }
}

int main() {
    
    return 0;
}