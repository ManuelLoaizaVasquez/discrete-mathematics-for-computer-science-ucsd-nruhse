#include <bits/stdc++.h>
using namespace std;

typedef long long Long;
const Long N = 20;


bool used[N];
Long cnt = 0;
Long n;// tablero de n x n
vector<Long> pos;

bool check(int row, int col) {
    if (used[col]) return false;
    for (int i = 0; i < row; i++) {
        Long dx = abs(i - row);
        Long dy = abs(pos[i] - col);
        if (dx == dy) return false;
    }
    return true;
}

void n_queens(int row) {
    if (row == n) {
        cnt++;
    } else {
        for (int col = 0; col < n; col++) {
            if (check(row, col)) {
                pos[row] = col;
                used[col] = true;
                n_queens(row + 1);
                pos[row] = -1;
                used[col] = false;
            }
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) pos.push_back(-1);
    n_queens(0);
    cout << cnt << endl;
    return 0;
}