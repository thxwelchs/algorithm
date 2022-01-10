#include <bits/stdc++.h>

using namespace std;

int n, k;

// vector<string> v;
vector<int> v;
vector<string> ans;

void backtrack(int sum) {
    if(sum >= n) {
        string s = "";
        s += (char) (v[0] + '0');
        for(int i = 1; i < v.size(); i++) {
            s += "+";
            s += (char) (v[i] + '0');
        }

        // cout << s << '\n';
        ans.push_back(s);

        return;
    }

    for(int i = 1; i <= 3; i++) {
        if(sum + i > n) {
            continue;
        }
        v.push_back(i);
        backtrack(sum + i);
        v.pop_back();
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;

    ans.push_back("0");
    backtrack(0);

    if(k > ans.size() - 1) {
        cout << - 1;
        return 0;
    }

    cout << ans[k];

    return 0;
}