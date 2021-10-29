#include <bits/stdc++.h>

using namespace std;

int N;

int main() {
   ios::sync_with_stdio(false);
   cin.tie(NULL); cout.tie(NULL);

   cin >> N;
   vector<int> A(N), B(N);
   for(int i = 0; i < N; i++) {
       cin >> A[i];
   }
   for(int i = 0; i < N; i++) {
       cin >> B[i];
   }

   sort(A.begin(), A.end(), greater<int>());
   sort(B.begin(), B.end());

   int ans = 0;
   for(int i = 0; i < N; i++) {
       ans += A[i] * B[i];
   }

   cout << ans;

   return 0;
}