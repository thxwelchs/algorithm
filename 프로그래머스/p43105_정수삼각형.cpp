#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 프로그래머스 43105 정수삼각형
// https://programmers.co.kr/learn/courses/30/lessons/43105

int dp[501][501];

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    dp[0][0] = triangle[0][0];
    int triangleLen = triangle.size();

    for(int i = 1; i < triangleLen; i++) {
        vector<int> t = triangle[i];
        for(int j = 0; j < t.size(); j++) {
            if(j > 0) {
                dp[i][j] = max(dp[i - 1][j] + t[j], dp[i - 1][j - 1] + t[j]);
            } else {
                dp[i][j] = dp[i - 1][j] + t[j];
            }
        }
    }

    for(int i = 0; i < triangleLen; i++) {
        int d = dp[triangleLen - 1][i];
        if(d > answer) answer = d;
    }

    return answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    solution({
        {7},
        {3, 8},
        {8, 1, 0},
        {2, 7, 4, 4},
        {4, 5, 2, 6, 5}
    });
    
    return 0;
}