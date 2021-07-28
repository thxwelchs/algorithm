#include <bits/stdc++.h>

using namespace std;

const int INF = 2e9;

int N, M;
int mp[501][501];
int d[501][501][2];

int dir[2][6][3] = {
    {
        {-1, -1, 0},
        {-1, 0, 1},
        {0, -1, 1},
        {0, 1, 1},
        {1, 1, 0},
        {1, 0, 1}
    },
    {
        {-1, 0, 0},
        {-1, 1, 1},
        {0, 1, 0},
        {0, -1, 0},
        {1, -1, 1},
        {1, 0, 0}
    }
};

struct Node {
    int y, x, s, d;
};

struct cmp {
    bool operator()(const Node& n1, const Node& n2) {
        return n1.d > n2.d;
    }
};

// \ 1(-1, -1, \), 2(-1, 0, /), 3(0, -1, /), 4(0, 1, /), 5(1, 1, \), 6(1, 0, /)

// / 1(-1, 0, \), 2(-1, 1, /), 3(0, 1, \), 4(0, -1, \), 5(1, -1, /), 6(1, 0, \)

void dij() {
    priority_queue<Node, vector<Node>, cmp> pq;

    d[1][1][0] = mp[1][1];
    pq.push({1, 1, 0, mp[1][1]});

    while(!pq.empty()) {
        Node node = pq.top(); pq.pop();

        auto& hDist = d[node.y][node.x][node.s];

        if(node.d > hDist) {
            continue;
        }

        for(int i = 0; i < 6; i++) {
            int ny = node.y + dir[node.s][i][0];
            int nx = node.x + dir[node.s][i][1];
            int ns = dir[node.s][i][2];

            if(ny < 1 || ny > N || nx < 1 || nx > M) {
                continue;
            }

            int w = ns != mp[ny][nx];

            if(d[ny][nx][ns] > hDist + w) {
                d[ny][nx][ns] = hDist + w;
                pq.push({ny, nx, ns, hDist + w});
            }
        }
    }
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(NULL); cout.tie(NULL);

   cin >> N >> M;

   for(int i = 1; i <= N; i++) {
       string s;
       cin >> s;

       for(int j = 1; j <= M; j++) {
           d[i][j][0] = INF;
           d[i][j][1] = INF;
           mp[i][j] = s[j - 1] == '/' ? 1 : 0;
       }
   }

   dij();

   if(d[N][M][0] == INF) {
       cout << "NO SOLUTION";
   } else {
        cout << d[N][M][0];
   }

   return 0;
}