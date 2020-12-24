#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 백준 2522 별 찍기 - 12
// https://www.acmicpc.net/problem/2522

int N;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;

    for(int i = 1; i <= N; i++) {
        for(int j = 0; j < N - i; j++) {
            cout << ' ';
        }
        for(int j = 0; j < i; j++) {
            cout << '*';
        }
        cout << '\n';
    }
    for(int i = 1; i <= N - 1; i++) {
        for(int j = 0; j < i; j++) {
            cout << ' ';
        }
        for(int j = 0; j < N - i; j++) {
            cout << '*';
        }
        cout << '\n';
    }
    
    return 0;
}
