#include <bits/stdc++.h>

using namespace std;

int square[10001];

void solve() {
    int n;
    vector<int> v;
    cin >> n;

    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }

    for(int i = 0; i < n; i++) {
        if(!square[v[i]]) {
            cout << "YES" << '\n';
            return;
        }
    }

    cout << "NO" << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;

    for(int i = 1; i <= 100; i++) {
        square[i * i] = 1;
    }

    while(t--) {
        solve();
    }
    
    return 0;
}