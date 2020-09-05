#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 백준 16916 부분 문자열
// https://www.acmicpc.net/problem/16916


// LPS(Longest Prefix Suffix) Table 만들기
vector<int> makeLPS(string pattern) {
    int size = pattern.size();
    vector<int> lps(size);

    int j = 0;
    for(int i = 1; i < size; i++) {
        while(j > 0 && pattern[i] != pattern[j]) {
            j = lps[j - 1];
        }

        if(pattern[j] == pattern[i]) lps[i] = ++j;
    }

    return lps;
}

// KMP 탐색
int search(string S, string P) {
    int lenS = S.size();
    int lenP = P.size();
    vector<int> lps = makeLPS(P);

    int j = 0;
    for(int i = 0; i < lenS; i++) {
        // mismatch 됐을 때
        // 해당 부분 전 인덱스의 lps를 참고해서 그만큼 건너 뛸 수 있도록 한다.
        while(j > 0 && S[i] != P[j]) {
            j = lps[j - 1];
        }


        // match가 되고 있는 중...
        if(S[i] == P[j]) {
            // 완전히 패턴에 일치하는 부분이 발견되었을 때 (부분문자열 찾았을 때)
            if(j == lenP - 1) return 1;
            // 계속해서 패턴이 맞는지 확인
            else j++;
        }
    }

    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string S, P;

    cin >> S;
    cin >> P;

    cout << search(S, P);
    
    return 0;
}