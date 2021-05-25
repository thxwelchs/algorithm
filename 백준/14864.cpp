#include <bits/stdc++.h>

using namespace std;

int arr[100001];
int arr2[100001];
int ans[100001];
int vis[100001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        arr[x]++; // x 뒤에 몇명있는지
        arr2[y]++; // y 앞에 몇명있는지
    }

    for(int i = 1; i <= n; i++) {
        // i번째 학생의 카드 번호는 적어도 i번째 앞의 학생수보다는 보다는 작아야하고,
        // 뒤의 학생수보다는 커야 한다
        ans[i] = arr[i] + i - arr2[i];  

        // 만약 카드 번호가 중복된다면? 존재해야 하는 순서쌍이 없거나, 무언가 잘못된것임
        if(vis[ans[i]]) {
            cout << -1;
            return 0;
        }

        vis[ans[i]] = 1;
    }

    for(int i = 1; i <= n; i++) {
        cout << ans[i] << ' ';
    }


    return 0;
}