#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 백준 10995 별 찍기 - 20
// https://www.acmicpc.net/problem/10995

int N;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    for(int i = 0; i < N; i++) {
        if(i % 2 != 0) cout << ' ';
        for(int j = 0; j < N * 2 - 1; j++) {
            if(j % 2 == 0) cout << '*';
            else cout << ' ';
        }
        cout << '\n';
    }
    
    return 0;
}
