#include <bits/stdc++.h>

using namespace std;
int T;
int n, m;
int A[1001], B[1001];
int pSumA[1001], pSumB[1001];
vector<int> v, v2;
unordered_map<int, int> um;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> A[i];
		pSumA[i] = pSumA[i- 1] + A[i];
	}
	cin >> m;
	for(int i = 1; i <= m; i++) {
		cin >> B[i];
		pSumB[i] = pSumB[i - 1] + B[i];
	}

	for(int i = 1; i <= n; i++) {
		for(int j = i; j <= n; j++) {
			v.push_back(pSumA[j] - pSumA[i - 1]);
		}
	}

	for(int i = 1; i <= m; i++) {
		// um[B[i]]++;
		for(int j = i; j <= m; j++) {
			// v2.push_back(pSumB[j] - pSumB[i - 1]);
			um[pSumB[j] - pSumB[i - 1]]++;
		}
	}

	// sort(v.begin(), v.end());
	// sort(v2.begin(), v2.end(), greater<int>());

	long long ans = 0;

	for(int _a : v) {
		if(um.count(T - _a)) {
			ans += um[T - _a];
		}
	}

	// int i = 0, j = 0;
	// while(i < v.size() && j < v2.size()) {
	// 	long long cntA = 0, cntB = 0;
	// 	int i2 = i, j2 = j; 
	// 	while(i2 < v.size() && v[i2++] == v[i]) {
	// 		cntA++;
	// 	}
	// 	while(j2 < v2.size() && v2[j2++] == v2[j]) {
	// 		cntB++;
	// 	}

	// 	if(v[i] + v2[j] == T) {
	// 		// ans++;
	// 		ans += cntA * cntB;
	// 		i = i2;
	// 	} else if(v[i] + v2[j] > T) {
	// 		j = j2;
	// 	} else {
	// 		i = i2;
	// 	}
	// }

	cout << ans;
	
	return 0;
}