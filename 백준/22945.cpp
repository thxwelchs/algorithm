#include <bits/stdc++.h>

using namespace std;

int N;
int A[100001];
int ans;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    int j = N - 1;
    for (int i = 0; i < N; i++)
    {
        int abil = min(A[j], A[i]);
        int dis = abs(j - i) - 1;
        ans = max(ans, abil * dis);
        // j가 줄어들어야 할 상황은? A[j]가 A[i]보다 더 작을때
        // why? 만약 A[j]가 A[i] 보다 더 클 때 범위를 줄이면 어떻게 될까?
        // 당연히 사이에 있는 개발자 수 dis는 줄어들 것이고, 둘 중 최소 능력치에 대한 부분이 더 큰 숫자로 새롭게 갱신될 것을 기대하지만
        // 이미 그 전의 결과가 A[i]임이 확실하기 때문에 적어도 A[j]가 A[i] 보다 더 작을 때 ans가 갱신이 된다는 것을 의미한다.
        // 그럼 앞으로 바라볼 값들이 더 큰 값이 나올수는 없기 때문에 A[j]가 더 작을때 앞으로 바라볼 값들을 봐야한다.
        if(A[j] < A[i]) {
            i--;
            j--;
        }
    }

    cout << ans;

    return 0;
}