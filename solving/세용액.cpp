#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

typedef long long ll;

int N;
int solutions[5000];
int answer[3];
ll minOfSum = 1000000001;

void dfs(int arr[], int p[], unordered_set<int> visited, int n, int r, int depth, ll sum) {

    if(depth == r && (ll)abs(sum) < minOfSum) {
        minOfSum = (ll)abs(sum);

        for(int i = 0; i < r; i++) {
            answer[i] = p[i];
        }
        return;
    }

    for (int i = depth; i < n; i++) {
        if(!visited.count(arr[i])) {
            visited.insert(arr[i]);
            p[depth] = arr[i];
            dfs(arr, p, visited, n, r, depth + 1, (ll)(sum + arr[i]));
        }
    }
}
 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> solutions[i];
    }
    int output[3] = {};
    unordered_set<int> visited;

    dfs(solutions, output, visited, N, 3, 0, 0);

    sort(answer, answer + 3);

    for(int i = 0; i < 3; i++) {
        cout << answer[i] << ' ';
    }
    return 0;
}