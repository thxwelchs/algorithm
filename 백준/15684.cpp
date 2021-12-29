#include <bits/stdc++.h>

using namespace std;

int N, M, H;
int arr[31][11];
int ans = 4;
// 가로선의 정보는 두 정수 a과 b로 나타낸다. (1 ≤ a ≤ H, 1 ≤ b ≤ N-1) b번 세로선과 b+1번 세로선을 a번 점선 위치에서 연결했다는 의미이다.

bool is_pass_by_x(int x)
{
    int _x = x;

    for (int j = 1; j <= H; j++)
    {
        // 입력으로 주어지는 가로선이 연속적일 순 없다.
        // 예를 들어 1 1 - 2, 1 2 - 3 의 가로선은 있을 수 없다는 뜻 (높이가 같은 가로선이면서 연속적인 경우)
        if (arr[j][_x]) _x++;
        else if(arr[j][_x - 1]) _x--;
    }

    return x == _x;
}

bool is_pass_all() {
    for(int i = 1; i <= N; i++) {
        if(!is_pass_by_x(i)) {
            return false;
        }
    }

    return true;
}

void backtrack(int y, int x, int n)
{
    // 결국 못찾은 경우
    if(n > 3) {
        return;
    }

    // 사다리 i번 플레이어의 결과가 i번이 될 수 있게 조작되었는지 체크
    if(is_pass_all()) {
        ans = min(ans, n);
        return;
    }

    // 시간이 많이 걸리는 순열 + 조합 짬뽕 풀이
    for(int i = y; i <= H; i++) {
        for(int j = 1; j <= N; j++) {
            if(arr[i][j]) continue;
            // j 양 옆은 연속적인 가로 사다리가 놓일 수 없다.
            // j - 1 - j, j - j + 1 이미 양 옆에 사다리가 있으면 일단 다음 사다리로 넘어가자
            if(arr[i][j - 1]) continue;
            if(arr[i][j + 1]) continue;

            arr[i][j] = 1;
            backtrack(i, j, n + 1);
            arr[i][j] = 0;
        }
    }

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> H;

    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        arr[a][b] = 1;
    }

    backtrack(1, 1, 0);

    if(ans < 4) cout << ans;
    else cout << -1;

    return 0;
}