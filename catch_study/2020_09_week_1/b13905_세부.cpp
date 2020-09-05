#include <iostream>
#include <string>
#include <vector>
#include <queue>

// 백준 13905 세부
// https://www.acmicpc.net/problem/13905

using namespace std;

// 막연하게만 알고 있던 다익스트라로 해결 할 수 있는 문제인줄 알고 다익스트라 알고리즘을 처음으로 공부하고 풀려고 했는데..
// 끝내 시간초과를 해결하지 못했다.
// 거의 반나절이 넘게 안풀려서 검색결과 이분탐색 + BFS 로 풀 수 있다라는 힌트만 얻고 진행해서 풀었는데,
// 아직도 다익스트라 결과가 왜 시간초과가 나오고, 이분탐색은 통과가 되는지 이해를 하지 못했다.
// (이분탐색 시 마다 계속해서 BFS로 전체노드를 탐색하는 것이 오히려 다익스트라에서 가지를 쳐가면서 한번만 수행하는 것보다 더 걸리지 않는건가..?)

int N, M; //집 갯수, 다리 갯수
int s, e; //출발지, 목적지
// i = 출발지, first = 목적지, second = 다리 무게제한
vector<vector<pair<int, int> > > islands;

// 노드 방문 체크
vector<bool> visited;

//  1부터 ~ 주어진 최대 GOLD 매개변수로 시작지점 -> 목표지점 까지 도달 할 수 있는지 체크 해본다.
bool BFS(int gold) {
    queue<int> q;
    fill(visited.begin(), visited.end(), false);

    q.push(s);

    while(!q.empty()) {
        int current = q.front();
        q.pop();

        if(visited[current]) continue;
        visited[current] = true;

        vector<pair<int, int> > adj = islands[current];

        for(int i = 0; i < adj.size(); i++) {
            int next = adj[i].first;
            int weight = adj[i].second;

            if(gold > weight) continue;

            if(next == e) return true;

            q.push(next);
        }
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;
    cin >> s >> e;

    islands.resize(N + 1);
    visited.resize(N + 1);

    int left = 1, right = 0, mid;

    for(int i = 0; i < M; i++) {
        int si, ei, w;
        cin >> si >> ei >> w;
        islands[si].push_back({ ei, w });
        islands[ei].push_back({ si, w });
        if(w > right) right = w;
    }

    int answer = 0;


    // 이분탐색으로 1 ~ 각 집과 집 사이에 주어진 무게제한 최대값(어차피 최대값 이하의 범위에서만 경로를 찾아야 하기에)
    while(left <= right) {
        // 각 테스트 해볼 매개변수 mid 가 들고다닐 gold를 의미 
        mid = (left + right) / 2;

        // mid 만큼의 gold로 시작지점 -> 목표지점까지 도달 할 수 있는 경우라면 이 gold는 허용되는 수치라는 것
        // 혹시 더 큰 값을 찾을 수도 있으니 찾았던 mid 왼쪽 만큼의 값은 무시한 채 하나씩 증가해가면서 최대값을 찾아본다.
        if(BFS(mid)) {
            left = mid + 1;
            answer = mid;
        } else {
            right = mid - 1;
        }
    }

    cout << answer << endl;
    
    return 0;
}