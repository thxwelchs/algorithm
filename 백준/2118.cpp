#include <bits/stdc++.h>

using namespace std;

int N;
int A[50002];
int P[50002];
int ans;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        cin >> A[i];
        P[i] = P[i - 1] + A[i];
    }

    int j = 2;
    for (int i = 1; i <= N; i++)
    {
        while (j <= N)
        {
            int leftSum = P[N] - P[j - 1]; // j기준 i까지의 시계방향의 합
            if (i > 1)
                leftSum += P[i - 1] - P[0];

            int rightSum = P[j - 1] - P[i - 1]; // j기준 i까지의 반시계방향의 합

            ans = max(ans, min(rightSum, leftSum));

            // rightSum이 leftSum보다 같거나 더 커지면
            // j를 더 증가시켜볼 필요가 없다.
            // why? j를 증가시키면 rightSum이 커지고 leftSum은 작아질것이기 때문에
            // rightSum, leftSum중 더 작은 값중 가장 큰 값을 취해야하기 때문에 i를 대상으로 하는 j중에 해당하는 min(rightSum, leftSum) 을 최대로 취하기위함
            // 즉 현재 i의 위치기준에서 j를 변경시켜 탐색해볼 min(rightSum, leftSum) 은 더 이상 기존에 봤던 값보다 더 큰 값이 나올수가 없기 때문임
            if (rightSum >= leftSum)
                break;

            j++;
        }
    }

    cout << ans;

    return 0;
}