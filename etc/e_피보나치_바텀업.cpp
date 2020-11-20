#include <iostream>
using namespace std;

int N;
long long cache[61];

void fibo() {
  cache[0] = 1;
  cache[1] = 1;
  for(int i = 0; i <= 60; i++) {
    cache[i + 2] = (cache[i + 1] + cache[i]);
  }
}

long long find_fibo(int num) {
  if(num == 1) return 2;
  for(int i = 0; i <= 60; i++) {
    if(num > cache[i]) continue;
    return cache[i];
  }
  
  return 0;
}

int main() {
  cin >> N;
  
  fibo();
  
  while(N--) {
    int n;
    cin >> n;
    cout << (long long)find_fibo(n) << '\n';
  }
  
  return 0;
}