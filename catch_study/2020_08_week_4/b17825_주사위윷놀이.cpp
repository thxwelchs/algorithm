#include <iostream>
#include <string>
#include <time.h>

using namespace std;

struct Board {
    int index;
    int score;
    int next;
    int fast = -1;
};

int dice[10];
Board boards[33];
int horses[5] = {0};

int d[10];
int v[10];
int result = 0;

void DFS(int depth, int sum) {

    // 기저 종료 시점 (주사위 다 던졌을 때)
    // 모든 말들의 점수 총 합을 비교해본다.
    if(depth == 10) {
        if(sum > result) {
            result = sum;
        }

        // for(int i = 0; i < 10; i++) {
        //     cout << d[i];
        // }
        // cout << endl;
        return;
    }

    for(int i = 1; i <= 4; i++) {
        if(!v[depth]) {
            v[depth] = true;
            d[depth] = i;
            // 여기서 노드 방문해서 점수 획득
            int horse = horses[i]; // 현재 턴에서 움직여야 할 말 = i, horse = 말의 현재 위치
            int next, fast;
            sum += boards[horse].score;
            next = boards[horse].next;
            for(int i = 1; i <= dice[depth] - 1; i++) {
                if(boards[next].fast != -1) {
                    next = boards[next].fast;
                } else {
                    next = boards[next].next;
                }
            }

            horses[i] = (next > 32 || next == -1) ? 0 : next;
            if(horses[next] <= 0) {
                sum += (next > 32 || next == -1) ? 0 : boards[next].score;
            } 

            DFS(depth + 1, sum);
            v[depth] = false;
        }
    }
}

void makeBoard() {
    for(int i = 1; i <= 20; i++) {
        boards[i] = {i, i * 2};
        boards[i - 1].next = i;
    }
    boards[5].fast = 21;
    boards[10].fast = 24;
    boards[15].fast = 26;

    boards[21] = {21, 13, 22};
    boards[22] = {22, 16, 23};
    boards[23] = {23, 19, 29};
    boards[24] = {24, 22, 25};
    boards[25] = {25, 24, 29};
    boards[26] = {26, 28, 27};
    boards[27] = {27, 27, 28};
    boards[28] = {28, 26, 29};
    boards[29] = {29, 25, 30}; //center
    boards[30] = {30, 30, 31};
    boards[31] = {31, 35, 32};
    boards[32] = {32, 40, -1};
}

int main() {
    // time_t start, end;
 
    // start = time(NULL); //시간 측정 시작
    makeBoard();
    DFS(0, 0);
    // end = time(NULL); //시간 측정 끝
    // cout << (end - start) << endl;
    cout << result;
    
    return 0;
}