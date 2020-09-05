#include <iostream>
#include <map>

using namespace std;

// 백준 4358 생태학
// https://www.acmicpc.net/problem/4358

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(0); cin.tie(0);
    map<string, int> map;
    string tree;
    int count = 0;

//  로컬테스트시 입력 무한루프에서 빠져나오질 않는데 왜 그러는지 모르겠음..
    while(getline(cin, tree)) {
        map[tree]++;
        count++;
    }

    cout.setf(ios::fixed);
    cout.precision(4);
    for (auto const& entry: map){
        double p = (double) entry.second / (double) count * 100;
        cout << entry.first << " " << p << endl;
    }

    return 0;
}

