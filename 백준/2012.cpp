#include <bits/stdc++.h>

using namespace std;

int N;
int arr[500001];
long long ans;

// 500000
// 500000 500000 500000 500000 500000 ... 500000 

int main() {
   ios::sync_with_stdio(false);
   cin.tie(NULL); cout.tie(NULL);

   cin >> N;

   for(int i = 1; i <= N; i++) {
       cin >> arr[i];
   }

   sort(arr + 1, arr + N + 1);

   for(int i = 1; i <= N; i++) {
       ans += abs(arr[i] - i);
   }

   cout << ans;

   return 0;
}