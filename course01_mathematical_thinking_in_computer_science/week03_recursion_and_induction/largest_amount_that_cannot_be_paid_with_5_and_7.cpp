#include <bits/stdc++.h>
using namespace std;
const int N = 1e6;
bool can[N + 1];

int main() {
    can[5] = can[7] = true;
    for (int i = 0; i <= N; i++) {
        if (can[i]) {
            if (i + 5 <= N) can[i + 5] = true;
            if (i + 7 <= N) can[i + 7] = true;
        }
    }
    int pos = -1;
    for (int i = 0; i + 3 < N; i++) {
        bool ok = true;
        for (int j = 0; j < 5; j++) {
            if (can[i + j]) continue;
            ok = false;
            break;
        }
        if (ok) break;
        pos = i;
    }
    cout << pos << endl;
    return 0;
}