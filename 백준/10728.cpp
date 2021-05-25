#include <bits/stdc++.h>

using namespace std;


bool is_not_three_xor_zero(vector<int> v) {
    for(int i = 0; i < v.size(); i++) {
        for(int j = i + 1; j < v.size(); j++) {
            for(int x = j + 1; x < v.size(); x++) {
                if(!(v[i] ^ v[j] ^ v[x])) {
                    return false;
                }
            }
        }
    }
    return true;
}

void solve() {
    int n;
    cin >> n;

    vector<int> ans;
    int ma = 0;

    for(int i = 0; i < (1 << n); i++) {

        vector<int> v;
        for(int j = 0; j < n; j++) {
            if((1 << j) & i) {
                v.push_back(j + 1);
            }
        }

        if(is_not_three_xor_zero(v)) {
            if(v.size() > ma) {
                ma = v.size();
                ans.clear();

                for(int _n : v) {
                    ans.push_back(_n);
                }
            }
        }
    }

    cout << ans.size() << '\n';
    for(int _n : ans) {
        cout << _n << ' ';
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