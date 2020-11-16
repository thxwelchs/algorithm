#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int MAX = 101;

vector<int> a[MAX]; // 각 정점과 연결된 간선 정보
int d[MAX]; // 특정한 정점을 점유하고 있는 정보
bool c[MAX]; // 정점 매칭 처리 여부

int n = 3, m;

// 매칭에 성공한 경우 True, 실패한 경우 False
bool dfs(int x) {
    //연결된 모든 노드에 대해서 들어 갈 수 있는 시도
    for(int i = 0; i < a[x].size(); i++) {
        int t = a[x][i];

        // 이미 처리한 노드는 제외
        if(c[t]) continue;
        c[t] = true;
        // 비어 있거나 점유 노드에 더 들어갈 공간이 있는 경우를 재귀적으로 확인
        if(d[t] == 0 || dfs(d[t])) {
            // 매칭이 이루어짐
            d[t] = x;
            return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    a[1].push_back(1);
    a[1].push_back(2);
    a[1].push_back(3);
    a[2].push_back(2);
    a[3].push_back(3);
    
    return 0;
}