#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 미해결

// 백준 2729 이진수 덧셈
// https://www.acmicpc.net/problem/2729

int T;


// 00000000...0000000000000000000000000101
// 00000000...0000000000000000000000000101
// 00000000...0000000000000000000000000101

void bin_add(string a, string b) {
    int c[81];
	// 0으로 채우는 이유에 대해서 고민해보기
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());

    int as = a.size(), bs = b.size();

    int size = max(as, bs);

	for (int i = 0; i < size; i++) 
		c[i] = (i > as - 1 ? 0 : (a[i] - '0')) + (i > bs - 1 ? 0 : (b[i] - '0'));

    if(c[size - 1] >= 2) c[size] = 0;
	for (int i = 0; i < size; i++){
        if(c[i] >= 2){
			c[i] -= 2;
			c[i + 1]++;
		}
	}
	int flag = 0;
	for (int i = 80; i >= 0; i--){ // 이 for문에서도 수정할 사항이 생김
		if(c[i] != -1)
			flag = 1;
		if(flag)
			cout << c[i];
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> T;
    for(int i = 0; i < T; i++) {
        string a, b;
        cin >> a >> b;
        bin_add(a, b);
        cout << '\n';
    }
    
    return 0;
}

// 3
// 1001101 10010
// 1001001 11001
// 1000111 1010110

// 1
// 1000111 1010110