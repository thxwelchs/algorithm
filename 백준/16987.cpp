#include <bits/stdc++.h>

using namespace std;

int N;
int ans;

vector<pair<int, int>> v;

void backtrack(int x)
{
    if (x >= v.size())
    { // off by one
        int cnt = 0;
        for (int i = 0; i < v.size(); i++)
        {
            if (v[i].first <= 0)
            {
                cnt++;
            }
        }

        ans = max(ans, cnt);
        return;
    }

    pair<int, int> &cur = v[x];
    if (cur.first <= 0)
    {
        backtrack(x + 1);
        return;
    }

    // 반례 1
    // 3
    // 100 100 (0)
    // 120 1 (1)
    // 100 100 (2)

    int flag = 0;
    for (int i = 0; i < v.size(); i++)
    {
        pair<int, int> &next = v[i];
        // 반례 1의 경우 이 조건문에서 모두 continue 됌
        // 깨지지 않은 다른 계란이 없을 때 치지 않고 넘어가되, 다음 backtrack은 해줘야 함
        if (i == x || next.first <= 0)
        {
            continue;
        }

        cur.first -= next.second;
        next.first -= cur.second;

        backtrack(x + 1);
        flag = 1;

        cur.first += next.second;
        next.first += cur.second;
    }
    if (!flag)
        backtrack(x + 1);
}

// 잘 생각해 보면, 1번부터 8(N)번까지 차례로 한 번씩 계란을 들고 다른 계란을 치는 것
// 다만, 이미 지금 들려고 하는 계란이 부서져 있는 상태라면 다른 계란을 칠 수가 없음

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    v.resize(N);

    for (int i = 0; i < N; i++)
    {
        cin >> v[i].first >> v[i].second;
    }

    backtrack(0);

    cout << ans;

    return 0;
}
