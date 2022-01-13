#include <bits/stdc++.h>

using namespace std;

int N, D;
typedef long long ll;
pair<ll, ll> A[100001];
ll ans;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> D;

    for (int i = 0; i < N; i++) {
        int p, v;
        cin >> p >> v;
        A[i] = make_pair(p, v);
    }

    sort(A, A + N);

    int i = 0, j = 0;
    ll sum = 0;
    while(i < N && j < N) {
        if(A[j].first - A[i].first < D) {
            sum += A[j++].second;
        } else {
            sum -= A[i++].second;
        }

        ans = max(ans, sum);
    }

    cout << ans;

    return 0;
}