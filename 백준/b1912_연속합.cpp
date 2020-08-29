#include <iostream>
#include <string>

using namespace std;

// 백준 1912 연속합
// https://www.acmicpc.net/problem/1912

int main() {
    int n;
    cin >> n;
    int a[100000] = {};
    int dp[100000] = {};
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    dp[0] = a[0];
    int answer = dp[0];

    for(int i = 1; i < n; i++) {
        dp[i] = max(a[i] + dp[i - 1], a[i]);
        answer = max(answer, dp[i]);
    }

    cout << answer << endl;

    return 0;
}