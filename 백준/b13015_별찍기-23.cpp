#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 백준 13015 별 찍기 - 23
// https://www.acmicpc.net/problem/13015

int N;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    int w =  N * 2 - 3;
    for(int i = 0; i < N; i++) cout << '*';
    for(int i = 0; i < w; i++) cout << ' ';
    for(int i = 0; i < N; i++) cout << '*';
    cout << '\n';

    for(int i = 1; i <= (w / 2); i++) {
        for(int j = 0; j < i; j++) cout << ' ';
        cout << '*';
        for(int j = 0; j < N - 2; j++) cout << ' ';
        cout << '*';
        for(int j = 0; j < w - (2 * i); j++) cout << ' ';
        cout << '*';
        for(int j = 0; j < N - 2; j++) cout << ' ';
        cout << '*';

        cout << '\n';
    }

    for(int i = 0; i < N - 1; i++) cout << ' ';
    cout << '*';
    for(int i = 0; i < N - 2; i++) cout << ' ';
    cout << '*';
    for(int i = 0; i < N - 2; i++) cout << ' ';
    cout << '*';
    cout << '\n';

    for(int i = (w / 2); i >= 1; i--) {
        for(int j = 0; j < i; j++) cout << ' ';
        cout << '*';
        for(int j = 0; j < N - 2; j++) cout << ' ';
        cout << '*';
        for(int j = 0; j < w - (2 * i); j++) cout << ' ';
        cout << '*';
        for(int j = 0; j < N - 2; j++) cout << ' ';
        cout << '*';
        cout << '\n';
    }

    for(int i = 0; i < N; i++) cout << '*';
    for(int i = 0; i < w; i++) cout << ' ';
    for(int i = 0; i < N; i++) cout << '*';
    
    return 0;
}


// *****       *****
//  *   *     *   *
//   *   *   *   *
//    *   * *   *
//     *   *   *
//    *   * *   *
//   *   *   *   *
//  *   *     *   *
// *****       *****


// ***   ***
//  * * * *
//   * * *
//  * * * * 
// ***   ***

// ****     ****
//  *  *   *  *
//   *  * *  *
//    *  *  *
//   *  * *  *
//  *  *   *  *
// ****     ****