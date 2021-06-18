#include <bits/stdc++.h>

using namespace std;

int n;
int che[4000001];
int a[4000001];
int sum[4000001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 2; i <= n; i++) {
		if (che[i]) continue;
		for (int j = 2 * i; j <= n; j += i) {
			che[j] = 1;
		}
	}
	int p = 0;
	for (int i = 2; i <= n; i++) {
		if (!che[i]) a[p++] = i;
	}

	//   l              r
	// 2 3 5 7 11 13 17 19 23 29 31 37 41

	int l = 0, r = 0;
	int sum = a[0];
	int ans = 0;
	while (l < p && r < p) {
		if (sum < n) {
			r++;
			sum += a[r];
		}
		else {
			if (sum == n)
				ans++;

			sum -= a[l];
			l++;
		}
	}

	cout << ans;

	return 0;
}`