#include <bits/stdc++.h>

using namespace std;

int N, H;
int A[500005];
int S[500005];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> H;

    for(int i = 1; i<= N; i++) {
        int a;
        cin >> a;

        if(i % 2 == 0) {
            A[H - a + 1] += 1;
        } else {
            A[1] += 1;
            A[a + 1] -= 1;
        }
    }

    for(int i = 1; i <= H; i++) {
        S[i] = S[i - 1] + A[i];
    }

    int mi = 2e9;
    int cnt = 0;
    for(int i = 1; i <= H; i++) {
        mi = min(mi, S[i]);
    }
    for(int i = 1; i <= H; i++) {
        if(mi == S[i]) {
            cnt++;
        }
    }

    cout << mi << ' ' << cnt;

    return 0;
}