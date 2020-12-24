#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

// 백준 1966 프린터큐
// https://www.acmicpc.net/problem/1966

int solve(int N, int M, int p[]) {
    priority_queue<int> pq;
    queue<pair<int, int> > q;
    for(int i = 0; i < N; i++) {
        q.push(make_pair(p[i], i));
        pq.push(p[i]);
    }

    int cnt = 0;
    while(!q.empty()) {
        int n = q.front().first, i = q.front().second;
        q.pop();
        // while(pq.top() == n)
        if(pq.top() == n) {
            cnt++;
            pq.pop();
            if(M == i) return cnt;
        } else {
            q.push(make_pair(n, i));
        }
    }
    
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int T;
    cin >> T;

    while(T--) {
        int N, M;
        cin >> N >> M;
        int p[100] = {};
        for(int i = 0; i < N; i++) {
            cin >> p[i];
        }
        cout << solve(N, M, p) << '\n';
    }
    return 0;
}