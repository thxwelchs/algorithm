#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 백준 1051 숫자 정사각형
// https://www.acmicpc.net/problem/1051

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int N, M;
    cin >> N >> M;
    int r[50][50] = {};

    for(int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for(int j = 0; j < M; j++) {
            r[i][j] = s[j] - '0';
        }
    }

    int ret = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            int np = 1;
            while(i + np < N && j + np < M) {
                int ni = i + np;
                int nj = j + np;
                if((r[i][j] == r[ni][j]) && (r[i][j] == r[i][nj]) 
                && (r[i][j] == r[ni][nj])) {
                    ret = max(ret, (np + 1) * (np + 1));
                }
                np++;
            }
        }
    }

    cout << ret;

    return 0;
}
