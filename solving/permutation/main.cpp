#include <iostream>
#include <string>

using namespace std;

// DFS로 순서대로 순열 구하기
// n개 에서 r개를 뽑아낸 경우의 수

/**
 * int arr[], 순열을 구할 배열
 * int p[], 순열을 구하기 위해 여러가지 경우의 수를 저장해놓을 배열
 * int visited[], DFS 할 때 방문체크 재귀호출 후 방문을 다시 비활성화 해주어야 다음 순서 재귀에서 재귀호출로 들어올 수 있다.
 */
void permutation(int arr[], int p[], bool visited[], int n, int r, int depth) {

    if(depth == r) {
        for(int i = 0; i < r; i++) {
            cout << p[i] ;
        }
        cout << endl;
        return;
    }

    for (int i = 0; i < n; i++) {
        if(!visited[i]) {
            visited[i] = true;
            p[depth] = arr[i];
            permutation(arr, p, visited, n, r, depth + 1);
            visited[i] = false;
        }
    }
}

int main() {

    int arr[3] = {1, 2, 3};
    int output[3] = {};
    bool visited[3] = {};
    permutation(arr, output, visited, 3, 3, 0);
    
    return 0;
}