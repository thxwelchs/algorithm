#include <iostream>
#include <set>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

// 백준 4991 로봇청소기
// https://www.acmicpc.net/problem/4991

// 시간초과

struct Cleaning {
    int w;
    int h;
    char a[20][20];
};

int main() {
    vector<Cleaning> cleanings;

    while (true) {
        int w, h;
        cin >> w >> h;

        if(w == 0 && h == 0) break;

        struct Cleaning c;
        c.w = w;
        c.h = h;

        char a[20][20];
        for(int i = 0; i < h; i++) {
            cin >> c.a[i];
        }

        cleanings.push_back(c);
    }

    for(auto &&c : cleanings) {
        queue<vector<int>> q;
        int d[20][20] = {0};
        int dirty = 0, found = 0, distance = 0;

        for(int i = 0; i < c.h; i++) {
            for(int j = 0; j < c.w; j++) {
                if(c.a[i][j] == 'o') q.push({i, j});
                else if(c.a[i][j] == '*') dirty++;
            }
        }


        while(!q.empty()) {
            int i = q.front()[0];
            int j = q.front()[1];

            if(c.a[i][j] == '*') {
                c.a[i][j] = '.';
                found++;
                distance += d[i][j];
                queue<vector<int>> empty;
                swap(q, empty);
                q.push({i, j});
                memset(d, 0, sizeof(d));
            }

            q.pop();

            // 상
            if(i > 0 && c.a[i - 1][j] != 'x' && d[i - 1][j] == 0) {
                d[i - 1][j] = d[i][j] + 1;
                q.push({i - 1, j});
            }
            // 하
            if(i < c.h - 1 && c.a[i + 1][j] != 'x' && d[i + 1][j] == 0) {
                d[i + 1][j] = d[i][j] + 1;
                q.push({i + 1, j});
            }
            // 좌
            if(j > 0 && c.a[i][j - 1] != 'x' && d[i][j - 1] == 0) {
                d[i][j - 1] = d[i][j] + 1;
                q.push({i, j - 1});
            }
            // 우
            if(j < c.w - 1 && c.a[i][j + 1] != 'x' && d[i][j + 1] == 0) {
                d[i][j + 1] = d[i][j] + 1;
                q.push({i, j + 1});
            }
        }

        if(dirty != found) distance = -1;

        cout << distance << endl;
    }



    return 0;
}