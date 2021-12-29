#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

int S;
int vis[2005][2005]; // vis[a][b] : a = 클립보드에 저장된 이모티콘 갯수, b = 화면에 입력된 이모티콘 갯수

void bfs()
{
    queue<pii> q;
    q.emplace(0, 1);
    vis[0][1] = 1;

    while (!q.empty())
    {
        pii p = q.front(); q.pop();

        int c = p.first;
        int e = p.second;

        if(e == S) {
            cout << vis[c][e] - 1;
            return;
        }
        
        if(!vis[e][e]) {
            q.emplace(e, e);
            vis[e][e] = vis[c][e] + 1;
        } 

        if((c + e) <= 2000 && !vis[c][c + e]) {
            q.emplace(c, c + e);
            vis[c][c + e] = vis[c][e] + 1;
        }

        if(e -1 >= 0 && !vis[c][e - 1]) {
            q.emplace(c, e - 1);
            vis[c][e - 1] = vis[c][e] + 1;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> S;
    bfs();

    return 0;
}