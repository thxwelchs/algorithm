#include <iostream>
#include <string>
#include <queue>
#include <vector>

using namespace std;

// 백준 4991 로봇청소기
// https://www.acmicpc.net/problem/4991


struct Cleaning {
    int w; // 열 (너비)
    int h; // 행 (높이)
    int d; // 최소거리(답)
    char a[20][20]; // 청소정보 행렬
};

// BFS로 시작지점(로봇청소기 or 더러운 칸)과 타겟지점(더러운 칸)의 최소거리를 찾는다
int BFS(int start[], int target[], Cleaning c) {
    queue<vector<int> > q;
    q.push({start[0], start[1]});
    int d[20][20] = {0};

    // 만약 타겟지점에 도달하지 못 할 경우 -1
    int result = -1;

    while(!q.empty()) {
        int i = q.front()[0];
        int j = q.front()[1];
        if(i == target[0] && j == target[1]) {
            result = d[i][j];
            break;
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

    return result;
}

// 각 더러운 칸끼리의 최소거리를 구하기 위해 DFS로 순열을 구한다.
void permutation(int arr[], int p[], bool visited[], int n, int r, int depth, int dis[11][11], Cleaning *c) {

    if(depth == r) {
        // 첫번째 합은 로봇 청소기(0번 인덱스)와 순열의 부분집합 중 첫번째 더러운 칸이다.
        int sum = dis[0][p[0]];

        // 순열의 부분집합 중 두번째 더러운 칸 부터는 합을 구한다.
        for(int i = 1; i < r; i++) {
            int d = dis[p[i - 1]][p[i]];
            if(d == -1) {
                c -> d = -1;
                return;
            }
            sum += dis[p[i - 1]][p[i]];
        }

        // 합이 이전에 구했던 합보다 작으면 최소값이므로 저장
        if(c -> d == 0 || sum < c -> d) c -> d = sum;

        return;
    }

    for (int i = 0; i < n; i++) {
        if(!visited[i]) {
            visited[i] = true;
            p[depth] = arr[i];
            permutation(arr, p, visited, n, r, depth + 1, dis, c);
            visited[i] = false;
        }
    }
}

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
        int dirty = 0;

        // 로봇청소기, 더러운칸의 위치값에 색인값을 부여하기 위해 위치값을 배열에 저장
        int t[11][2] = {0};

        for(int i = 0; i < c.h; i++) {
            for(int j = 0; j < c.w; j++) {
                if(c.a[i][j] == '*') {
                    t[++dirty][0] = i;
                    t[dirty][1] = j;
                } else if(c.a[i][j] == 'o') {
                    // 출발은 로봇청소기로부터 해야하므로 0번째 인덱스에 저장
                    t[0][0] = i;
                    t[0][1] = j;
                }
            }
        }

        // 로봇청소기 or 더러운칸 -> 더러운칸 으로 가기 위한 최소거리를 저장할 2d 배열
        // dis[i][j] = i 부터 j까지의 최소거리
        // 각 인덱스(i,j)는 위 t 2d 배열에 색인한 순서대로 
        int dis[11][11] = {0};
        for(int i = 0; i < dirty + 1; i++) {
            for(int j = 0; j < dirty + 1; j++) {
                if(j > i) {
                    dis[i][j] = BFS(t[i], t[j], c);
                } else {
                    dis[i][j] = dis[j][i];
                }
            }
        }

        int arr[10];
        int p[10];
        bool visited[10];
        for(int i = 0; i < dirty; i++) {
            arr[i] = i + 1;
        }

        permutation(arr, p, visited, dirty, dirty, 0, dis, &c);

        cout << c.d << endl;
    }



    return 0;
}