#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 백준 11655 ROT13
// https://www.acmicpc.net/problem/11655

string s;
vector<char> v;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    getline(cin, s); // cin은 개행 문자까지만 입력
    // cin >> s;

    for(int i=0;i<s.size();i++) {
        if(s[i] >= 'a' && s[i] <= 'z') {
            v.push_back((char) ((s[i] - 'a' + 13) % 26) + 'a');
        } else if(s[i] >= 'A' && s[i] <= 'Z') {
            v.push_back((char) ((s[i] - 'A' + 13) % 26) + 'A');
        } else {
            v.push_back(s[i]);
        }
    }

    for(char c : v) {
        cout << c;
    }
    
    return 0;
}