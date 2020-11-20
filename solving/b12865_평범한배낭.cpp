#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 백준 12865 평범한 배낭
// https://www.acmicpc.net/problem/12865

const int MAX_THINGS = 101;
const int MAX_WEIGHT = 100001;

int w[MAX_THINGS];
int v[MAX_THINGS];

int dp[MAX_WEIGHT];

int N, K;
 
int main() {
 
    cin >> N >> K;
 
    for (int i = 1; i <= N; i++) {
        cin >> w[i] >> v[i];
    }
 
    for (int i = 1; i <= N; i++) {
        for (int j = K; j >= 1; j--) {
            if(w[i] <= j) dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
        }
    }
 
    cout << dp[K];

    return 0;
} 