#include <iostream>
#include <string>

using namespace std;

// 백준 13398 연속합2
// https://www.acmicpc.net/problem/13398

int main() {
    const int MAX_SIZE = 100000;

    int n;

    cin >> n;
    int a[MAX_SIZE];
    int dpL2R[MAX_SIZE];
    int dpR2L[MAX_SIZE];

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    dpL2R[0]=a[0];
    for(int i = 1; i < n; i++) {
        dpL2R[i] = max(dpL2R[i - 1] + a[i], a[i]);
    }

    dpR2L[n-1]=a[n-1];
    for(int i = n - 2; i >= 0; i--) {
        dpR2L[i] = max(dpR2L[i + 1] + a[i], a[i]);
    }

    int answer = -1001;

    for(int i = 0; i < n; i++) {
        answer = max(answer, dpL2R[i]);
        if(i > 0) answer = max(answer, dpL2R[i - 1]);
        if(i < n - 1) answer = max(answer, dpR2L[i + 1]);
        if(i > 0 && i < n - 1) answer = max(answer, dpL2R[i - 1] + dpR2L[i + 1]);
        // answer = max(max(dpL2R[i], dpL2R[i - 1] + dpR2L[i + 1]), max(dpL2R[i - 1], dpR2L[i + 1]));
        // answer = max(dpL2R[i] + dpR2L[i], max(dpL2R[i], dpR2L[i]));

    }


    // go(dpL2R, 0, n);
    // go(dpR2L, n, 0)

    cout << answer << endl;
    
    return 0;
}