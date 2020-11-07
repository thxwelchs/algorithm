#include <iostream>
#include <string>
#include <vector>

// 백준 17070 파이프 옮기기 1
// https://www.acmicpc.net/problem/17070

using namespace std;

int N;

const int MAX = 16;
int house[MAX + 1][MAX + 1];
int d[3][MAX + 1][MAX + 1];

int dirs[3][2] = {
    {0, -1},
    {-1, 0},
    {-1, -1},
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    for(int i = 1; i <= N; i++) 
        for(int j = 1; j <= N; j++)
            cin >> house[i][j];

    d[0][1][2] = 1;

    for(int i = 1; i <= N; i++) {
        for(int j = 3; j <= N; j++) {
            if(house[i][j]) continue;

            // 현 위치의 각 회전 방향의 경우의 수 계산
            // [x][i][j]: x 방향 i 행 j 열
            for(int x = 0; x < 3; x++) {
                int di = i + dirs[x][0];
                int dj = j + dirs[x][1];

                if(x == 2 && (house[i-1][j] || house[i][j-1])) continue;

                if(x == 2) {
                    d[x][i][j] += d[0][di][dj] + d[1][di][dj];
                } else {
                    d[x][i][j] += d[x][di][dj];
                }
                d[x][i][j] += d[2][di][dj];
            }
        }
    }

    cout << d[0][N][N] + d[1][N][N] + d[2][N][N];
    
    return 0;
}