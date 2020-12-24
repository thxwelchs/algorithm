#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 백준 2979 트럭 주차
// https://www.acmicpc.net/problem/2979

int A, B, C;
int c[3][101];
int total = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> A >> B >> C;
    for(int i=0;i<3;i++) {
        int d, l;
        cin >> d >> l;
        for(int j=d;j<l;j++) c[i][j]++;
    }


    for(int i = 0; i<101;i++) {
        int t = c[0][i]+c[1][i]+c[2][i];
        // cout << t;
        if(t == 1) total += A;
        else if(t == 2) total+= B*t;
        else if(t == 3) total+= C*t;
    }

    cout << total;
    
    return 0;
}