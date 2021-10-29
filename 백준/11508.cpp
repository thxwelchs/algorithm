#include <bits/stdc++.h>

using namespace std;

int N;
int arr[100000];

int main() {
   ios::sync_with_stdio(false);
   cin.tie(NULL); cout.tie(NULL);

   cin >> N;

   for(int i =0; i< N; i++) {
       cin >> arr[i];
   }

   sort(arr, arr + N, greater<int>());

   long long sum = 0;

   for(int i = 0; i < N; i+=3) {
       if(i + 2 > N - 1) {
           int s = 0;
           for(int j = i; j < N; j++) {
               s += arr[j];
           }

           sum += s;
           break;
       }

       sum += arr[i] + arr[i + 1];
   }

   cout << sum;

   return 0;
}