#include <bits/stdc++.h>

using namespace std;

int N, M;
int A[100001];
int ans = 2e9;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    // 단조증가성을 보장하기 위한 정렬
    sort(A, A + N);

    // i
    // 1 3 5
    //     j
    // O(N^2) 풀이처럼 각 i에 대해서 모든 j를 살펴보는 것이 아니라, 이전의 j 값을 활용하는 것이 투포인터이다.
    int j = 0;
    for (int i = 0; i < N; i++)
    {
        // j와 i의 차가 M보다 작으면 단조증가성이 보장되는 수열에서 j의 포인터를 증가시켜야 한다.
        // why? i를 증가시키면 차가 더 작아지면 작아졌지 커지지는 않을 것이고 j를 증가시켜야 차가 커질것이다
        while (j < N - 1 && A[j] - A[i] < M)
            j++;

        // 이곳의 j는 항상 A[j] - A[i]가 M이상일 경우의 최초 지점 이후의 포인터이다.
        // 하지만 i로 인해 A[j] - A[i]가 M 미만일 수 있다.
        if (A[j] - A[i] < M)
            break;

        ans = min(ans, A[j] - A[i]);
    }

    cout << ans;

    return 0;
}