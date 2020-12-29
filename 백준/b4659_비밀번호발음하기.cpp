#include<bits/stdc++.h>

using namespace std;

// 백준 4659 비밀번호 발음하기
// https://www.acmicpc.net/problem/4659

bool isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

bool isAcceptable(string p) {
    int vowel = 0;
    bool check = true;
    for(int i = 0; i < p.size(); i++) {
        if(isVowel(p[i])) {
            vowel++;
        }
        if(i >= 2 && ((isVowel(p[i - 2]) && isVowel(p[i - 1]) && isVowel(p[i])) || (!isVowel(p[i - 2]) && !isVowel(p[i - 1]) && !isVowel(p[i])))
        ) {
            check = false;
            break;
        }
        if(i >= 1 && p[i - 1] == p[i] && (p[i] != 'e' && p[i] != 'o')) {
            check = false;
            break;
        }
    }

    return vowel > 0 && check;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    while(1) {
        string s;
        cin >> s;
        if(s == "end") break;

        cout << "<" + s + ">" << ' ' << "is" << (isAcceptable(s) ? ""  : " not") << " acceptable." << '\n';
    }
    
    return 0;
}