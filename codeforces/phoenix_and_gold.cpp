#include <bits/stdc++.h>

// Phoenix And Gold

using namespace std;

void solve() {
    int n, x;
    vector<int> v;
    cin >> n >> x;

    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }

    sort(v.begin(), v.end());

    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += v[i];
    }

    // 어떠한 경우에도, 수열의 모든합이 x가 된다면 반드시 터질 수 밖에 없어서 NO 이다.
    if(sum == x) {
        cout << "NO" << '\n';
        return;
    }

    // 위에서 정렬되었으니 수열의 단조증가성은 보장되어져있고,
    // 연속된 두 수를 더했을 때 x가 된다면, 가장 마지막에 있는 수와 swap 해준다. 그러면 적어도 x보다는 무조건 크다.
    // (실은 가장 마지막에 있는 수를 더할 필요 없고, 현재 위치보다 한칸 더 앞에 있는 수(i + 1)를 더해주어도 x보다는 무조건 크다는 조건이 성립한다.)
    // 1. 의문? 그런데 만약 수열의 가장 마지막 수까지 더했을 때 x가 된거라면? (n - 2 + n - 1) 이 더해졌을 때의 상황이라면?
    // - 실은 이미 이 상황은 이미 위 모든합이 x가 되었을 때의 조건과 같으므로 여기서는 이 상황이 나올 수가 없다.
    // - 애초에 한번이라도 연속된 두수의 합이 x가 나올수 있는 부분은 단 한번 뿐이 될 것이다.
    sum = 0;
    int back = n - 1;
    for(int i = 0; i < n; i++) {
        sum += v[i];
        if(sum == x) {
            sum -= v[i];
            int tmp = v[back];
            v[back] = v[i];
            v[i] = tmp;
            sum += v[i];

            break;
        }
    }

    cout << "YES" << '\n';
    for(int i = 0; i < n; i++) {
        cout << v[i] << ' ';
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    while(t--) {
        solve();
    }
    
    return 0;
}