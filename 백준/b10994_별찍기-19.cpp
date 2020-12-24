#include <iostream>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

// 백준 10994 별 찍기 - 19
// https://www.acmicpc.net/problem/10994

char a[505][505];

// ****
// *  *
// *  *
// ****

void func(int x, int y, int l) {
     // (x,y)가 맨 위 왼쪽인 안쪽이 차 있는 정사각형을 출력하되, 한 변의 길이는 n*4-3

    if(l == 0)
		return;
    func(x+2,y+2,l-1);

	int n = l * 4 - 3;
	for(int i = 0; i < n; i++) {
        a[x][y + i] = '*';
    }
    for(int i = 0; i < n - 2; i++) {
        a[x+i+1][y] = '*';
    }
    for(int i = 0; i < n - 2; i++) {
        a[x+i+1][y+n-1] = '*';
    }
    for(int i = 0; i < n; i++) {
        a[x + n - 1][y + i] = '*';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N;
    cin >> N;

	memset(a, ' ', sizeof(a));
	func(0, 0, N);
    int n = N * 4 - 3;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << a[i][j];
        }
        cout << '\n';
    } 

	return 0;
}