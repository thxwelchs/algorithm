#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 백준 16916 부분 문자열
// https://www.acmicpc.net/problem/16916


// LPS(Longest Prefix Suffix) Table 만들기
// 접두사와 접미사가 같은 최대 길이
// 1. i와 j위치의 문자가 같을 때는 그 table 자리에 공통 부분 접미사, 접두사 최대 길이를 넣고 그렇지 않을 땐 0을 넣는다.
// 2. i와 j위치의 문자가 같을 때는 i와 j를 둘 다 증가
// 3. 그렇지 않을 때는 i만 증가 (단, j가 0 일 때)
// 4. j가 0보다 클 때에는, 그 전으로 돌아가서 한번 더 i와 비교해주어야 한다.
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
        // 해당 부분 전 인덱스(현재까지 매치된 부분까지의 최대 인덱스)의 lps를 참고해서 그만큼 건너 뛸 수 있도록 한다.
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