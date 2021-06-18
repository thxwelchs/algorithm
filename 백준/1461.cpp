#include <bits/stdc++.h>

using namespace std;

int N, M;
int arr[10000];
int vis[10000];
int ans;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;

    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    // 일단 정렬 해서 단조성이 보장된 선형구조를 만든다.
    sort(arr, arr + N);

    if(abs(arr[0]) > abs(arr[N - 1])) {
        for(int i = 0; i < M; i++) {
            vis[i] = 1;
        }
        ans += abs(arr[0]);
    } else {
        for(int i = N - 1; i > N - M; i--) {
            vis[i] = 1;
        }
        ans += abs(arr[N - 1]);
    }

    int i = 0;
    while(i < N) {
        if(vis[i]) continue;

        ans += abs(arr[i]);
        // if()
        // i += M;
    }
    
    return 0;
}