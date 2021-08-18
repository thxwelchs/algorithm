#include <bits/stdc++.h>

using namespace std;

/**
 * 정의: dp[i]는 가장 오른쪽 끝 칸까지의 최소 점프 횟수
 * 점화식: 
 *   x = ma[i]
 *   m = min(dp[i + 1] ... dp[x])
 *   dp[i] = if(m != 0) m, else 0
 */

int N;
int ma[1001];
int dp[1001];

int go(int n) {
    if(n == N) {
        return 0;
    }

    if(dp[n] != -1) {
        return dp[n];
    }

    int mi = 100 * 1000 + 1;
    for(int i = n + 1; i <= n + ma[n] && i <= N; i++){
        if(ma[i] == 0) 
            continue;
        
        mi = min(mi, go(i));
    }

    dp[n] = mi + 1;

    return dp[n];
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(NULL); cout.tie(NULL);

   cin >> N;

   for(int i = 1; i <= N; i++) {
       cin >> ma[i];
   }

   memset(dp, -1, sizeof(dp));

   if(go(1) >= 100 * 1000 + 1)
       cout << -1;
   else cout << go(1);

   return 0;
}