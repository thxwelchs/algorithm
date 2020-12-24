#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 백준 18430 무기공학
// https://www.acmicpc.net/problem/18430

const int MAX = 5;

int N, M;
int wood[MAX][MAX];
bool visited[MAX][MAX];
int answer = 0;

int dir[4][2] = {
    { 1, -1 },
    { -1, -1 },
    { -1, 1 },
    { 1, 1 },
};

void visit(int r, int c, int nr, int nc, bool v) {
    visited[r][c] = v;
    visited[r][nc] = v;
    visited[nr][c] = v;
}

int getSum(int r, int c, int nr, int nc) {
    return (wood[r][c] * 2) + (wood[r][nc] + wood[nr][c]);
}

bool isIn(int r, int c) {
    return (r < N && r >= 0 && c < M && c >= 0);
}

bool isVisited(int r, int c, int nr, int nc) {
    return visited[nr][c] || visited[r][nc];
}

void dfs(int r, int c, int sum) {
    if(c == M) {
        c = 0;
        r++;
    }
    if(r == N) {
        answer = max(answer, sum);
        return;
    }

    if(!visited[r][c]) {
        for(int d = 0; d < 4; d++) {
            int nr = r + dir[d][0];
            int nc = c + dir[d][1];
            if(!isIn(nr, nc) || isVisited(r, c, nr, nc)) continue;
            visit(r, c, nr, nc, true);
            int nextSum = sum + getSum(r, c, nr, nc);
            dfs(r, c + 1, nextSum);
            visit(r, c, nr, nc, false);
        }
    }

    dfs(r, c + 1, sum);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> wood[i][j];
        }
    }
    dfs(0, 0, 0);
    cout << answer;
    
    return 0;
}