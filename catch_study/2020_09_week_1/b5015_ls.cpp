#include <iostream>
#include <string>
#include <vector>

using namespace std;

string p;
int n;
vector<string> v;

int dp[111][111];

bool match(int i, int j, string &s){ //p idx, s idx, s
	int &ret = dp[i][j];
	if(ret != -1) return ret;
	if(i >= p.size()) return ret = (j == s.size());
	if(p[i] == s[j]) return ret = match(i+1, j+1, s);
	if(p[i] == '*'){
		return ret = (match(i+1, j, s) || match(i, j+1, s));
	}
	return ret = 0;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> p >> n; v.resize(n);
	for(int i=0; i<n; i++) cin >> v[i];

	for(int i=0; i<n; i++){
		memset(dp, -1, sizeof dp);
		if(match(0, 0, v[i])) cout << v[i] << "\n";
	}
}