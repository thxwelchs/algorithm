#include <bits/stdc++.h>

using namespace std;

// unordered_map<int, vector<int>> um;
vector<vector<int>> v(13);
int ans;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for(int i = 0; i < 12; i++) {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    for(int i = 1; i <= 12; i++) {
        vector<int> _v = v[i];
        if(_v.size() == 3) {
            int sum = 0;
            for(int n : _v) {
                sum += v[n].size();
            }

            if(sum == 6) {
                cout << i;
                break;
            }
        }
    }
    
    return 0;
}