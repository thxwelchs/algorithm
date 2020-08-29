// https://www.welcomekakao.com/learn/courses/30/lessons/42891
// 프로그래머스 42891 무지의 먹방라이브 

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

struct Food {
	int time;
	int index;
};

bool timeComparator(Food a, Food b) {
	return a.time < b.time;
}

bool indexComparator(Food a, Food b) {
	return a.index < b.index;
}

int solution(vector<int> food_times, long long k) {
	int n = food_times.size();
	vector<Food> foods(n);

	// 음식을 먹는데 걸리는 시간, 음식의 번호를 각 원소마다 매겨준다.
	for(int i = 0; i < n; i++) {
		foods[i] = {food_times[i], i + 1};
	}

	// 음식시간 기준으로 오름차순하여 정렬 해놓는다.
	// k까지 도달할 때까지 여러 음식시간들을 한번에 처리하기 위함이다. (정렬 해놓아야 같은 시간이 걸리는 음식들은 한번에 처리가 가능하다.)
	sort(foods.begin(), foods.end(), timeComparator);

	int prev = 0;
	vector<Food>::iterator it;
	for(it = foods.begin(); it != foods.end(); ++it, --n) {
		// loop i마다 반드시 하나 이상의 음식을 모두 먹는다.

		int time = it -> time, index = it -> index;

		// 현재 존재하는 음식들 중 먹을 수 있는 음식의 최대 갯수
		// 현재 음식시간으로 정렬되어져 있는 음식 배열 기준에서 최대 한번에 처리 할 수 있는 음식 갯수를 뜻한다.
		ll eats = (ll) (time - prev) * n;

		// 먹을 수 있는 음식 갯수가 존재하지 않으면, 그냥 넘어간다.
		if(eats== 0) continue;

		// 만약 먹을 수 있는 음식 갯수가 k에 도달하지 않는 갯수라면 한번에 모두 처리한다.
		if(eats <= k) {
			// 처리 후에 k를 먹은 음식 갯수만큼 차감해주고 나머지 k만큼만 또 진행한다.
			k -= eats;
			prev = time;
		} else {
			// 먹을 수 있는 음식이 k만큼 도달 할 수 있는 경우, 즉 네트워크 지연이 발생한 음식이 있는 구간
			k %= n;

			// k 번째 위치만큼 이동한 다음 음식번호를 지정하기 위해 다시 인덱스 기준으로 오름차순 정렬한다.
			sort(it, foods.end(), indexComparator);

			// 현재 위치에서 k번째 위치만큼 이동한 음식을 먹으면 된다. 
			// [3, 1, 3, 4] 음식이 있을 때 k가 3이라면 4번째 음식부터 바로 먹으면 되는 것이다.
			return (it + k) -> index;
		}
	}

	return -1;
}

int main() {
	// int answer = solution({3, 1, 2}, 5);
	int answer = solution({7, 3, 1, 2, 4, 3, 1, 2}, 9);
	cout << answer << endl;
	
	return 0;
}