#include <iostream>
#include <string>

using namespace std;

// 백준 3019 테트리스
// https://www.acmicpc.net/problem/3019

int check(int C, int P, int h[], int i) {   
    int count = 0;

    switch (P) {
    case 1:
        // none rotate
        count++;

        // rotate -90deg
        if(i + 3 <= C - 1 && h[i] == h[i + 1] && h[i] == h[i + 2] && h[i] == h[i + 3]) count++;

        break;
    case 2:
        // none rotate
        if(i + 1 <= C - 1 && h[i] == h[i + 1]) count++;

        break;
    case 3:
        // none rotate
        if(i + 2 <= C - 1 && h[i] == h[i + 1] && h[i + 2] - h[i] == 1) count++;

        // rotate -90deg
        if(i + 1 <= C - 1 && h[i] - h[i + 1] == 1) count++;

        break;
    case 4:
        // none rotate
        if(i + 2 <= C - 1 && h[i + 1] == h[i + 2] && h[i] - h[i + 1] == 1) count++;

        // rotate -90deg
        if(i + 1 <= C - 1 && h[i + 1] - h[i] == 1) count++;

        break;
    case 5:
        // none rotate
        if(i + 2 <= C - 1 && h[i] == h[i + 1] && h[i] == h[i + 2]) count++;

        // rotate -90deg
        if(i + 1 <= C - 1 && h[i] - h[i + 1] == 1) count++;

        // rotate -180deg
        if(i + 2 <= C - 1 && h[i] - h[i + 1] == 1 && h[i + 2] - h[i + 1] == 1) count++;

        // rotate -270deg
        if(i + 1 <= C - 1 && h[i + 1] - h[i] == 1) count++;

        break;
    case 6:
        // none rotate
        if(i + 2 <= C - 1 && h[i] == h[i + 1] && h[i] == h[i + 2]) count++;

        // rotate -90deg
        if(i + 1 <= C - 1 && h[i] - h[i + 1] == 2) count++;

        // rotate -180deg
        if(i + 2 <= C - 1 && h[i + 1] - h[i] == 1 && h[i + 2] - h[i] == 1) count++;

        // rotate -270deg
        if(i + 1 <= C - 1 && h[i] == h[i + 1]) count++;

        break;
    case 7:
        // none rotate
        if(i + 2 <= C - 1 && h[i] == h[i + 1] && h[i] == h[i + 2]) count++;

        // rotate -90deg
        if(i + 1 <= C - 1 && h[i] == h[i + 1]) count++;

        // rotate -180deg
        if(i + 2 <= C - 1 && h[i] - h[i + 2] == 1 && h[i + 1] - h[i + 2] == 1) count++;

        // rotate -270deg
        if(i + 1 <= C - 1 && h[i + 1] - h[i] == 2) count++;

        break;
    default:
        break;
    }

    return count;
}

int main() {
    int C, P;
    int h[100] = {};
    cin >> C >> P;

    for(int i = 0; i < C; i++) {
        cin >> h[i];
    }

    int answer = 0;

    for(int i = 0; i < C; i++) {
        answer += check(C, P, h, i);
    }

    cout << answer << endl;

    
    return 0;
}