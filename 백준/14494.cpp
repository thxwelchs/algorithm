#include <bits/stdc++.h>

using namespace std;

// 정의: dp[i][j]는 m[1][1] 에서 출발하여 도착할 수 있는 경우의 수
// 점화식: dp[i][j] = dp[i - 1][j] + dp[i][j - 1] + dp[i - 1][j - 1]

int N, M;
long long dp[1001][1001];
const int K = 1000000007;

long long go(int i, int j) {
    if(i < 1 || j < 1) {
        return 0;
    }

    if(i == 1 && j == 1) {
        dp[i][j] = 1;
        return dp[i][j];
    }

    if(dp[i][j] != -1) {
        return dp[i][j];
    }

    dp[i][j] = (go(i - 1, j) % K) + (go(i, j - 1) % K) + (go(i - 1, j - 1) % K);
    dp[i][j] %= K;

    return dp[i][j];
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(NULL); cout.tie(NULL);

   cin >> N >> M;

   memset(dp, -1, sizeof(dp));

   cout << go(N, M);

   return 0;
}


// short-circuit evaluation