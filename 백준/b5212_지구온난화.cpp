#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 백준 5212 지구 온난화
// https://www.acmicpc.net/problem/5212

int R, C;
char map[10][10];
char cmap[10][10];

int dir[4][2] = {
    {-1, 0},
    {0, 1},
    {1, 0},
    {0, -1}
};

// int dx = {-1,0,1,0};
// int dy = {0,-1,0,1};

bool isValid(int r, int c) {
    int count = 0;

    for(int i = 0; i < 4; i++) {
        int nr = r + dir[i][0];
        int nc = c + dir[i][1];
        if(nr < 0 || nr > R - 1 || nc < 0 || nc > C - 1 || cmap[nr][nc] == '.') count++;
    }

    return count < 3;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> R >> C;

    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            cin >> map[i][j];
            cmap[i][j] = map[i][j];
            // 1, 4
            // 1, 6
            // 1, 8
            // 2, 0

        }
    }

    int minY = 11, minX = 11, maxY = -1, maxX = -1;

    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            if(!isValid(i, j)) {
                map[i][j] = '.';
            }

            if(map[i][j] == 'X') {
                minY = min(minY, i);
                minX = min(minX, j);
                maxY = max(minY, i);
                maxX = max(maxX, j);
            }
        }
    }

    for(int i = minY; i <= maxY; i++) {
        for(int j = minX; j <= maxX; j++) {
            cout << map[i][j];
        }
        cout << '\n';
    }
    
    return 0;
}