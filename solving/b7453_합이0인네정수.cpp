#include <iostream>
#include <string>

using namespace std;

// 백준 7453 합이 0인 네 정수
// https://www.acmicpc.net/problem/7453
const int MAX_LEN = 4000;
int n;
int AB[MAX_LEN * MAX_LEN], CD[MAX_LEN * MAX_LEN];
int A[MAX_LEN], B[MAX_LEN], C[MAX_LEN], D[MAX_LEN];

int main() {

    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> A[i] >> B[i] >> C[i] >> D[i];
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            AB[n * i + j] = (A[i] + B[j]);
            CD[n * i + j] = C[i] + D[j];
        }
    }

    return 0;
}