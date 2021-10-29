#include <bits/stdc++.h>

using namespace std;

int N;
int arr[100000];

int main() {
   ios::sync_with_stdio(false);
   cin.tie(NULL); cout.tie(NULL);

   cin >> N;

   for(int i = 0; i < N; i++) {
       cin >> arr[i];
   }

   sort(arr, arr + N, greater<int>());

   long long sum = 0;
   for(int i = 0; i < N; i++) {
       int x = (arr[i] - i);
       if(x < 0) {
           continue;
       }
       sum += x;
   }

    cout << sum;

   return 0;
}