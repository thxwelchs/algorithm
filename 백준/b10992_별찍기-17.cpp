#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 백준 10992 별 찍기 - 17
// https://www.acmicpc.net/problem/10992

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int N;
    cin >> N;

    for(int i = 0;i<N;i++) {
        if(i+1 == N) {
            for(int j = 0; j < N * 2 -1; j++) {
                cout << '*';
            }

        } else {
            for(int j = 0; j < N-i-1; j++) {
                cout << ' ';
            }
            cout << '*';
            if(i == 0) {
                cout << '\n';
                continue;
            }
            for(int j = 0; j < (i* 2 - 1); j++) {
                cout << ' ';
            }
            cout << '*';
        }
        cout << '\n';
    }
    
    return 0;
}