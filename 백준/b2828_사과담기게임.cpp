#include<bits/stdc++.h>

using namespace std;

// 백준 2828 사과담기게임
// https://www.acmicpc.net/problem/2828

int M, N, j;
int bs, be;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M >> j;

    int d = 0;
    bs = 1;
    be = M;

    while(j--) {
        int app;
        cin >> app;

        if(app >= bs && app <= be) {
            continue;
        }

        if(abs(bs - app) < abs(be - app)) {
            d += abs(bs-app);
            bs = app;
            be = bs + M - 1;
        } else {
            d += abs(be-app);
            be = app;
            bs = be - M + 1;
        }
    }

    cout << d;
    
    return 0;
}