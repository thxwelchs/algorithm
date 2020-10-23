#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

// 백준 15829 Hashing
// https://www.acmicpc.net/problem/15829

typedef unsigned long long ull;
int L;
const int M = 1234567891;
const int r = 31;

ull my_hash(char a, int e) {
    ull value = a - 'a' + 1;
    for(int i = 1; i <= e; i++) {
        value = value * r % M;
    }

    return value;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> L;

    ull sum = 0;
    for(int i = 0; i < L; i++) {
        char a;
        cin >> a;
        sum += my_hash(a, i);
    }

    cout << sum % M;
    return 0;
}