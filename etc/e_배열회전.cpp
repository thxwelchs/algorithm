#include <iostream>
#include <string>
#include <vector>

using namespace std;

int arr[3][3] = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
};

int temp[3][3];

int rotate_arr(int degree) {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(degree == 90) {
                // 회전 후 행 인덱스는 기존 열 인덱스
                // 회전 후 열 인덱스는 마지막 인덱스 - 기존 행
                cout << arr[j][2 - i];
            }
        }
        cout << '\n';
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cout << arr[i][j];
        }
        cout << '\n';
    }

    cout << "90도 회전 후\n";

    rotate_arr(90);
    // rotate_arr(90);
    
    return 0;
}