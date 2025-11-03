#include<bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> H(N);
    for (int i = 0; i < N; i++) {
        cin >> H[i];
    }

    long long T = 0;
    int idx = 0;

    while (idx < N) {
        T++;
        // If current enemy is already defeated, move to next
        if (H[idx] <= 0) {
            idx++;
            continue;
        }

        // Attack the frontmost alive enemy
        if (T % 3 == 0) {
            H[idx] -= 3;
        } else {
            H[idx] -= 1;
        }

        // If this enemy is defeated, move to next
        if (H[idx] <= 0) {
            idx++;
        }
    }

    cout << T << endl;
    return 0;
}