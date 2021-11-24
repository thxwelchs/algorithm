#include <bits/stdc++.h>

using namespace std;

int N;
int arr[11][11];
vector<int> v;
int chk[11];
int ans = 10000000;

void backtrack(int n) { // n: 내가 지금까지 n-1개의 정점을 뽑아서 이동했고, 이제 n번째 정점으로 이동해야 함
    if(n > N) {
        int f = v[0], b = v[v.size() - 1];
        if(!arr[b][f]) {
            return;
        }
        int sum = arr[b][f];
        for(int i = 1; i < v.size(); i++) {
            int s = arr[v[i - 1]][v[i]];
            if(!s)
            {
                return;
            }

            sum += s;
        }

        ans = min(ans, sum);
        return;
    }

    for(int i = 1; i <= N; i++)
    {
        // i: 내가 n번째 방문할 정점으로 정점 i를 시도함; 정점 i로 이동하고 싶음
        if (chk[i])
        {
            continue;
        }

        chk[i] = 1;
        v.push_back(i);
        backtrack(n + 1);
        v.pop_back();
        chk[i] = 0;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> arr[i][j];
        }
    }

    backtrack(1);

    cout << ans;

    return 0;
}