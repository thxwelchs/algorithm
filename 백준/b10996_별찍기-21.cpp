#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 백준 10996 별 찍기 - 21
// https://www.acmicpc.net/problem/10996

int N;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    for(int i = 0; i < N * 2; i++) {
        for(int j = 0; j < N; j++) {
            if(i % 2 == 0) {
                if(j % 2 == 0) cout << '*';
                else cout << ' ';
            } else {
                if(j % 2 == 0) cout << ' ';
                else cout << '*';
            }
        }
        cout << '\n';
    }
    
    return 0;
}