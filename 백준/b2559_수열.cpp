#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 백준 2559 수열
// https://www.acmicpc.net/problem/2559

const int MAX = 100000 + 1;
int arr[MAX];
int N, K;
long long int res;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> K;
 
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
 
    //초기 배열1 설정
    int s = 0;
    long long int sum = 0;
    for (int i = s; i < s+K; i++) {
        sum += arr[i];
    }
    res = sum;
 
    //배열 탐색
    while (true) {
        //기존 합에 앞에 부분을 뺀다
        sum -= arr[s];
        //배열의 범위를 벗어날 경우
        if (s+K >= N) {
            break;
        }
        //합에 뒷부분을 더한다
        sum += arr[s+K];
        if (sum > res) {
            res = sum;
        }
        //다음 배열 index
        s++;
    }
 
    //출력
    cout << res;
    
    return 0;
}