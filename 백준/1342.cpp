#include <bits/stdc++.h>

using namespace std;

string S;
int N;
vector<char> v;
int vis[11];
int fac[27];
int alpha[27];
int ans;

int fact(int n) {
    if(n == 0)
        return 0;
    if(n == 1) 
        return 1;

    return fact(n - 1) * n;
}

bool is_luck_str()
{
    for (int i = 1; i < N; i++)
    {
        if(v[i - 1] == v[i])
        {
            return false;
        }
    }

    return true;
}

void backtrack(int idx)
{
    if (idx >= N)
    {
        if (is_luck_str())
        {
            ans++;
        }
        return;
    }

    for (int i = 0; i < N; i++)
    {
        if (vis[i])
            continue;

        vis[i] = 1;
        v.push_back(S[i]);
        backtrack(idx + 1);
        v.pop_back();
        vis[i] = 0;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> S;

    N = S.length();
    for(int i = 0; i < N; i++) {
        alpha[S[i] - 'a']++;
    }

    backtrack(0);

    for(int i = 0; i < 27; i++) {
        if(!alpha[i]) 
            continue;

        ans /= fact(alpha[i]);
    }

    cout << ans;

    return 0;
}