#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 백준 1756 피자굽기
// https://www.acmicpc.net/problem/1756

int main() {
    int D, N;

    cin >> D >> N;
    
    vector<int> oven(D);
    vector<int> dough(N);

    for(int i = 0; i < D; i++) {
        int input;
        cin >> input;
        oven[i] = (i > 0 && input >= oven[i - 1] ? oven[i - 1] : input);
    }

    for(int i = 0; i < N; i++) {
        int input;
        cin >> input;
        dough[i] = input;
    }

    int j = 0;
    int answer = 0;

    for(int i = D - 1; i >= 0; i--) {
        // oven 가장 깊숙한 곳에서부터 반죽을 넣을 수 있는지 본다.
        // 해당 oven 자리에 반죽이 들어갔다면 다음 반죽으로 넘어가기
        if(dough[j] <= oven[i]) {
            j++;
        }

        // 모든 반죽을 오븐에 다 넣었다면, 현재 자리가 가장 마지막에 들어간 반죽이 들어간 자리이다.(오븐 번호는 배열 인덱스 + 1이다.)
        if(j == N) {
            answer = i + 1;
            break;
        }
    }

    cout << (j == 0 ? j : answer) << endl;

    return 0;
}