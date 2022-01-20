#include <bits/stdc++.h>

using namespace std;

int N, K;
int eatingChocolate, eatingMinDay;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;

    int first;
    cin >> first;

    // 이 문제에서 최선은 모든 i번째 통의 초콜릿들은 1번째 통의 초콜릿과 개수가 똑같아질때까지 먹고 재배치할 수 있다.
    // 먼저 K + 1 번째 초콜릿부터 시작해서 1, 2연산을 하면서 결국 마지막 초콜릿까지 모두 먹을 수 있다.
    // (초콜릿을 먹고 나서 초콜릿의 개수가 오름차순이 되도록 통을 재배치하기 때문에 가능한 것임)
    for (int i = 2; i <= N; i++)
    {
        int a;
        cin >> a;

        // 각 i번째의 초콜릿통의 초콜릿들은 결국 무조건 1번만에 1번째 통의 초콜릿 개수와 똑같아질때까지 먹을 것이다.
        // 즉 1번째 초콜릿통의 초콜릿보다 현재 초콜릿통의 초콜릿 개수가 더 크다면 한번 먹는 횟수와 같다는 것
        // 하지만 1번째 초콜릿과 같은 경우가 있을 수 있기 때문에 이 경우는 제외한다.
        // 물론 if(a == first) continue; 처럼 해도 되겠지?
        if (a > first)
        {
            eatingMinDay++;
        }

        // 현재 초콜릿통에 든 초콜릿 개수는 결국 1번째 초콜릿통과 같아질 것이기 때문에 
        // 1번째 초콜릿통 초콜릿 - 현재 초콜릿통 초콜릿
        eatingChocolate += a - first;
    }

    cout << eatingChocolate << ' ' << eatingMinDay;

    return 0;
}