#include <iostream>
#include <vector>

using namespace std;

// 백준 16505 별
// https://www.acmicpc.net/problem/16505

int N;
char map[1025][1025];

void go(int y, int x, int l) {
    if(l == 0) {
        map[y][x] = '*';
        return;
    }

    l /= 2;

    go(y, x, l);
    go(y, x + l, l);
    go(y + l, x, l);
}


int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> N;
    // cout << N / 2;
    int l = 1; 
    for(int i=0; i<N;i++) l *= 2;
    go(0, 0, l);

    for(int i = 0; i < l; i++) {
        for(int j = 0; j < l - i; j++) {
            if(map[i][j] != '*') cout << ' ';
            else cout << '*';
        }
        cout << '\n';
    }
    return 0;
}