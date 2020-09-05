#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
using P = pair<int, int>;

int N;
vector<vector<int>> tree(51);
vector<priority_queue<P>> q(51);
int dfs(int cur) {
	int ret = 0;
	
	for (int next : tree[cur]) {
		q[cur].push({1 + dfs(next),next});
	}
	
	int time = 0;
	while (!q[cur].empty()) {
		P p = q[cur].top(); q[cur].pop();
		int cost = p.first;
		
		ret = max(ret, cost + (time++));
	}

	return ret;
}

int main(){
	scanf("%d", &N); 
	for (int i = 0; i < N; i++) { 
		int to; scanf("%d", &to);
		if (to == -1) continue;
		tree[to].push_back(i);
	}
	// 입력정리 

	cout << dfs(0);
}