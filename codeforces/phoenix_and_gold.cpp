#include <bits/stdc++.h>

// Phoenix And Gold

using namespace std;

void solve() {
    int n, x;
    vector<int> v;
    cin >> n >> x;

    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }

    sort(v.begin(), v.end());

    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += v[i];
    }

    if(sum == x) {
        cout << "NO" << '\n';
        return;
    }

    sum = v[0];
    int back = n - 1;
    for(int i = 1; i < n; i++) {
        sum += v[i];
        if(sum == x) {
            if(i == back) continue;
            sum -= v[i];
            int tmp = v[back];
            v[back] = v[i];
            v[i] = tmp;
            sum += v[i];

            back--;
        }
    }

    if(sum > x || sum < x) {
        cout << "YES" << '\n';
        for(int i = 0; i < n; i++) {
            cout << v[i] << ' ';
        }
        cout << '\n';
    } else {
        cout << "NO" << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    while(t--) {
        solve();
    }
    
    return 0;
}