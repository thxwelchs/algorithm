#include <bits/stdc++.h>

using namespace std;

int arr[3];

void solve() {
    memset(arr, 0, sizeof(arr));

    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;
        arr[a]++;
    }

    // 공정하게 나눌 수 없을 때의 경우는, 1 무게의 캔디가 홀수개 이거나,
    // 1 무게의 캔디가 0개 이면서 2 무게의 캔디가 짝수개 일 때이다.

    // 만약 1무게의 캔디가 짝수개이면, 2무게의 캔디가 몇개가 있던 공정하게 나눌 수 있다.
    // 1무게의 캔디가 짝수개이고, 2무게의 캔디가 짝수개라면 당연하게도 짝수개를 2씩 나눠서 둘에게 공정하게 나누어주면 된다.
    // 1무게의 캔디가 짝수개이고, 2무게의 캔디가 홀수개라면, 2무게의 캔디를 2로 나누어 한명에게 하나를 더 주고, 나머지 한명에게 
    // 주어야 할 부족한 캔디는 1무게의 2개로 채우면 된다. (1무게의 캔디가 짝수개이기 때문에 2개로 무조건 채울 수 있다.)

    if(arr[1] % 2) {
        cout << "NO";
    } else if(!arr[1] && arr[2] % 2) {
        cout << "NO";
    } else {
        cout << "YES";
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