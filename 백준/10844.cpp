#include <bits/stdc++.h>

using namespace std;

// 
// dp[n][k] : n자리이면서 k로 끝나는 계단 수의 개수
// dp[n][k] = (if(k - 1 >= 0) dp[n - 1][k - 1] else 0) + (if(k + 1 < 10) dp[n -1][k + 1] else 0)

int N;
int dp[101][10];
const int A = 1000000000;

int go(int n, int k) {
    if(k < 0 || k > 9) {
        return 0;
    } 

    if(n == 1) {
        if(k == 0) return 0;
        return 1;
    }

    if(dp[n][k] != -1) {
        return dp[n][k];
    }

    dp[n][k] = (go(n - 1, k - 1) % A) + (go(n - 1, k + 1) % A) % A;

    return dp[n][k];
}

// 2, 1 -> 1, 0 -> 1, 2 = 2?

// 2, 0 -> 1, -1 -> 1, 1

int main() {
   ios::sync_with_stdio(false);
   cin.tie(NULL); cout.tie(NULL);

   cin >> N;
   memset(dp, -1, sizeof(dp));
   
//    memset(dp, 0x3f, sizeof(dp));
   // dp[i][j] = 0x[3f][3f][3f][3f] ~ 10억 좀 넘음 
   // 0x3f * 256^3 + 0x3f * 256^2 + ... + 0x3f

    long long ans = 0;
    for(int i = 0; i <= 9; i++) { // 
        ans = (ans + go(N, i)) % A;
    }

    cout << ans;

   return 0;
}

// 45654  3 5
