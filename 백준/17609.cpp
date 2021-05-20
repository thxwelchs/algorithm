#include <bits/stdc++.h>

using namespace std;

int T;
vector<int> v;

void solve() {
    string s;
    cin >> s;

    int cnt = 0;

    int sz = s.size();

    for(int i = 0; i < sz / 2; i++) {
        if(s[i] != s[sz - 1 - i]) {
            cnt++;
        }
    }

    if(!cnt) {
        v.push_back(0);
        return;
    }

    int st = 0, en = sz - 1;
    int flag = 0;

    while(st < en) {
        if(s[st] == s[en]) {
            st++;
            en--;
        } else {
            if(flag < 3) {
                if(flag == 0) {
                    st++;
                } else if(flag == 1) {
                    st--;
                    en--;
                }
                flag++;
            } 
            else {
                break;
            }
        }
    }

    v.push_back(((flag > 2) ? 2 : 1));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;

    while(T--) {
        solve();
    }

    for(int n : v) {
        cout << n << '\n';
    }
    
    return 0;
}