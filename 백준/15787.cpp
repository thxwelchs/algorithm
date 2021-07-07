#include <bits/stdc++.h>

using namespace std;

const int MA = 100000;
int N, M;

int arr[MA + 1];
int chk[(1 << 21)];
int ans;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int o, i1;
		cin >> o >> i1;
		
		if (o <= 2) {
			int x;
			cin >> x;

			if (o == 1) {
				arr[i1] |= (1 << x);
			}
			else {
				arr[i1] &= ~(1 << x);
			}
		}
		else if (o == 3) {
			arr[i1] = (arr[i1] << 1);
			arr[i1] &= ((1 << 21) - 1);
		}
		else {
			arr[i1] = (arr[i1] >> 1);
			arr[i1] &= ~1;
		}
	}

	
	for (int i = 1; i <= N; i++) {
		if (chk[arr[i]]) 
			continue;

		chk[arr[i]] = 1;
		ans++;
	}

	cout << ans;
	
	return 0;
}