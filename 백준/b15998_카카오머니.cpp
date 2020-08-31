#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <cmath>

using namespace std;

const long long MAX = pow(10, 18);

// 백준 15998 카카오머니
// https://www.acmicpc.net/problem/15998

long long gcd(long long a, long long b) {
    long long tmp, r;
    if(a < b) {
        tmp = a;
        a = b;
        b = tmp;
    }

    while(b!=0) {
        r = a % b;
        a = b;
        b = r;
    }

    return a;
}

long long solve(vector<pair<long long, long long>> logs, int N) {
    long long g = 0, prev = 0;
    // 그 전 로그에서 충전 후 출금 했을 때의 남은 잔고를 들고 다닐 변수
    long long prevMin = MAX;

    for(int i = 0; i < N; i++) {
        long long a = logs[i].first;
        long long b = logs[i].second;

        // 출금
        if(a < 0) {
            // 충전의 경우: 출금할 금액이 보유한 잔액보다 클 때
            if(prev + a < 0) {
                // 충전의 경우인데 충전액이 0 이하일순 없다.
                if (b - a - prev <= 0) {
                    return -1;
                }

                // 그 전 충전액의 최대공약수를 포함한 최대 공약수 구하기
                g = gcd(g, b - a - prev);

                // 충전 후 결제했을 때 경우의 남은 잔고값을 들고 다닌다.
                if(b > 0 && b < prevMin) {
                    prevMin = b;
                }

                // 충전단위가 1일때는 잔액이 남아있을 수 가 없다.
                if(g == 1 && b > 0) {
                    return -1;
                }

                // 새로운 gcd를 구했는데, 그 gcd 값이 prevMin 값보다 작을 순 없다.
                if(prevMin != MAX && g <= prevMin) {
                    return -1;
                }
            } else {
                // 충전이 필요하지 않은데, 충전액이 0보다 클 순 없다.
                // 충전액이 음수가 될 수 있는 상황이 고려되므로 0보다 작은것이 아닌 0이 아닌 조건으로 변경해주어야 함
                if(b - a - prev != 0) {
                    return -1;
                }
            }
        } else {
            // 입금의 경우인데 입금 후 잔액과 맞지 않는 경우
            if(prev + a != b) {
                return -1;
            }
        }

        prev = b;
    }

    return g == 0 ? 1 : g;
}

int main() {
    int N;
    cin >> N;
    long long g = 0, prev = 0;
    vector<pair<long long, long long>> logs(N);
    int count = 0;
    for(int i = 0; i < N; i++) {
        long long a, b;
        cin >> a >> b;
        logs[i] = make_pair(a, b);

    }


    cout << solve(logs, N) << endl;
}

