#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

// 백준 1620 나는야 포켓몬 마스터 이다솜
// https://www.acmicpc.net/problem/1620

unordered_map<string, int> map;
string p[100002];
int N, M;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        string s;
        cin >> s;
        p[i + 1] = s;
        map.insert(make_pair(s, i + 1));
    }

    for(int i = 0; i < M; i++) {
        string s;
        cin >> s;
        if(s[0] >= '0' && s[0] <= '9') {
            int n = stoi(s);
            cout << p[n];
        } else {
            cout << map[s];
        }
        cout << '\n';
    }
    return 0;
}