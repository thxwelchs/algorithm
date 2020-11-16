#include <iostream>
#include <string>
#include <vector>

// 백준 2839 설탕 배달
// https://www.acmicpc.net/problem/2839

using namespace std;

const int MAX = 5000 + 1;
const int INF = (MAX / 5) + (MAX / 3);

int N;
int dp[MAX];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    // N킬로그램을 만들기 위해서는 3킬로그램과 5킬로그램의 조합으로 만들어야 한다.
    // 즉 이것을 최소 봉지수로 판단해보기 위해서는 다음과 같이 생각 할 수 있다.
    /*      
        N킬로그램을 만들기 위한 최소 봉지 수는 min(N - 3 최소 봉지수, N - 5 최소 봉지수) + 1(3이든 5든 봉지 수는 하나 더해질것이기 때문) 이다
        예로, 15킬로그램을 배달하기 위해서는, 
        1. 15에서 3을 뺀 12킬로그램을 배달 할 때 필요했던 최소 봉지수
        2. 15에서 5를 뺀 10킬로그램을 배달 할 때 필요했던 최소 봉지수
        위 1과 2중에서 한 봉지가 더해진 것일것이다.
        그런데 최소 봉지수를 항상 선택해야 하므로  2번을 택한 후 봉지수를 하나 추가해준다.

        그러므로 점화식은 다음과 같이 된다.
        dp[i] = min(dp[i - 3], dp[i - 5]) + 1

    */

    if(N < 3) cout << -1;

    // 최소 값을 구하기 위한 큰 값 설정
    for(int i = 1; i <= N; i++) {
        dp[i] = INF;
    }
    // 3킬로그램 일 때 5킬로그램일 때 최소 봉지수 설정
    dp[3] = 1;
    dp[5] = 1;

    // Bottom Up Dynamic Programming
    // 6킬로 미만 일 때는 사실상 무조건 최소 봉지수가 1개보다 클 수 없으므로 6킬로 부터 bottom up DP 진행
    for(int i = 6; i <= N; i++) {
        dp[i] = min(dp[i - 3], dp[i - 5]) + 1;
    }

    // 구해야 할 값이 INF 이상이라는 것은 3킬로그램과 5킬로그램의 조합으로 구할 수 없는 수라는 것을 의미
    if(dp[N] >= INF) {
        cout << -1;
        return 0;
    }

    cout << dp[N];

    return 0;
}