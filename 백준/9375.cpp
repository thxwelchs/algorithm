#include <bits/stdc++.h>

using namespace std;

int T;

void solve() {
    int n;
    unordered_map<string, int> um;
    cin >> n;

    for(int i = 0; i < n; i++) {
        string n, k;
        cin >> n >> k;

        if(um.find(k) == um.end()) {
            um[k] = 1;
            continue;
        }

        um[k]++;
    }

    int total = 1;

    // 경우의 수를 구할 때 각 카테고리에 입지않은경우까지 고려하여 + 1한 경우의 수를 구해준다.

    for(auto _k : um) {
        total *= _k.second + 1;
    }

    // 모든 경우의 수에서 모두 안입었을 경우도 포함이 되어있기 때문에 1을 빼준다.

    cout << --total << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;

    while(T--) {
        solve();
    }
    
    return 0;
}