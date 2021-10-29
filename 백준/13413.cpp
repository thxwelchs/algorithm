#include <bits/stdc++.h>

using namespace std;

int T;

void solve() {
    int n;
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;

    int x, y;
    x = y = 0;
    for(int i = 0; i < s1.length(); i++) {
        if(s1[i] == s2[i]) {
            continue;
        } else if(s1[i] == 'W') {
            x++;
        } else {
            y++;
        }
    }

    cout << min(x, y) + abs(x - y) << '\n';
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(NULL); cout.tie(NULL);

   cin >> T;

   while(T--) {
       solve();
   }

   return 0;
}