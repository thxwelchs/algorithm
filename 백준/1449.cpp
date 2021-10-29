#include <bits/stdc++.h>

using namespace std;

int N, L;
int arr[1001];

int main() {
   ios::sync_with_stdio(false);
   cin.tie(NULL); cout.tie(NULL);
   
   cin >> N >> L;

   for(int i = 0; i < N; i++) {
       cin >> arr[i];
   }

   sort(arr, arr + N);

    int ans = 1;
    int current = arr[0];
    for(int i = 0; i < N; i++) {
        if(arr[i] - current + 1 > L) {
            current = arr[i];
            ans++;
        }
    }

    cout << ans;

   return 0;
}