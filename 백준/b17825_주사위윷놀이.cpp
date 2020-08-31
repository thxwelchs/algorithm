#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 백준 17825 주사위 윷놀이
// https://www.acmicpc.net/problem/17825

struct Board {
    int index;
    int score;
    int next;
    int fast;
};

int dice[10];
Board boards[33];
int horses[4] = {0};

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
    makeBoard();
    for(int i = 0; i < 10; i++) {
        dice[i] = 1;
    }

    int count = 0;

    for(int i = 0; i < 10; i++ ) {

    }

    
    return 0;
}
