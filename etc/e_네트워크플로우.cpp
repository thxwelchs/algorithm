#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int INF = 1000000000;

int const N = 8;
int result;
int c[N + 1][N + 1]; //용량
int f[N + 1][N + 1]; //유량
int d[N + 1]; // 방문체크
vector<int> a[N + 1];

void maxFlow(int start, int end) {
    while(1) {
        // 방문 초기화
        fill(d, d + N + 1, -1);

        // 증가 경로를 찾기 위한 BFS
        queue<int> q;
        q.push(start);
        while(!q.empty()) {
            int x = q.front();
            q.pop();
            // 인접노드 방문
            for(int i = 0; i < a[x].size(); i++) {
                int y = a[x][i];

                // 방문하지 않은 노드 중 용량이 남은 경우
                if(c[x][y] - f[x][y] > 0 && d[y] == -1) {
                    q.push(y);
                    d[y] = x;

                    // 도착지에 도달한 경우
                    if(y == end) 
                        break;
                }

            }
        }

        // 모든 경로를 찾은 뒤 루프 탈출
        if(d[end] == -1)
            break;

        int flow = INF;
        // 거꾸로 최소 유량 탐색
        for(int i = end; i != start; i = d[i]) {
            flow = min(flow, c[d[i]][i] - f[d[i]][i]);
        }

        // 최소 유량만큼 추가
        for(int i = end; i != start; i = d[i]) {
            f[d[i]][i] += flow;
            // 역방향(음의 간선) 도 고려
            f[i][d[i]] -= flow;
        }

        result += flow;
    }
}

int main() {
    a[1].push_back(2);
    a[1].push_back(3);
    a[1].push_back(4);
    c[1][2] = 3;
    c[1][3] = 4;
    c[1][4] = 5;

    a[2].push_back(5);
    a[2].push_back(6);
    c[2][5] = 1;
    c[2][6] = 3;

    a[3].push_back(6);
    c[3][6] = 2;

    a[4].push_back(7);
    c[4][7] = 7;

    a[5].push_back(8);
    c[5][8] = 3;

    a[6].push_back(8);
    c[6][8] = 5;

    a[7].push_back(6);
    a[7].push_back(8);
    c[7][6] = 1;
    c[7][8] = 4;

    maxFlow(1, 8);

    cout << result << "\n";
    
    return 0;
}