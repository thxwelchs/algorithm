#include <bits/stdc++.h>

using namespace std;

int A[1001][1001];
int S[1001][1001];
int R, C, Q;

void solve()
{
    int r1, c1, r2, c2;

    cin >> r1 >> c1 >> r2 >> c2;

    int sum = S[r2][c2] - S[r1 - 1][c2] - S[r2][c1 - 1] + S[r1 - 1][c1 - 1];

    sum /= ((r2 - r1 + 1) * (c2 - c1 + 1));

    cout << sum << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> R >> C >> Q;
    for (int i = 1; i <= R; i++)
    {
        for (int j = 1; j <= C; j++)
        {
            cin >> A[i][j];
            S[i][j] = S[i - 1][j] + S[i][j - 1] + A[i][j] - S[i - 1][j - 1];
        }
    }

    while (Q--)
    {
        solve();
    }

    return 0;
}