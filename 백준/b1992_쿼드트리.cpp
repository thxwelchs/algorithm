#include<bits/stdc++.h>

using namespace std;

// 백준 1992 쿼드트리
// https://www.acmicpc.net/problem/1992

int N;
int arr[64][64];

string go(int y, int x, int n) {
    string s = "";
    if(n == 1) {
        s += arr[y][x] ? "1" : "0";
        return s;
    }
    int t1, t2;
    t1 = t2 = 0;
    for(int i = y; i < y + n; i++) {
        for(int j = x; j < x + n; j++) {
            if(arr[i][j]) t1++;
            else t2++;
        }
    }
    if(t1 > 0 && t2 > 0) {
        s += "(";
        s += go(y, x, n / 2); // 왼위 
        s += go(y, x + n / 2, n / 2); // 오위
        s += go(y + n / 2, x, n / 2); // 왼아
        s += go(y + n / 2, x + n / 2, n / 2); // 오아
        s += ")";
    } else {
        if(t1 > 0) s += "1";
        else s += "0";
    }

    return s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    for(int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for(int j = 0; j < N; j++) {
            arr[i][j] = s[j] - '0';
        }
    }

    cout << go(0, 0, N);
    
    return 0;
}

// (0(0011)(0(0111)01)1)