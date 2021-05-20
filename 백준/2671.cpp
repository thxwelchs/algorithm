#include <bits/stdc++.h>

using namespace std;

// 직접 정규표현식을 해석하는 해석 함수를 만들어보는게 의미가 있을 것 같은데..
// 나중에 해보는 것으로

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;
    cin >> s;

    regex re("(100+1+|01)+");
    cout << (regex_match(s, re) ? "SUBMARINE" : "NOISE");
    
    return 0;
}