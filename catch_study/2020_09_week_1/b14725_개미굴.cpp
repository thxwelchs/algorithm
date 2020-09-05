#include <iostream>
#include <string>
#include <queue>
#include <map>
#include <vector>

using namespace std;

// 백준 14725 개미굴
// https://www.acmicpc.net/problem/14725


/**
 * 전형적인 DFS 문제인것으로 보여 비교적 문제 자체를 파악하긴 쉬웠으나, 그래프를 만드는데 조금 공수가 들어갔다. 
 * Cave 구조체에 children으로 priority_queue<Cave> 를 넣고 먹이 문자열을 기준으로 정렬을 시키면서 넣을려고 했다.
 * 덕분에 연산자 오버로딩 공부를 하고.. 이것저것 삽질하다가 java와는 다르게 기본 map이 key를 기준으로 오름차순 정렬이 된다고 하여
 * 우선순위큐를 빼고 map을 쓰기로 함 그런데 그래프를 만들 때 자식의 map 포인터를 활용해야 될 것 같은데 잘 되지 않아서
 * 이것저것 삽질하다가 겨우 해결함
 * 덕분에 포인터 공부 다시 했음 
 * 구현하고 보니 map<string, map> 으로 했어도 될 걸 그랬다.
 */

int N; // 먹이 갯수
const char step = '-'; // 깊이 표현 문자

struct Cave {
    map<string, Cave> children;
};

void DFS(map<string, Cave> parent, int depth) {
    for(pair<string, Cave> child: parent) {
        for(int i = 0; i < depth * 2; i++) {
            cout << step;
        }
        cout << child.first << endl;

        // 자식이 있을 때만 한층 밑으로 들어간다.
        if(!child.second.children.empty()) {
            DFS(child.second.children, depth+1);
        }
    }
}

int main() {
    cin >> N;
    // Root map(개미굴 입구)에서부터 출발 
    map<string, Cave> root = {};

    // 깊이에 따라 바뀔 map 포인터
    map<string, Cave> *mp = &root;

    // 탐색한 먹이 루트 만큼 진행
    while(N--) {
        int K; // 발견된 먹이(개미굴 깊이)
        cin >> K;
        for(int i = 0; i < K; i++) {
            string food;
            cin >> food;
            Cave cave = {{}}; 
            
            // 자식이 없다면 추가한다.
            if(!(*mp).count(food)) {
                (*mp)[food] = cave;
            }

            // 맵포인터 교체
            mp = &(*mp)[food].children;
        }
        // 다시 루트부터 넣어야 하므로 맵포인터 교체
        mp = &root;
    }

    // DFS로 출력
    DFS(root, 0);

    return 0;
}