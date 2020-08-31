#include <iostream>
#include <string>
#include <vector>

using namespace std;

// // 백준 7579 앱
// // https://www.acmicpc.net/problem/7579

const int MAX = 100;

int main() {

    int N, M;
    cin >> N >> M;

    int memories[MAX];
    int costs[MAX];

    // DP 배열 dp[i], i = 비활성화 시 비용(cost)
    // 비용이 아무리 많이 발생해도 10000을 넘어가지 않는다. 최악의 경우 비활성화 시 100 비용이 발생하는 100개의 메모리가 있다고 해도 100 * 100 = 10000
    // dp[i] i 만큼의 비용을 들여서 얻을 수 있는 이전까지 메모리를 포함한 합을 의미
    int dp[MAX * MAX + 1];

    for(int i = 0; i < N; i++) {
        cin >> memories[i];
    }

    // 비용 0부터 모든 비용을 더한 것 까지의 메모리 합 dp를 구하기 위해 비용 총합 더하기
    int totalCost = 0;

    for(int i = 0; i < N; i++) {
        cin >> costs[i];
        totalCost += costs[i];
    }

    for(int i = 0; i < N; i++) {
        // 최근의 메모리 합과, 현재 메모리 + 현재 비용과 구해야할 비용에서 남는 메모리 중 더 큰 값
        // 만약 역 루프가 아니라면, 지금 구해야 할 비용보다 작은 비용의 현재 비용의 기준으로 메모리 값이 갱신되어져 버리기 때문에 잘못된 계산이 이루어진다.
        for(int j = totalCost; j >= costs[i]; j--) {
            int remain = j - costs[i];
            dp[j] = max(dp[j], memories[i] + dp[remain]);
        }
    }

    // 모든 비활성화 비용별 메모리 합을 구해놓았기 때문에 dp[i] 에는 i의 비용을 들여 최대 가용할 수 있는 메모리값이 저장되어 있다.
    int answer = 0;
    for(int i = 0; i <= totalCost; i++) {
        if(dp[i] >= M) {
            answer = i;
            break;
        }
    }

    cout << answer << endl;

    return 0;
}

// 2차원 dp 방법 (메모리 낭비를 줄일 수 있는 1차원 dp로도 해결 할 수 있어서 사용하지 않는다.)

// #include <iostream>
// #include <string>
// #include <vector>

// using namespace std;


// const int MAX = 100;

// int main() {

//     int N, M;
//     cin >> N >> M;

//     int memories[MAX];
//     int costs[MAX];

//     // DP 배열 dp[i][j], i = memory, j = 비활성화 시 비용
//     // 비용이 아무리 많이 발생해도 10000을 넘어가지 않는다. 최악의 경우 비활성화 시 100 비용이 발생하는 100개의 메모리가 있다고 해도 100 * 100 = 10000
//     // dp[i][j] = j 만큼의 비용을 들여서 얻을 수 있는 i와 i 이전까지 메모리를 포함한 합을 의미
//     int dp[MAX][MAX * MAX + 1];

//     for(int i = 0; i < N; i++) {
//         cin >> memories[i];
//     }

//     // 비용 0부터 모든 비용을 더한 것 까지의 메모리 합 dp를 구하기 위해 비용 총합 더하기
//     int totalCost = 0;
//     for(int i = 0; i < N; i++) {
//         cin >> costs[i];
//         totalCost += costs[i];
//     }

//     // 첫번째 메모리 비활성화 비용으로 얻을 수 있는 메모리를 미리 계산해놓는다.
//     for(int i = 0; i <= totalCost; i++) {
//         dp[0][i] = costs[0] <= i ? memories[0] : 0;
//     }

//     // O(1000000)
//     // 두번째 메모리부터 시작
//     for(int i = 1; i < N; i++) {
//         for(int j = 0; j <= totalCost; j++) {
//             // 구해야 할 비용보다 현재 메모리 비용이 더 작다면 미리 계산해놓았던 최근의 메모리 합(현재 비용으로 얻을 수 있는 최대 메모리 보장)을 사용
//             if(costs[i] > j) {
//                 dp[i][j] = dp[i - 1][j];
//                 continue;
//             }
            
//             // 최근의 메모리 합과, 현재 메모리 + 현재 비용과 구해야할 비용에서 남는 메모리 중 가장 큰 값
//             int remain = j - costs[i];
//             dp[i][j] = max(dp[i - 1][j], memories[i] + dp[i-1][remain]);
//         }
//     }

//     int answer = 0;
//     for(int i = 0; i < totalCost; i++) {
//         // i = 비용, N - 1 가장 마지막 구했던 DP 이므로 비용별 최대 메모리가 계산되어있다.
//         if(dp[N - 1][i] >= M) {
//             answer = i;
//             break;
//         }
//     }

//     cout << answer << endl;

//     return 0;
// }

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