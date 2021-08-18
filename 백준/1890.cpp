#include <bits/stdc++.h>

using namespace std;

// 정의: d[i][j]는 map[i][j]부터 map[n][n]까지 규칙에 맞게 갈 수 있는 경로의 갯수
// 점화식: d[i][j] = d[i + map[i][j]][j] + d[i][j + map[i][j]]

// map[i][j] : (i,j)에 써져있는 숫자
// 이 변수가 점화식 안에 사용되어야 함

// d[n][n]는 map[n][n]부터 map[n][n]까지 규칙에 맞게 갈 수 있는 경로의 갯수
// 는? 1가지 (가만히 서있기)

int ma[101][101];
long long dp[101][101];
int N;

long long go(int x, int y){ // dp[x][y]를 계산한 다음 반환하는 함수
    if(x > N || y > N) 
        return 0; 
	if(x == N && y == N)
		return 1; // base case
    if(dp[x][y] != -1) 
        return dp[x][y];

    if(ma[x][y] == 0) {
        return 0;
    }
    
    return dp[x][y] = go(x + ma[x][y], y) + go(x, y + ma[x][y]); 
}

int main() {
  
   ios::sync_with_stdio(false);
   cin.tie(NULL); cout.tie(NULL);

   cin >> N;

   for(int i = 1; i <= N; i++) {
       for(int j = 1; j <= N; j++) {
           cin >> ma[i][j];
       }
   }

   memset(dp, -1, sizeof(dp));

   cout << go(1, 1);

   return 0;
}