#include <iostream>
#include <string>

using namespace std;

// 백준 10808 알파벳 개수
// https://www.acmicpc.net/problem/10808

string s;
int a[26];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> s;

    for(int i = 0; i<s.size();i++) {
        a[s[i] - 'a']++;
    }

    for(int i=0;i<26;i++) {
        cout << a[i] << ' ';
    }

    
    return 0;
}