#include <bits/stdc++.h>

using namespace std;

int N, P, E;

pair<int, int> duck[20];
int ans[20];

int main() {
   ios::sync_with_stdio(false);
   cin.tie(NULL); cout.tie(NULL);

   cin >> N >> P >> E;

   for(int i = 0; i < N; i++) {
       int x, y;
       cin >> x >> y;

       duck[i] = {x, y};
   }

   for(int i = 0; i < (1 << N); i++) {

       vector<int> v;
       for(int j = 0; j < N; j++) {
           if(i & (1 << j)) {
               v.push_back(j);
           }
       }

       if(v.size() == P) {

           int mi, ma;
           mi = ma = 0;
           for(int j = 0; j < P; j++) {
               mi += duck[v[j]].first;
               ma += duck[v[j]].second;
           }

            // 최소나 최대값이 E 범위 안에 들어온다면?
           if(mi <= E && ma >= E) {
               // 먼저 최소개를 각 유효한 회원번호의 사람에게 나눠주고
               for(int j = 0; j < P; j++) {
                   ans[v[j]] = duck[v[j]].first;
               }
               // 남은 인형을 나눠준다.
               int temp = E - mi;

               for(int j = 0; j < P; j++) {
                    int diff = duck[v[j]].second - duck[v[j]].first;
                    if(diff <= temp) {
                        ans[v[j]] += diff;
                        temp -= diff;
                    } else {
                        ans[v[j]] += temp;
                        temp = 0;
                    }
               }

               for(int i = 0; i < N; i++) {
                   cout << ans[i] << ' ';
               }

               return 0;
           }
       }
   }

   cout << -1;

   return 0;
}