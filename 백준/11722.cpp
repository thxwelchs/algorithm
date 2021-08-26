#include <bits/stdc++.h>

using namespace std;

/**
 * 정의: dp[i]는 0부터 i까지의 가장 긴 감소하는 뿌분수열의 최대 길이
 * 점화식: 
 *   - A
 *   - M = max(dp[0] ... dp[i])
 *   - Mi = M 을 찾은 index
 *   dp[i] = if (A[i] < A[Mi]) M + 1 else 1
 * 
 */

const int MAX = 1001;

int N;
int A[MAX];
int dp[MAX];
int answer;

int go(int n) {
    if(n == 0) {
        dp[n] = 1;
        return dp[n];
    }

    if(dp[n] != -1) {
        return dp[n];
    }

    // dp[n] = 1;
    dp[n] = 1;
    for(int i = n - 1; i >= 0; i--) {
        // short-circuit evaluation 주의
        if(A[i] > A[n] && dp[n] <= go(i)) {
            dp[n] = go(i) + 1;
        }
    }

    return dp[n];
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(NULL); cout.tie(NULL);

   cin >> N;

   for(int i = 0; i < N; i++) {
       cin >> A[i];
   }

   memset(dp, -1, sizeof(dp));

   go(N - 1);

   for(int i = 0; i < N; i++) {
       answer = max(go(i), answer);
   }

   cout << answer;

   return 0;
}