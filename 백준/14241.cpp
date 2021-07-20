#include <bits/stdc++.h>

using namespace std;

int N;
priority_queue<int> pq;

int main() {
   ios::sync_with_stdio(false);
   cin.tie(NULL); cout.tie(NULL);

   cin >> N;

   while(N--) {
       int a;
       cin >> a;
       pq.push(a);
   }

    int ans = 0;
   while(pq.size() > 1) {
       int x = pq.top(); pq.pop();
       int y = pq.top(); pq.pop();
       ans += x * y;
       pq.push(x + y);
   }

   cout << ans;

   return 0;
}