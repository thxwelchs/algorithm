#include <bits/stdc++.h>

using namespace std;

int N;
int arr[11];
int chk[11];
int ans;

void backtrack(int n, int sum) {
    if(n <= 2) {
        ans = max(ans, sum);
        return;
    }

    for(int i = 1; i < N - 1; i++) {
        if(chk[i]) {
            continue;
        }

        chk[i] = 1;
        int left = 0;
        for(int j = i - 1; j >= 0; j--) {
            if(chk[j]) {
                continue;
            }
            left = arr[j];
            break;
        }

        int right = 0;
        for(int j = i + 1; j < N; j++) {
            if(chk[j]) {
                continue;
            }
            right = arr[j];
            break;
        }
        backtrack(n - 1, sum + left * right);
        chk[i] = 0;
    }
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(NULL); cout.tie(NULL);

   cin >> N;
   for(int i = 0; i < N; i++) {
       cin >> arr[i];
   }

   backtrack(N, 0);

   cout << ans;

   return 0;
}