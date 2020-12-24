#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 백준 7568 덩치
// https://www.acmicpc.net/problem/7568

pair<int, int> p[51];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int N;
    cin >> N;
    for(int i = 0; i < N; i++) {
        int w, t;
        cin >> w >> t;
        p[i] = make_pair(w, t);
    }

    for(int i=0; i<N;i++) {
        int l = 0;
        for(int j=0;j<N;j++) {
            if(j == i) continue;
            if(p[i].first < p[j].first && p[i].second < p[j].second) l++;
        }

        cout << l + 1 << ' ';
    }
    
    return 0;
}