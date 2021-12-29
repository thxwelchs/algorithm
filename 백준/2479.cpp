#include <bits/stdc++.h>

using namespace std;

int N, K, A, B;
string bins[1001];
unordered_map<string, int> mp;

bool is_one_hamming_dis(string a, string b)
{
    int cnt = 0;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] != b[i])
        {
            cnt++;
        }

        if (cnt > 1)
        {
            return false;
        }
    }

    return true;
}

void bfs()
{
    // 상태전이
    queue<int> q;
    q.push(A);
    mp[bins[A]] = -1;

    while (!q.empty())
    {

        int c = q.front();
        q.pop();

        if (c == B)
        {
            int p = c;

            vector<int> v;

            while (mp.count(bins[p]) && mp[bins[p]] != -1)
            {
                v.push_back(p);
                p = mp[bins[p]];
            }

            v.push_back(A);

            for (int i = v.size() - 1; i >= 0; i--)
            {
                cout << v[i] << ' ';
            }

            return;
        }

        for (int i = 1; i <= N; i++)
        {
            if (i == c)
            {
                continue;
            }

            if (mp.count(bins[i]))
            {
                continue;
            }

            if (is_one_hamming_dis(bins[c], bins[i]))
            {
                mp[bins[i]] = c;
                q.push(i);
            }
        }
    }

    cout << -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;

    for (int i = 1; i <= N; i++)
    {
        cin >> bins[i];
    }

    cin >> A >> B;

    bfs();

    return 0;
}