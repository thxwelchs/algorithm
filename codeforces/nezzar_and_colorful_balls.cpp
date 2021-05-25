#include <bits/stdc++.h>

using namespace std;

int arr[101];

void solve() {
    memset(arr, 0, sizeof(arr));
    int n;
    cin >> n;

    int ma = 0;
    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;
        arr[a]++;

        ma = max(ma, arr[a]);
    }

    cout << ma << '\n';
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