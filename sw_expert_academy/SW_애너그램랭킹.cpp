#include <bits/stdc++.h>
 
using namespace std;

typedef unsigned long long ull;
 
int T;
string S;
int chk[27];
ull fa[21];
ull ans;
 
ull fac(long long x) {
    if (x == 0) {
        return 1;
    }
    if (x <= 2) {
        return x;
    }
    if(fa[x] != -1) {
        return fa[x];
    }
 
    return x * fac(x - 1);
}
 
void go(int x, int len) {
    if (x == len) {
        return;
    }
 
    for (int i = 0; i < (S[x] - 'A'); i++) {
        if (!chk[i]) {
            continue;
        }
 
        chk[i]--;
        long long f = fac(len - (x + 1));
        for (int j = 0; j < 26; j++) {
            f /= fac(chk[j]);
        }
        ans += f;
        chk[i]++;
    }

    // cout << "ans : " << ans << " x : " << x << "\n";
 
    chk[S[x] - 'A']--;
    go(x + 1, len);
}
 
 
void solve(int t) {
 
    cin >> S;
    ans = 0;
    memset(chk, 0, sizeof(chk));
 
    for (int i = 0; i < S.size(); i++) {
        chk[S[i] - 'A']++;
    }
 
    go(0, S.size());
 
    cout << "#" << t << " " << ans << '\n';
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
 
    cin >> T;

    memset(fa, -1, sizeof(fa));
    fac(20);

    for (int i = 1; i <= T; i++) {
        solve(i);
    }
 
    return 0;
}