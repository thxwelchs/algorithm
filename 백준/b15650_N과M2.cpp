#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 백준 15650 N과 M 2
// https://www.acmicpc.net/problem/15650

int N, M;
int arr[8];
bool visited[8];

void dfs(int depth, int k) {
    if(depth == M) {
        for(int i = 0; i < M; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for(int i = 1; i <= N; i++) {
        if(visited[i]) continue;
        visited[i] = true;
        arr[depth] = i;
        if(k < i) {
            dfs(depth + 1, i);
        }
        visited[i] = false;
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;

    for(int i = 0; i < N; i++) {
        arr[i] = i+1;
    }

    dfs(0, 0);

    return 0;
}