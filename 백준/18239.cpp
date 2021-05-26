#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;

    cin >> n >> k;

    /**
     *
     * 애드혹 문제 특성상 이 문제에 대해 충분한 아이디어를 고려해서 푸는 문제이다. 
     * 많은 시간을 투자했으나 결국 풀리지 않아 아래 블로그에서 해설을 보고 그대로 구현했다.
     * https://hellogaon.tistory.com/75
     * 
     * 먼저 이 문제의 핵심은 3번의 연산으로 편안한 수열을 만들 수 있다면, 나머지 2번을 채우는 것은 전체를 reverse 하는 연산을 2번 더 채우면 총 5번으로
     * 해를 찾을 수 있는 것이었다.
     * 일반적으로는 3번의 reverse로 편안한 수열을 만들 수 있다.
     * reverse 1 n
     * reverse 1 n - k
     * reverse n - k + 1 n
     * 
     * 그런데 위 3번으로 편안한 수열을 만들지 못하는 경우가 있는데 다음과 같다.
     * 1. n이 3인 경우 (이 경우에는 어떤 경우를 대입해봐도 절대로 5번의 연산으로 편안한 수열을 만들 수 없다.)
     * 2. n이 2인 경우 (이 경우에는 위 reverse 3번의 연산으로 편안한 수열을 만들 수 없다.)
     * 3. k가 1인경우 (이 경우에도 마찬가지로 위 reverse 3번의 연산으로 편안한 수열을 만들 수 없다.)
     * 3. k가 n - 1인경우 (이 경우에도 마찬가지로 위 reverse 3번의 연산으로 편안한 수열을 만들 수 없다.)
     */

    if(n == 3) {
        cout << "NO";
        return 0;
    }

    cout << "YES" << '\n';

    if(n == 2) {
        cout << "swap 1 2" << '\n';
        cout << "swap 1 2" << '\n';
        cout << "swap 1 2" << '\n';
        cout << "reverse 1 2" << '\n';
        cout << "reverse 1 2" << '\n';
        return 0;
    }

    if(k == 1) {
        cout << "swap 1 2" << '\n';
        cout << "reverse 2 " << n << '\n';
        cout << "reverse 2 " << n - 1 << '\n';
        cout << "reverse 1 " << n << '\n';
        cout << "reverse 1 " << n << '\n';
    } else if(k == n - 1) {
        cout << "swap " << n - 1 << " " << n << '\n';
        cout << "reverse 1 " << n - 1 << '\n';
        cout << "reverse 2 " << n - 1 << '\n';
        cout << "reverse 1 " << n << '\n';
        cout << "reverse 1 " << n << '\n';
    } else {
        cout << "reverse 1 " << n << '\n';
        cout << "reverse 1 " << n - k << '\n';
        cout << "reverse " << n - k + 1  << " " << n << '\n';
        cout << "reverse 1 " << n << '\n';
        cout << "reverse 1 " << n << '\n';
    }
    
    return 0;
}