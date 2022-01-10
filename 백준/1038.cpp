#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> v;
vector<long long> lv;

long long get_decreasing_number()
{
    long long e = 1;
    long long s = 0;
    for (int i = v.size() - 1; i >= 0; i--)
    {
        s += ((long long)v[i]) * e;
        e *= 10;
    }

    return s;
}

void backtrack(int idx, int n)
{
    if (idx >= n)
    {
        lv.push_back(get_decreasing_number());
        return;
    }

    for (int i = 9; i >= 0; i--)
    {
        // 전에 봤던 숫자 (더 큰 자릿수의 숫자)가 추가하려는 숫자보다 작거나 같으면 넘어간다
        if (v.size() && v.back() <= i)
            continue;

        v.push_back(i);
        backtrack(idx + 1, n);
        v.pop_back();
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    if (N > 1022)
    {
        cout << -1;
        return 0;
    }

    for (int i = 10; i >= 1; i--)
    {
        v.clear();
        backtrack(0, i);
    }

    sort(lv.begin(), lv.end());

    cout << lv[N];

    return 0;
}