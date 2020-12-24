#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 백준 10990 별 찍기 -16
// https://www.acmicpc.net/problem/10991

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int N;
    cin >> N;

    for(int i = 0;i<N;i++) {
        for(int j = 0; j < N-i-1; j++) {
            cout << ' ';
        }
        for(int j = 0; j < i + 1; j++) {
            cout << '*' << ' ';
        }
        cout << '\n';
    }
    
    return 0;
}