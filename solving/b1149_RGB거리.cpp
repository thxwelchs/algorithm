#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 백준 1149 RGB거리
// https://www.acmicpc.net/problem/1149

const int MAX = 1000 + 1;

int N;
int r[MAX], g[MAX], b[MAX];
int dp[3][MAX];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for(int i = 1; i <= N; i++) {
        cin >> r[i] >> g[i] >> b[i];
    }
    // 0 = r, 1 = g, 2 = b
    dp[0][1] = r[1];
    dp[1][1] = g[1];
    dp[2][1] = b[1];

    for(int i = 2; i <= N; i++) {
        dp[0][i] = r[i] + min(dp[1][i - 1], dp[2][i - 1]);
        dp[1][i] = g[i] + min(dp[0][i - 1], dp[2][i - 1]);
        dp[2][i] = b[i] + min(dp[0][i - 1], dp[1][i - 1]);
    }

    cout << min(dp[0][N], min(dp[1][N], dp[2][N]));
    
    return 0;
}