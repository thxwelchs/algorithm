#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 백준 8911 거북이
// https://www.acmicpc.net/problem/8911

int dx[4]={0, -1, 0, 1}; // 위, 왼, 아, 오
int dy[4]={1, 0, -1, 0};


int solve(string s) {
    int x, y;
    int min_x, min_y, max_x, max_y;
    x=y=min_x=min_y=max_x=max_y=0;
    
    int direction = 0;
 
    int n = s.size();
    for(int i=0; i<n; i++){
        if(s[i]=='F'){
            x+=dx[direction];
            y+=dy[direction];
        }
        else if(s[i]=='B'){
            x-=dx[direction];
            y-=dy[direction];
        }
        else if(s[i]=='L'){
            direction = (direction+1)%4;
        }
        else{
            direction = (direction+3)%4;
        }
        min_x = min(x, min_x);
        min_y = min(y, min_y);
        max_x = max(x, max_x);
        max_y = max(y, max_y);
    }

    return (max_x-min_x)*(max_y-min_y);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    /* 
        1
        FFRFRFFRFRRFFF
     */
    cout << solve("FFRFRFFRFRRFFF");

    // int T;
    // cin >> T;
    // while(T--) {
    //     string s;
    //     cin >> s;
    //     cout << solve(s) << '\n';
    // }
    
    return 0;
}