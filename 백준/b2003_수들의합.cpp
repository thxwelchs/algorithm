#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 백준 2003 수들의 합
// https://www.acmicpc.net/problem/2003

int N, M;
int arr[10000];
int sum = 0;

int two_pointer() {
    int count = 0;
    int start, end;

    // 시작, 끝 포인터를 처음에는 0으로 설정
    start = end = 0;
    // 출발할 값은 현재 첫번째 자리의 값 
    sum = arr[0];

    // 두 포인터가 배열 끝에 도달할 때까지 진행
    while(start < N && end < N) {
        // 현재 부분 합이 M과 같다면 카운트
        if(sum == M) {
            count++;
        }

        // 현재 부분합이 M보다 작거나 크다면 end를 증가시키고 현재 부분합에 값을 더해준다.
        if(sum <= M) sum += arr[++end];
        // 현재 부분합이 M보다 크다면 기존의 start의 원소값을 현재 부분합에서 빼주고, start 포인터를 하나 증가
        else if(sum > M) sum -= arr[start++];
    }

    return count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    cout << two_pointer();
    
    return 0;
}