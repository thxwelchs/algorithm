#include <bits/stdc++.h>

using namespace std;

int arr[3];

void solve() {
    memset(arr, 0, sizeof(arr));

    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;
        arr[a]++;
    }

    if(arr[1] % 2 || arr[2] % 2) {
        cout << "NO";
    } else {
        cout << "YES";
    }

    cout << '\n';
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