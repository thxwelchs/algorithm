#include<bits/stdc++.h>

using namespace std;    

// 백준 2309 일곱 난쟁이
// https://www.acmicpc.net/problem/2309

vector<int> v; 

int temp;
int main(){
	for(int i = 0; i < 9; i++) {
		cin >> temp; 
		v.push_back(temp);
	}
	sort(v.begin(), v.end());
	do{
        int sum = 0;
		for(int i = 0; i < 7; i++) sum += v[i];
        if(sum == 100) {
            for(int i = 0; i < 7; i++) cout << v[i] << '\n';

            break;
        }
	}while(next_permutation(v.begin(), v.end())); 
    return 0; 
} 