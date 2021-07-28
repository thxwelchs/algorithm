#include <bits/stdc++.h>

using namespace std;

using pii = pair<int, int>;

const int MAX = 5000000;

int N, L;

int arr[MAX];
deque<pii> dq;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> L;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < N; i++) {
        if (!dq.empty() && dq.front().second <= i - L)
            dq.pop_front();

        while (!dq.empty() && dq.back().first > arr[i]) {
            dq.pop_back();
        }

        dq.push_back({arr[i], i});
        cout << dq.front().first << " ";
    }

    cout << "\n";

    return 0;
}
