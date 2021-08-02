#include <bits/stdc++.h>

using namespace std;

// 위클리 챌린지 1주차 부족한 금액 계산하기
// https://programmers.co.kr/learn/courses/30/lessons/82612

long long solution(int price, int money, int count) {
    // 등비수열의 합으로 구하기 (공비는 price이고 항 갯수는 count)
    // 캐스팅 안해주면 overflow가 난채로 totalPay 변수에 값이 대입되어 입력범위에 따라 정답처리가 되지 않는다.
    // 여기서 최대 범위는 아마도 count ^ 2 * price 정도가 될 것인데, 
    // 2500 ^ 3 만 해보더라도 int의 최대범위를 넘어간다.
    long long totalPay = ((long long) (price + (count * price))) * count / 2;
    
    return money >= totalPay ? 0 : (long long) (totalPay - money);
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(NULL); cout.tie(NULL);

   cout << solution(3, 20 , 4);

   return 0;
}