#include <bits/stdc++.h>

using namespace std;

int N, K;
typedef pair<int, int> pii;

const int MA = 100001;
int dist[MA];

const int INF = 0x3f3f3f3f;

// 내 선택이 다음 선택에 영향을 주지 않는다면, 상태에 들어갈 필요가 없다.

bool is_(int n) {
	return n < MA && n >= 0;
}

void dijkstra() {
	priority_queue<pii, vector<pii>, greater<pii>> pq;

	for (int i = 0; i < MA; i++) {
		if (i == N) continue;
		dist[i] = INF;
	}

	pq.emplace(dist[N], N);

	while (!pq.empty()) {
		pii p = pq.top(); pq.pop();
		int hdist = p.first, here = p.second;

		if (hdist > dist[here]) continue;

		if (is_(here + 1) && dist[here + 1] > dist[here] + 1) {
			dist[here + 1] = dist[here] + 1;
			pq.emplace(dist[here + 1], here + 1);
		}

		if (is_(here - 1) && dist[here - 1] > dist[here] + 1) {
			dist[here - 1] = dist[here] + 1;
			pq.emplace(dist[here - 1], here - 1);
		}

		if (is_(here * 2) && dist[here * 2] > dist[here]) {
			dist[here * 2] = dist[here];
			pq.emplace(dist[here * 2], here * 2);
		}
	}

	cout << dist[K];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> K;

	dijkstra();

	return 0;
}