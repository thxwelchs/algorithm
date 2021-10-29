#include <bits/stdc++.h>

using namespace std;

int N;
int chk[100001];
vector<int> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for(int i = 0; i < N; i++) {
        int n;
        cin >> n;
        if(chk[n]) continue;
        v.push_back(n);
    }

    sort(v.begin(), v.end());

    int half = v.size() % 2 == 0 ? v.size() / 2 - 1 : v.size() / 2;

    cout << v[half];
    
    return 0;
}