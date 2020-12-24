#include <iostream>
#include <string>
#include <stack>

using namespace std;

// 백준 2504 괄호의 값
// https://www.acmicpc.net/problem/2504

int solve(string s) {
    stack<int> stack;
    int answer = 0;
    int n = 1;

    for(int i = 0; i < s.size(); i++) {
        char c = s[i];
        if(c == '(') {
            stack.push(c);
            n *= 2;
        } else if(c == '[') {
            stack.push(c);
            n *= 3;
        } else if(c == ')') {
            if(stack.empty()) return 0;

            if(stack.top() == '(') {
                if(s[i - 1] == '(') {
                    answer += n;
                }
                stack.pop();
                n /= 2;
            } else return 0;
        } else if(c == ']') {
            if(stack.empty()) return 0;
            if(stack.top() == '[') {
                if(s[i - 1] == '[') {
                    answer += n;
                }
                stack.pop();
                n /= 3;
            } else return 0;
        }
    }

    return stack.empty() ? answer : 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string s;

    cin >> s;

    cout << solve(s);
    
    return 0;
}