#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 백준 15649 N과M1
// https://www.acmicpc.net/problem/15649

int arr[8];
bool visited[9];

int dfs(int N, int M, int depth) {
    if(depth == M) {
        for(int i = 0; i < M; i++) {
            cout << arr[i];
            if(i < M - 1) cout << ' ';
        }
        cout << '\n';
        return 0;
    } 

    for(int i = 1; i <= N; i++) {
        if(visited[i]) continue;
        arr[depth] = i;
        visited[i] = true;
        dfs(N, M, depth + 1);
        visited[i] = false;
   }

    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    dfs(N, M, 0);
    
    return 0;
}