#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

struct Node {
	int d, n, s;
};

struct cmp {
	bool operator()(Node a, Node b) {
		return a.d > b.d;
	}
};

int N, M;
const int INF = 2e9;

int dist[4001];
int dist2[4001][2];

vector<pii> g[4001];
vector<pii> g2[4001][2];

void dijkstra() {
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.emplace(0, 1);

	while (!pq.empty()) {
		pii p = pq.top(); pq.pop();

		int hd = p.first, hh = p.second;

		if (hd > dist[hh]) 
			continue;

		for (int i = 0; i < g[hh].size(); i++) {
			pii th = g[hh][i];

			int tt = th.first, td = th.second;

			if (dist[tt] > dist[hh] + td) {
				dist[tt] = dist[hh] + td;
				pq.emplace(dist[tt], tt);
			}
		}
	}
}

void dijkstra2() {
	priority_queue<Node, vector<Node>, cmp> pq;
	pq.push({ 0, 1, 0 });

	while (!pq.empty()) {
		Node node = pq.top(); pq.pop();

		int hd = node.d, hh = node.n, hs = node.s;

		if (hd > dist2[hh][hs])
			continue;

		int ns = 1 - hs;

		for (int i = 0; i < g2[hh][hs].size(); i++) {
			pii th = g2[hh][hs][i];

			int tt = th.first, td = th.second;

			if (dist2[tt][ns] > dist2[hh][hs] + td) {
				dist2[tt][ns] = dist2[hh][hs] + td;
				pq.push({ dist2[tt][ns], tt, ns });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int a, b, d;
		cin >> a >> b >> d;

		g[a].push_back({ b, d * 2 });
		g[b].push_back({ a, d * 2 });

		g2[a][0].push_back({ b, d });
		g2[a][1].push_back({ b, d * 4 });
		g2[b][0].push_back({ a, d });
		g2[b][1].push_back({ a, d * 4 });
	}

	dist2[1][1] = INF;
	for (int i = 2; i <= N; i++) {
		dist[i] = INF;
		dist2[i][0] = INF;
		dist2[i][1] = INF;
	}

	dijkstra();
	dijkstra2();

	int ans = 0;
	for (int i = 2; i <= N; i++) {
		if (dist[i] < min(dist2[i][0], dist2[i][1])) {
			ans++;
		}
	}

	cout << ans;
	
	return 0;
}