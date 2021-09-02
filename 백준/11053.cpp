#include <bits/stdc++.h>

using namespace std;

// dp[x] = x번째 까지의 가장 긴 증가하는 부분 수열의 길이
// dp[i] = max j<i dp[j] + 1 (단, a[j] < a[i])

int N;
int A[1001];
int dp[1001];

int go(int x) { // dp[x]를 계산하는 함수
    if(x == 1) {
        return 1;
    }

    if(dp[x] != -1) {
        return dp[x];
    }

    int j = x - 1;
    int ma = 0;
    for(int i = 1; i <= j; i++) {
        if(A[i] < A[x]) {
            ma = max(ma, go(i));
        }
    }

    dp[x] = ma + 1;

    return dp[x];
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(NULL); cout.tie(NULL);

   cin >> N;
   for(int i = 1; i <= N; i++) {
       cin >> A[i];
   }

   memset(dp, -1, sizeof(dp));

   int ans = 0;
   for(int i = 1; i <= N; i++) {
       ans = max(ans, go(i));
   }

   cout << ans;

   return 0;
}