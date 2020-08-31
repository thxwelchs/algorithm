#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

// 프로그래머스 64064 불량사용자
// https://programmers.co.kr/learn/courses/30/lessons/64064

unordered_set<int> set;
// 순열 중 순서가 뒤바뀐 것이 중복제거가 안되므로 중복제거를 한 뒤에 갯수를 세어주어야 한다. set은 중복허용이 안되므로 set의 size가 즉 답이 되는 것
// 중복이 되는 경우의 예: {frodo, crodo, abc123}, {crodo, frodo, abc123}
// 2중 string set으로 중복제거를 할 수도 있지만, 각 user_id의 index를 기준으로 BIT OR 연산한 결과 또한 중복이라는 것을 보장 할 수 있기에 이렇게 해결하기로 함
// frodo = user_id[0], crodo = user_id[1], abc123 = user_id[3] 라고 봤을 때 user_id의 최대 길이는 8이므로, 총 8비트(int 255) 의 기준으로 각 비트가 1인 값이 user_id의 index라고 했을 때
//  0000 1011 가 되어 11이 된다. 즉 013 순서이든 103 순서이든 bit 연산을 하면 11이 되므로 set으로 저장시 중복제거가 된다.


void permutation(vector<string> arr, vector<string> p, vector<string> target, bool visited[], int n, int r, int depth, int bit) {
    // banned_id 총 길이만큼의 모든 순열을 구한 뒤, 제재 아이디에 매치가 되는지 검사 한다. 
    if(depth == r) {
        bool check = true;
        for(int i = 0; i < r; i++) {
            // 길이 자체가 다르다면 제재 아이디에 매치 될 수 없다.
            if(p[i].size() != target[i].size()) {
                return;
            }

            // 순열로 구한 모든 문자열이 제재 아이디에 매치 되는지 확인
            for (int j = 0; j < p[i].size(); j++){
                check = check && (p[i][j] == target[i][j] || target[i][j] == '*');
                if(!check) return;
            }
        }

        // 중복 제거를 위한 bit flag로 계산한 유일한 int값을 set에 삽입
        set.emplace(bit);
        return;
    }

    for (int i = 0; i < n; i++) {
        if(!visited[i]) {
            visited[i] = true;
            p[depth] = arr[i];
            // user_id의 index 만큼 시프트 연산으로 밀어넣어 bit 변수의 bit flag를 유효한 값으로 설정한다.
            permutation(arr, p, target, visited, n, r, depth + 1, (bit | 1 << i));
            visited[i] = false;
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    vector<string> output(8);
    bool visited[8] = {};
    permutation(user_id, output, banned_id, visited, user_id.size(), banned_id.size(), 0, 0);
    
    return set.size();
}