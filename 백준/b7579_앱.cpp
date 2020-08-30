#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 백준 7579 앱
// https://www.acmicpc.net/problem/7579

const int MAX = 100;

int main() {

    int N, M;
    cin >> N >> M;

    int memories[MAX];
    int costs[MAX];
    int dp[MAX][MAX * MAX + 1];

    for(int i = 0; i < N; i++) {
        cin >> memories[i];
    }

    int totalCost = 0;

    for(int i = 0; i < N; i++) {
        cin >> costs[i];
        totalCost += costs[i];
    }

    for(int i = 0; i <= totalCost; i++) {
        dp[0][i] = costs[0] <= i ? memories[0] : 0;
    }

    for(int i = 1; i < N; i++) {
        for(int j = 0; j <= totalCost; j++) {
            if(costs[i] > j) {
                dp[i][j] = dp[i - 1][j];
                continue;
            }
            int remain = j - costs[i];
            dp[i][j] = max(dp[i - 1][j], memories[i] + dp[i-1][remain]);
        }
    }

    int answer = 0;
    for(int i = 0; i < totalCost; i++) {
        if(dp[N - 1][i] >= M) {
            answer = i;
            break;
        }
    }

    cout << answer << endl;

    return 0;
}



// 모든 경우의 수를 조합해서 가장 최소의 비용이 드는 것을 반환하게끔 했더니 시간초과 뜸

// void permutation(vector<int> arr, vector<int> w, vector<bool> visited, int N, int r, int ws, int M, int *answer) {

//     if(M == r) {
//         if(ws < *answer) {
//             *answer = ws;
//         }

//         return ;
//     }

//     for (int i = 0; i < N; i++) {
//         if(!visited[i]) {
//             visited[i] = true;
//             permutation(arr, w, visited, N, r + arr[i], ws + w[i], M, answer);
//             visited[i] = false;
//         }
//     }
// }

// int main() {

//     int N, M;
//     cin >> N >> M;

//     vector<int> mem(N);
//     vector<int> weight(N);
//     vector<int> output(N); 
//     vector<bool> visited(N);
//     int answer = 1000000001;

//     for(int i = 0; i < N; i++) {
//         cin >> mem[i];
//     }

//     for(int i = 0; i < N; i++) {
//         cin >> weight[i];
//     }

//     permutation(mem, weight, visited, N, 0, 0, M, &answer);

//     cout << answer << endl;
    
//     return 0;
// }