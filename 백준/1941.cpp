#include <bits/stdc++.h>

using namespace std;

char arr[26];
int chk[26];
vector<int> v;
int dirY[4] = {-1, 0, 1, 0};
int dirX[4] = {0, 1, 0, -1};
int ans;

pair<int, int> to_pos(int n)
{
    n--;

    int y = n / 5;
    int x = n % 5;

    return make_pair(y + 1, x + 1);
}

int to_idx(int y, int x)
{
    return --y * 5 + x;
}

void check_ans()
{
    memset(chk, 0, sizeof(chk));
    queue<pair<int, int>> q;
    pair<int, int> pos = to_pos(v[0]);
    q.push(pos);
    chk[v[0]] = 1;
    
    while(!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();
        int y = p.first, x = p.second;

        for(int i = 0; i < 4; i++) {
            int ny = y + dirY[i];
            int nx = x + dirX[i];

            if(ny < 1 || ny > 5 || nx < 1 || nx > 5) {
                continue;
            }

            // 조합 7개 중에 있고, 아직 방문안했으면 방문
            for(int j = 1; j < v.size(); j++) {
                int idx = to_idx(ny, nx);
                if(idx == v[j] && !chk[v[j]]) {
                    chk[v[j]] = 1;
                    q.push({ny, nx});
                }
            }
        }
    }

    int sevenPrincessCount = 0;
    int dasomCount = 0;
    for(int i : v) {
        sevenPrincessCount += chk[i];
        if(arr[i] == 'S') {
            dasomCount++;
        }
    }

    if(sevenPrincessCount == 7 &&  dasomCount >= 4) {
        ans++;
    }
}

void backtrack(int n)
{
    if (n > 7)
    {
        check_ans();
        return;
    }

    int start = 1;
    if (v.size())
    {
        start = v.back() + 1;
    }
    for (int i = start; i <= 25; i++)
    {
        v.push_back(i);
        backtrack(n + 1);
        v.pop_back();
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int idx = 0;
    for (int i = 1; i <= 5; i++)
    {
        string s;
        cin >> s;
        for (int j = 1; j <= 5; j++)
        {
            arr[++idx] = s[j - 1];
        }
    }

    backtrack(1);

    cout << ans;
    return 0;
}