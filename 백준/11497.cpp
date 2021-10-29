#include <bits/stdc++.h>

using namespace std;

int T;

void solve() {
    int N;
    cin >> N;
    vector<int> v(N);
    for(int i = 0; i < N; i++)
        cin >> v[i];

    sort(v.begin(), v.end());

    int lprev = v[0], rprev = v[1];
    int ans = abs(lprev - rprev);
    for(int i = 2; i < v.size() - 1; i+=2) {
        ans = max(ans, abs(v[i] - lprev));
        ans = max(ans, abs(v[i + 1] - rprev));
        lprev = v[i];
        rprev = v[i + 1];
    } 

    if(N % 2) {
        int last = v[N - 1];
        ans = max(ans, abs(last - lprev));
        ans = max(ans, abs(last - rprev));
    }

    cout << ans << '\n';
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