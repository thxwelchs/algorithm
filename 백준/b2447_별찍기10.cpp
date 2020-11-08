#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 백준 2447 별 찍기 10
// https://www.acmicpc.net/problem/2447

const int MAX = 2187; // 3^7 까지 가능

int N;
char stars[MAX + 1][MAX + 1];

void print_star(int r, int c, int n) {

    if(n == 1) {
        stars[r][c] = '*';
        return;
    }

    n /= 3;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(i == 1 && j == 1) continue;
            print_star(r + i * n, c + j * n, n);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;

    print_star(0, 0, N);

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(stars[i][j] == '\0') cout << ' ';
            else cout << stars[i][j];
        }
        cout << "\n";
    }
    
    return 0;
}