#include <bits/stdc++.h>

using namespace std;

/**
 * 정의: dp[N]은 N자리 이친수 개수
 * 점화식: dp[N] = dp[N-1] + dp[N-2]
 */

 // 정의 : dp[N][K]는 N자리이면서 마지막 자리가 K인 이친수 개수
 // dp[N][0] = dp[N-1][0] + dp[N-1][1]
 // dp[N][1] = dp[N-1][0]


 // dp[N-1][0] = dp[N-2][0] + dp[N-2][1] = DP[N-2]


 // DP[N] = dp[N][0] + dp[N][1]
 // DP[N] = dp[N-1][0] + dp[N-1][0] + dp[N-1][1]
 // DP[N] = dp[N-1][0] + DP[N-1](dp[N-1][0] + dp[N-1][1])
 // DP[N] = DP[N-2] + DP[N-1]




// 맨 뒷자리 숫자가 1이면 0만 붙임
// 맨 뒷자리 숫자가 0이면 0 혹은 1을 붙임
// 1, 1 (1)
// 2 10 (1)
// 3 101, 100 (2)
// 4 1010, 1001, 1000 (3)
// 5 10101, 10100, 10010, 10000, 10001 (5)
// 6 101010, 101001, 101000, 100100, 100101, 100001, 100000, 1000010 (8)
// 7 1010100, 1010101, 1010010, 1010001, 1010000 , 1001001, 1001000, 1001010, 1000010, 1000001, 1000000, 10000100, 10000101  (13)

const int MAX = 91;

long long dp[MAX][2];
int N;

long long go(int n, int k) {
    if(dp[n] != -1) return dp[n];

    dp[n][k] = go(n - 1, ) + go(n - 2);

    return dp[n];
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(NULL); cout.tie(NULL);

   cin >> N;

   memset(dp, -1, sizeof(dp));

   cout << go(N);

   return 0;
}