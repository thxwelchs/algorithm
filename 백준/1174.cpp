#include <bits/stdc++.h>

using namespace std;

int N;
vector<long> v;
set<long> chk;

void backtrack(long x) {
    long r = x / 10 * 10;

    long d = x >= 10 ? x - r : x;

    while(d >= 0) {
        if(chk.count(x)) {
            break;
        }
        v.push_back(x);
        chk.insert(x);
        for(long i = x - 1; i >= x / 10 * 10; i--) {
            backtrack(i);
        }
        d--;
        x = x * 10 + d;
    }
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(NULL); cout.tie(NULL);

   cin >> N;

   for(int i = 0; i <= 9; i++) {
        backtrack(i);
   }

   if(N > v.size()) {
       cout << -1;
       return 0;
   }

   sort(v.begin(), v.end());
   cout << v[N - 1];

   return 0;
}