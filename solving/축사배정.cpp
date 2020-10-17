#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n, m;

const int MAX = 201;

vector<int> cow[MAX];
int d[MAX];
bool c[MAX];

// 매칭 성공 true, 매칭 실패 false
bool dfs(int x) {
    for(int i = 0; i < cow[x].size(); i++) {
        int t = cow[x][i]; //축사 번호

        // 이미 처리된 노드는 넘어간다.
        if(c[t]) continue;

        c[t] = true;
        // 축사가 비어있다면 현재 소를 축사에 넣는다 
        // 혹은 축사가 다른소에 의해 점유되어 있더라도, 그 소가 다른 축사로 갈 수 있는지 살펴본다.
        if(d[t] == 0 || dfs(d[t])) {
            d[t] = x;
            return true;
        }
    }

    return false;
}

int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        int s;
        cin >> s;
        for(int j = 1; j <= s; j++) {
            int sNum;
            cin >> sNum;
            cow[i].push_back(sNum);
        }
    }

    int count = 0;
    for(int i = 1; i <= n; i++) {
        // 방문처리 초기화
        fill(c, c + MAX, false);
        if(dfs(i)) count++;
    }

    cout << count << "\n";
    
    return 0;
}