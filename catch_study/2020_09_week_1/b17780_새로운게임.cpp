#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

// 백준 17780 새로운 게임 
// https://www.acmicpc.net/problem/17780

/**
 * 로컬 테스트에서는 발견되지 않는 런타임 에러가 백준에서 계속 발생한다..
 * 이유를 모르겠다.
 */

int N, K;  //체스판의 크기, 말의 갯수

struct Horse {
    int x; // 행
    int y; // 열
    int d; // 방향
};

int color[14][14]; // 체스판의 색
int board[14][14][4]; // 체스판 각 칸에 서있는 말 (4마리 이상 일 땐 채워넣지 않을 것임)
int horseCount[14][14]; // 체스판 각 칸에 서있는 말의 갯수
Horse horses[11]; // 말 (index가 말 번호)


bool move(int n) {

    Horse horse = horses[n];

    int nextX = horse.x;
    int nextY = horse.y;

    // 1, 2, 3, 4
    // →, ←, ↑, ↓
    // 다음칸을 결정한다.
    if(horse.d == 1) nextY++;
    else if(horse.d == 2) nextY--;
    else if(horse.d == 3) nextX--;
    else if(horse.d == 4) nextX++;


    int c = color[nextX][nextY];
    int curHorseCount = horseCount[horse.x][horse.y];
    int nextHorseCount = horseCount[nextX][nextY];
    // 흰색
    if(c == 0) {
        // 옮기고 난 뒤의 총 갯수가 4개이상이라고 판단 될 때 
        if(curHorseCount + nextHorseCount >= 4) {
            return true;
        }

        // 기존의 말들을 다음 칸위로 올린다.
        for(int x = 0; x < curHorseCount; x++) {
            int h = board[horse.x][horse.y][x];
            board[nextX][nextY][nextHorseCount + x] = h;

            // 옮겨진 말들의 위치값 새롭게 갱신
            horses[h].x = nextX;
            horses[h].y = nextY;

            // 현재자리에 있는 말들은 초기화
            board[horse.x][horse.y][x] = 0;
        }
        // 체스판 위에 서있는 말 카운트 갱신
        horseCount[nextX][nextY] += curHorseCount;
        horseCount[horse.x][horse.y] = 0;
    }
    // 빨간색
    else if(c == 1) {
        // 옮기고 난 뒤의 총 갯수가 4개이상이라고 판단 될 때 
        if(curHorseCount + nextHorseCount >= 4) {
            return true;
        }

        // 기존의 말들을 다음 칸위로 뒤집어서 올린다.
        int idx = 0;
        for(int x = curHorseCount - 1; x >= 0; x--){
            int h = board[horse.x][horse.y][x];
            board[nextX][nextY][nextHorseCount + (idx++)] = h;

            // 옮겨진 말들의 위치값 새롭게 갱신
            horses[h].x = nextX;
            horses[h].y = nextY;

            // 현재자리에 있는 말들은 초기화
            board[horse.x][horse.y][x] = 0;
        }
        // 체스판 위에 서있는 말 카운트 갱신
        horseCount[nextX][nextY] += curHorseCount;
        horseCount[horse.x][horse.y] = 0;
    }
    // 파란색 혹은 체스판 범위 밖
    else {
        // 방향을 반대 방향으로 전환한다. 
        if(horse.d == 1) horses[n].d = 2, nextY = horse.y - 1;
        else if(horse.d == 2) horses[n].d = 1, nextY = horse.y + 1;
        else if(horse.d == 3) horses[n].d = 4, nextX = horse.x + 1;
        else if(horse.d == 4) horses[n].d = 3, nextX = horse.x - 1;

        // 방향을 전환한 뒤 의 색을 살펴본다.
        int nextColor = color[nextX][nextY];
        // 다음 칸의 색이 흰색 혹은 빨간색에 해당한다면 다시 이동해서 체크
        if(nextColor == 0 || nextColor == 1) {
            return move(n);
        }
    }

    return false;
}


int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    cin >> N >> K;

    memset(color, -1, sizeof(color));

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            cin >> color[i][j];
        }
    }

    for(int i = 1; i <= K; i++) {
        int r, c, d;
        cin >> r >> c >> d;
        Horse horse = { r, c, d };

        horses[i] = horse;
        board[r][c][0] = i;
        horseCount[r][c] = 1;
    }


    // 1턴부터 출발해서 1000턴 까지 시도해본다. 
    for(int i = 1; i <= 1000; i++) {
        for(int j = 1; j <= K; j++) {
            // 말이 가장 아래에 있는 말이 아닐 경우 이동 불가능
            if(j != board[horses[j].x][horses[j].y][0]) continue;

            if(move(j)) {
                cout << i << endl;
                return i;
            }
        }
    }

    cout << -1 << endl;
    
    return 0;
}