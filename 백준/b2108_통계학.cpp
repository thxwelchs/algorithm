#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 백준 2108 통계학
// https://www.acmicpc.net/problem/2108

int a[500000];
int c[8100];
vector<int> cv;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int N;

    cin >> N;
    int mi = 8002, ma = 0, cma = 0;
    int sum = 0;
    for(int i =0;i<N;i++) {
        cin >> a[i];
        a[i] += 4001;

        sum += a[i];
        mi = min(mi, a[i]);
        ma = max(ma, a[i]);
        c[a[i]]++;
        if(c[a[i]] > cma) {
            cv.clear();
            cma = c[a[i]];
            cv.push_back(a[i]);
        } else if(c[a[i]] == cma) {
            cv.push_back(a[i]);
        }
        // cma = max(cma, c[a[i]]);
    }

    sort(cv.begin(), cv.end());
    sort(a, a+N);

    if(cv.size() >= 2) {
        cma = cv[1];
    } else {
        cma = cv[0];
    }

	cout << fixed;
	cout.precision(0);
	cout << ((double)sum / N - 4001) << '\n';
    cout << a[N / 2] - 4001 << '\n';
    cout << cma - 4001 << '\n';
    cout << ma - mi << '\n';
    
    return 0;
}

/*
3
2000 
2001
2002
*/