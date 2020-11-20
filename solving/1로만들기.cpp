#include <iostream>
#include <string>

using namespace std;

const int MAX = 1000000;

int N;
int answer = MAX;
int dp[MAX + 1];

int dfs(int n) {
    if(n == 1) return 0;
    if(dp[n] != MAX) return dp[n];

    int a = MAX, b = MAX, c = MAX;
    if(!(n % 3)) a = dfs(n / 3) + 1;
    if(!(n % 2)) b = dfs(n / 2) + 1;
    c = dfs(n - 1) + 1;

    dp[n] = min(a, min(b, c));

    return dp[n];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    // dfs(N, 0);
    dp[2] = 1;
    dp[3] = 1;
    for(int i = 4; i <= N; i++) {
        dp[i] = MAX;
    }
    // dfs(N);

    cout << dfs(N);
    
    return 0;
}