#include <bits/stdc++.h>

using namespace std;

// 정의: dp[x][y] = 1부터 x번째 까지 마시는데, 최대 y개의 병을 연속으로 마셨을 때의 최대 포도주 양
// 점화식: dp[x][y] = max

// 6, 10, 13, 9, 8, 1
// 6, 10, 13, 9

// OOX
// OXO
// XOO

int g[10001];
int dp[10001][3];

int go(int x, int y) { // go(x,y) = x번째 술을 먹는데, x번째 술을 먹으면 지금까지 y번 연속해서 술을 먹은 것이다. 이때 최대 점수는?
    if(x < 1) return 0;
    if(x == 1) return g[1];
    if(dp[x][y] != -1) return dp[x][y];

    int ma = 0;

    if(y == 1) {
        //  O    O    X    O
        // x-3  x-2  x-1   x

        //  X    O    X    O
        // x-3  x-2  x-1   x

        //  O    X    X    O
        // x-3  x-2  x-1   x
        // 1번째 술을먹을 때에는 x-2번째와 x-3번째의 최대 점수를 고려하면 된다. 연속해서 3잔먹을 수는 없기에, 지금 현재 1잔 먹을 때 가장 최대 값을 낼 수 있는 부분을 고려

        // O(n)
        ma = max({ma, go(x-3, 1), go(x-3, 2)});
        ma = max({ma, go(x-2, 1), go(x-2, 2)});

        // 밑에 반복문으로 하면 O(n^2)
        // for(int i = 1; i <= x - 2; i++) {
        //     ma = max({ma, go(x-2, 1), go(x-2, 2)});
        // }
    } else {
        // 연속해서 2번째 술을 먹을 때에는 x-1번째를 고려
        // 대신 x-1번째이지만 2잔을 연속으로 마신경우는 고려할 수 없음 x-1번째가 2잔을 연속으로 마신경우라면 현재 위치에 있는 잔을 마시면 연속으로 3잔마시는 것이 되기 때문

        // .....  O    O
        //       x-1   x
		ma = go(x - 1, 1);
	}

    // X O
    // X X O
    // 위 예와 같이 전에는 모두 안마시다 현재 x번째에서 처음 마시는 경우가 있을 수 있다. 2번째 잔 3번째 잔
    // 위 경우 ma 값이 0으로 되어있으므로 상관 X
    
    return dp[x][y] = ma + g[x];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> g[i];

    memset(dp, -1, sizeof(dp));

    int answer = -1;
    for(int i = 1; i <= n; i++) {
        answer = max({answer, go(i, 1), go(i, 2)});
    }

    cout << answer;
    
    return 0;
}