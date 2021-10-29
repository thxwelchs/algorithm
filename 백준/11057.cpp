#include <bits/stdc++.h>

using namespace std;

// 정의: dp[i][j]는 i번째 자릿수의 j로 끝나는 오르막 수의 개수
// 점화식: dp[i][j] = (dp[i - 1][0] ... dp[i - 1][j - 1])

// (dp[1][0] ... dp[1][9]) = 1
// dp[i][j] = (dp[i - 1][0] ... dp[i - 1][j - 1])

int N;
int dp[1001][10];
const int X = 10007;

int go(int i, int j) {
    if(i == 1) {
        return 1;
    }

    if(dp[i][j] != -1) {
        return dp[i][j];
    }

    int sum = 0;
    for(int k = 0; k <= j; k++) {
        sum = (sum + go(i - 1, k)) % X;
    }

    dp[i][j] = sum % X;

    return dp[i][j];
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(NULL); cout.tie(NULL);

   cin >> N;

   memset(dp, -1, sizeof(dp));

    int ans = 0;
    for(int i = 9; i >= 0; i--) {
        ans = (ans + go(N, i)) % X;
    }

    cout << ans;

   return 0;
}