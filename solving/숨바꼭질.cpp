#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

// 백준 1697 숨바꼭질
// https://www.acmicpc.net/problem/1697

const int MAX = 100000;
int N, K;
int answer = MAX + 1;
queue<pair<int, int> > q;
bool visited[MAX + 1];

void bfs() {
    while(!q.empty()) {
        int cur = q.front().first;
        int count = q.front().second;
        q.pop();

        if(cur < -1 || cur > MAX + 1) continue;
        if(cur == K) {
            answer = min(answer, count);
        }

        if(!visited[cur + 1]) {
            visited[cur + 1] = true;
            q.push(make_pair(cur + 1, count + 1));
        }

        if(!visited[cur - 1]) {
            visited[cur - 1] = true;
            q.push(make_pair(cur - 1, count + 1));
        }

        if(cur * 2 <= MAX && !visited[cur * 2]) {
            visited[cur * 2] = true;
            q.push(make_pair(cur * 2, count + 1));
        }
    }
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> K;

    q.push(make_pair(N, 0));
    visited[N] = true;
    bfs();

    cout << answer;
    
    return 0;
}