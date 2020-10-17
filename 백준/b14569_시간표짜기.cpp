#include <iostream>
#include <string>
#include <bitset>

using namespace std;
unsigned long long a;
typedef unsigned long long ull;

int N, M;
ull subjects[1001];

// 백준 14569 시간표 짜기
// https://www.acmicpc.net/problem/14569

/**
다음 둘의 차이가 있었다.. 형변환의 형태에 따라 다르게 값이 들어가는건지 살펴봐야겠다.
((ull) 1 << st)
((ull) (1 << st))
 */

int main() {
    cin >> N;
    for(int i = 0; i < N; i++) {
        int k;
        cin >> k;

        ull s = 0;

        for(int j = 0; j < k; j++) {
            int st;
            cin >> st;
            s |= ((ull) 1 << st);
        }

        subjects[i] = s;
    }


    cin >> M;
    for(int i = 0; i < M; i++) {
        int candidate = 0;
        int p;
        cin >> p;
        ull s = 0;
        for(int j = 0; j < p; j++) {
            int sp;
            cin >> sp;
            s |= ((ull) 1 << sp);
        }

        for(int j = 0; j < N; j++) {
            if((s & subjects[j]) == subjects[j]) candidate++;
        }
        cout << candidate << "\n";
    }

    return 0;
}