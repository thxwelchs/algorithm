#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 백준 10988 팰린드롬인지 확인하기
// https://www.acmicpc.net/problem/10988

string s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> s;

    int size = s.size();
    bool check = true;

    for(int i=0;i<size;i++) {
        check = check && s[i] == s[size - 1 - i];
    }

    cout << check ? 1 : 0;
    
    return 0;
}