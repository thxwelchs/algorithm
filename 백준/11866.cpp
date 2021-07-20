#include <bits/stdc++.h>

using namespace std;

queue<int> q;
int N, K;
vector<int> ans;

int main() {
   ios::sync_with_stdio(false);
   cin.tie(NULL); cout.tie(NULL);

   cin >> N >> K;
   for(int i = 1; i <= N; i++) {
       q.push(i);
   }

   while(!q.empty()) {
       for(int i = 1; i <= K; i++) {
           int t = q.front(); q.pop();

            if(i == K) {
                ans.push_back(t);
                continue;
            }
           q.push(t);
       }
   }

    cout << '<';
   for(int i = 0; i < ans.size(); i++) {
       if(i == ans.size() - 1) {
           cout << ans[i];
           continue;
       }
       cout << ans[i] << ", ";
   }
    cout << '>';

   return 0;
}