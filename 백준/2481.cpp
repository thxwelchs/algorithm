#include <bits/stdc++.h>

using namespace std;

int N, K, M;
string A[100001];
unordered_map<int, int> umap;
int vis[100001];

int to_dec(string &s)
{
    int sum = 0;
    for (int i = 0; i < s.length(); i++)
    {
        sum *= 2;
        sum += (s[i] - '0');
    }

    return sum;
}

void bfs()
{
    queue<int> q;
    q.push(1);
    vis[1] = -1;

    while (!q.empty())
    {
        int cur = q.front(); q.pop();

        for(int i = 0; i < K; i++) {
            int curd = to_dec(A[cur - 1]);
            int nextd = curd ^ (1 << i);

            if(umap.count(nextd)) {
                int next = umap[nextd];
                if(vis[next]) {
                    continue;
                }
                q.push(next);
                vis[next] = cur; 
            }
        }
    }
}

void solve()
{
    int j;
    cin >> j;

    if(!vis[j]) {
        cout << - 1 << '\n';
        return;
    }

    vector<int> v;
    v.push_back(j);
    int p = vis[j];
    while(p != -1 && p != 0) {
        v.push_back(p);
        p = vis[p];
    }

    for(int i = v.size() - 1; i >= 0; i--) {
        cout << v[i] << ' ';
    }

    cout << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
        umap[to_dec(A[i])] = i + 1;
    }

    bfs();

    cin >> M;
    while (M--)
    {
        solve();
    }

    return 0;
}