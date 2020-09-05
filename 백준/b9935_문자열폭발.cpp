#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 백준 9935 문자열 폭발
// https://www.acmicpc.net/problem/9935

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    string N, P;
    char a[1000000];

    cin >> N >> P;

    int strSize = N.size(), bombSize = P.size();

    int j = 0;
    int count = 0;
    for(int i = 0; i < strSize; i++) {
        a[j++] = N[i];

        if (a[j - 1] == P[bombSize - 1] && j >= bombSize) {

            int o = 0;
            bool isAllMatch = true;
            for (int x = bombSize - 1; x >= 0; x--) {
                if (a[j - 1 - (bombSize - 1 - x)] != P[x]) {
                    isAllMatch = false;
                    break;
                }
            }

            if (isAllMatch) {
                count++;
                j -= bombSize;
            }
        }
    }
    if(count * bombSize == strSize) {
        cout << "FRULA";
        return 0;
    }

    for(int i = 0; i < strSize - count * bombSize; i++) {
        cout << a[i];
    }

    return 0;
}

// string N, P, S;

// vector<int> makeLPS(string p) {
//     int len = p.size();
//     vector<int> lps(len);

//     int j = 0;
//     for(int i = 1; i < len; i++) {
//         // 그 전 패턴(접두사와 접미사가 같았던 곳) 이 맞았던 곳 까지 검사해야 하기 때문에 그 전 위치로 이동하면서 검사
//         while(j > 0 && p[i] != p[j]) {
//             j = lps[j - 1];
//         }

//         // j까지는 접두사와 접미사가 일치했다고 봐야하기 때문에 다음 접두사 검사 부분을 1증가
//         if(p[j] == p[i]) {
//             lps[i] = ++j;
//         }
//     }

//     return lps;
// }

// int KMP(string N, string P) {
//     vector<int> lps = makeLPS(P);
//     int lenN = N.size();
//     int lenP = P.size();

//     if(lenP > lenN) return -1;

//     int matchCount = 0;

//     int j = 0;
//     for(int i = 0; i < lenN; i++) {
//         // 패턴 미스매치 체크해서 가장 최근에 매치되었던 부분부터 다시 검사하기 위한 처리
//         while(j > 0 && N[i] != P[j]) {
//             S.push_back(N[i]);
//             // 미스매치 된 현재의 전 인덱스에 위치한 lps값을 참조하여 그 위치부터 다시 패턴을 맞춰본다.
//             // 하나씩 내려가며 결국 lps가 0이 아닌(prefix, suffix 공통된 부분이 일치하는 패턴 인덱스) 가장 높은 값을 참조하게 될 것임
//             j = lps[j - 1];
//         }

//         if(N[i] == P[j]) {
//             // 일치하는 패턴을 찾았을 경우 (j가 패턴의 끝이 되었을 때)
//             if(j == lenP - 1) {
//                 // 패턴이 일치했던 주어진 문자 N의 처음 문자열 처음 인덱스 반환
//                 // return i - lenP + 1;
//                 matchCount++;
//                 j = 0;
//             } 
//             // 계속해서 비교하기 위해 j를 1씩 증가
//             else {
//                 j++;
//             }
//         } else {
//             S.push_back(N[i]);
//             // cout << N[i];
//         }
//     }

//     return matchCount > 0 ? matchCount : 0;
// }

// int main() {
//     cin >> N >> P;
//     while(KMP(N, P)) {
//         N = S;
//         if(S == "") {
//             cout << "FRULA" << endl;
//             return 0;
//         }
//         S = "";
//     }
//     cout << S << endl;

    
//     return 0;
// }