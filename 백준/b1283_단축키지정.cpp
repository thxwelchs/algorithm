#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

// 백준 1283 단축키지정
// https://www.acmicpc.net/problem/1283

int N;
bool sc[26];
string opts[30];
int a[30];



char make_shortcut(char s) {
    if(s == ' ') return s;
    int n = 0;
    if(s >= 'a' && s <= 'z') n = s - 'a';
    else if(s >= 'A' && s <= 'Z') n = s - 'A';
    if(!sc[n]) {
        sc[n] = true;
        return sc[n];
    }

    return ' ';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
	cin.ignore(); // getline 으로 입력받을 때 개행 버퍼 비우기
	for (int i = 0; i < N; i++)
	{
		getline(cin, opts[i]);
	}

    memset(a, -1, sizeof(a));

	for(int i =0;i<N;i++) {
        string o = opts[i];

        // 단어의 첫 글자에서 shortcut을 탐색
        bool isMaked = false;
        for(int j = 0; j < o.size(); j++) {
            if(j == 0 || (j > 0 && o[j - 1] == ' ')) {
                char s = make_shortcut((char)o[j]);
                if(s != ' ') {
                    a[i] = j;
                    isMaked = true;
                    break;
                }
            }
        }

        if(isMaked) continue;
        for(int j = 1; j < o.size(); j++) {
            char s = make_shortcut((char)o[j]);
            if(s != ' ') {
                a[i] = j;
                break;
            }
        }
        // 모든 글자에서 shorcut을 탐색 (0번 인덱스부터 끝까지 (공백이 아닌) 모든 글자에 대해서 고려)
    }

    for(int i = 0;i<N;i++) {
        for(int j = 0; j < opts[i].size(); j++) {
            if(j == a[i]) cout << '[';
            cout << opts[i][j];
            if(j == a[i]) cout << ']';
        }
        cout << '\n';
    }

    return 0;
}

/*
3
As
sa
sA
*/