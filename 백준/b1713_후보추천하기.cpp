#include<bits/stdc++.h>

using namespace std;

// 백준 1713 후보 추천하기
// https://www.acmicpc.net/problem/1713

// 학생번호, 추천 수, 처음 추가된 시점(인덱스)
map<int, pair<int, int>> m;

int N, R;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> R;

    for(int i = 0; i < R; i++) {
        int s;
        cin >> s;

        if(m.find(s) != m.end()) m[s].first++;
        else {
            if(m.size() >= N) {
                int ct;
                int rmax = 1001;
                for(const auto j : m) {
                    int rr = j.second.first;
                    int fi = j.second.second;

                    if(rr < rmax) {
                        ct = j.first;
                        rmax = rr;
                    } else if(rr == rmax && fi < m[ct].second) {
                        ct = j.first;
                    }
                }

                m.erase(ct);
            }
            m[s] = make_pair(1, i);
        }
    }

    for(const auto i : m) {
        cout << i.first << ' ';
    }
    
    return 0;
}