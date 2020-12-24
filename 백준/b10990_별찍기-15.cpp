#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 백준 10990 별 찍기 - 15
// https://www.acmicpc.net/problem/10990

int N;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    for(int i = 0; i < N; i++) {
        for(int j = i; j < N - 1; j++) {
            cout << ' ';
        }
        cout << '*';
        for(int j = 0; j < i * 2 - 1; j++) {
            cout << ' ';
        }
        if(i > 0) cout << '*';
        cout << '\n';
    }
    
    return 0;
}
