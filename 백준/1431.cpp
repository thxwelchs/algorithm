#include <bits/stdc++.h>

using namespace std;

int N;
string arr[1001];
unordered_map<string, int> um;

bool cmp(string a, string b) {
    if(a.size() == b.size()) {
        if(um[a] == um[b]) {
            return a < b;
        } else {
            return um[a] < um[b];
        }
    } else {
        return a.size() < b.size();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for(int i = 0; i < N; i++) {
        string s;
        cin >> s;
        arr[i] = s;
        int sum = 0;
        for(int j = 0; j < s.size(); j++) {
            if(s[j] >= '0' && s[j] <= '9') {
                sum += s[j] - '0';
            }
        }
        um[s] = sum;
    }

    sort(arr, arr + N, cmp);

    for(int i = 0; i < N; i++) {
        cout << arr[i] << '\n';
    }
    
    return 0;
}