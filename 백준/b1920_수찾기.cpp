#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> A;

// 백준 1920 수찾기
// https://www.acmicpc.net/problem/1920

// 이분탐색 기본문제

int bin_search(int target) {
    int left = 0;
    int right = N;
    while(left <= right) {
        int mid = (left + right) / 2;
        if(A[mid] == target) return 1;
        else if(A[mid] > target) right = mid - 1; 
        else left = mid + 1;
    }

    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for(int i = 0; i < N; i++) {
        int elm;
        cin >> elm;
        A.push_back(elm);
    }

    sort(A.begin(), A.end());

    cin >> M;
    while(M--) {
        int elm;
        cin >> elm;
        cout << bin_search(elm) << "\n";
    }
    
    return 0;
}