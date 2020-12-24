#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 백준 1159 농구경기
// https://www.acmicpc.net/problem/1159

int N;
int n[26];
vector<char> v;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;

    while(N--) {
        string s;
        cin >> s;
        n[s[0] - 'a']++;
    }

    for(int i=0;i<26;i++) {
        if(n[i] >= 5) v.push_back((char) (i + 'a'));
    }

    if(v.size() == 0) {
        cout << "PREDAJA";
        return 0;
    }

    sort(v.begin(), v.end());

    for(int i=0;i<v.size();i++){
        cout << v[i];
    }
    
    return 0;
}