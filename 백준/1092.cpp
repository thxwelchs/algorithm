#include <bits/stdc++.h>

using namespace std;

int N, M, ans;
int pos[51];
int chk[10001];

int main() {
   ios::sync_with_stdio(false);
   cin.tie(NULL); cout.tie(NULL);

   cin >> N;
   vector<int> c(N);
   int ma = 0;
   for(int i = 0; i < N; i++) {
       cin >> c[i];
       ma = max(ma, c[i]);
   }
   cin >> M;
   vector<int> b(M);
   for(int i = 0; i < M; i++) {
       cin >> b[i];
       if(ma < b[i]) {
           cout << -1;
           return 0;
       }
   }

   sort(c.begin(), c.end(), greater<int>());
   sort(b.begin(), b.end(), greater<int>());

    int cnt = 0;
    for(int i = 0; i < c.size(); i++) {
        for(int j = 0; j < b.size(); j++) {
            if(b[j] > c[i]) {
                continue;
            }
            if(!chk[j]) {
                cnt++;
                chk[j] = 1;
                pos[i] = j;
                break;
            }
        }
    }
    ans++;

    while(cnt < M) {
        for(int i = 0; i < c.size(); i++) {
            for(int j = pos[i] + 1; j < b.size(); j++) {
                if(b[j] > c[i]) {
                    break;
                }
                if(!chk[j]) {
                    cnt++;
                    chk[j] = 1;
                    pos[i] = j;
                    break;
                }
            }

            if(cnt >= M) {
                break;
            }
        }
        ans++;
    }

    cout << ans;

   return 0;
}