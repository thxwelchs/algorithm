#include<bits/stdc++.h>

using namespace std;

// 백준 2910 반도 정렬
// https://www.acmicpc.net/problem/2910

int N, C;
unordered_map<int, pair<int, int>> m;
vector<pair<int, int> > v;
bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first) {
        return m[a.second].second < m[b.second].second;
    }
    return a.first > b.first;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> C;

    for(int i = 0; i < N; i++) {
        int a;
        cin >> a;
        if(m.find(a) == m.end()) {
            m[a] = make_pair(1, i);
            continue;
        }

        m[a].first++;
    }

    for(const auto i : m) {
        v.push_back(make_pair(i.second.first, i.first));
    }

    sort(v.begin(), v.end(), cmp);

    for(const auto i : v) {
        for(int j = 0; j < i.first; j++) {
            cout << i.second << ' ';
        }
    }
    
    return 0;
}