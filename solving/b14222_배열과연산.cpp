#include <iostream>
#include <string>
#include <vector>

// 백준 14222 배열과 연산 
// https://www.acmicpc.net/problem/14222

using namespace std;

const int MAX = 50 + 1;

int N, K;
int d[MAX]; // 매칭 체크
bool c[MAX]; // 이미 처리한 노드인지 체크

bool dfs(int x) {
    //이미 매칭을 처리한 노드라면 매칭 시켜 볼 필요 없다.
    if(c[x]) return false;

    c[x] = true;

    // x에 K를 더하는 연산을 N 이하 일 때까지 해본다.
    // 즉 왼쪽 그룹{50보다 작거나 같은 자연수}을, 오른쪽 그룹{(A[i] + K * n) <= N 인}에 매칭되는지 DFS를 통해 매칭시켜 본다.
    for(int i = x; i <= N; i+=K) {
        // x는 매칭 시켜 볼 왼쪽 그룹의 노드 번호이다.
        // i는 매칭 시켜 볼 오른쪽 그룹의 노드 번호이다.
        
        if(d[i] == 0 || dfs(d[i])) {
            d[i] = x;
            return true;
        }
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> K;
    int count = 0;
    for(int i = 0; i < N; i++) {
        int a;
        cin >> a;

        // 이미 처리한 노드 체크 다시 풀어주기
        fill(c, c + MAX, false);

        // 매칭이 성공했다면 count 증가
        if(dfs(a)) count++;
    }

    // 매칭된 카운트가 N개 만큼 있다면 1부터 N까지의 수가 모두 하나씩 있는 배열을 만들 수 있는 것
    cout << (int)(count == N);
    
    return 0;
}