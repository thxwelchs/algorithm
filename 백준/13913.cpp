#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

int N, K;
int vis[100002];

void bfs()
{
    queue<pii> q;
    q.push({N, 0});
    vis[N] = -1;

    while (!q.empty())
    {
        int c = q.front().first;
        int d = q.front().second;
        q.pop();

        if (c == K)
        {

            vector<int> v;
            v.push_back(c);
            int p = vis[c];
            if(p == -1) 
                p = 0;

            while(p != N) {
                v.push_back(p);
                p = vis[p];
                if(p == -1) {
                    p = 0;
                }
            }
            v.push_back(N);

            cout << d << '\n';
            for(int i = v.size() - 1; i >= 0; i--) {
                if(v[i] < 0)
                    continue;

                cout << v[i] << ' ';
            }

            return;
        }

        int pWalk = c - 1;
        int nWalk = c + 1;
        int jump = c * 2;

        if (pWalk >= 0 && !vis[pWalk] && vis[pWalk] != -1)
        {
            q.push({pWalk, d + 1});
            vis[pWalk] = c == 0 ? -1 : c;
        }

        if (nWalk <= 100000 && !vis[nWalk] && vis[nWalk] != -1)
        {
            q.push({nWalk, d + 1});
            vis[nWalk] = c == 0 ? -1 : c;
        }

        if (jump <= 100000 && !vis[jump] && vis[jump] != -1)
        {
            q.push({jump, d + 1});
            vis[jump] = c == 0 ? -1 : c;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;

    if(N == K) {
        cout << 0 << '\n';
        cout << N;
        return;
    }

    bfs();

    return 0;
}