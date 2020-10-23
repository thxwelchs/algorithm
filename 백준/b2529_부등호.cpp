#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// 백준 2529 부등호
// https://www.acmicpc.net/problem/2529

string answer[2];

int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
int output[10] = {};
bool visited[10] = {};
char soi[9];

void permutation(int n, int r, int depth, string sum) {

    if(depth == r) {
        if(answer[0] == "") {
            answer[0] = sum;
        } else {
            answer[1] = sum;
        }
        return;
    }

    for (int i = 0; i < n; i++) {
        if(!visited[arr[i]]) {
            if(depth > 0 && soi[depth - 1] == '<' && output[depth - 1] >= arr[i]) continue;
            else if(depth > 0 && soi[depth - 1] == '>' && output[depth - 1] <= arr[i]) continue;

            visited[arr[i]] = true;
            output[depth] = arr[i];

            string nextSum; 
            nextSum = sum + to_string(output[depth]);

            permutation(n, r, depth + 1, nextSum);
            visited[arr[i]] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int k;

    cin >> k; 
    for(int i = 0; i < k; i++) {
        cin >> soi[i];
    }
    
    permutation(10, k + 1, 0, "");

    cout << answer[1];
    cout << '\n';
    cout << answer[0];

    return 0;
}