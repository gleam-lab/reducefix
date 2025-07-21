#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> H(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> H[i];
    }
    long long T = 0;
    for (int i = 1; i <= N; ++i) {
        long long cycles = H[i] / 5;
        long long remaining = H[i] % 5;
        T += cycles * 3;
        H[i] = remaining;
        if (H[i] > 0) {
            if (T % 3 == 2) {
                // Next attack is T+1, which is a multiple of 3 (since T+1 mod 3 == 0)
                if (H[i] <= 3) {
                    T += 1;
                } else {
                    T += 3;
                }
            } else if (T % 3 == 0) {
                // Next attack is T+1, which is not a multiple of 3 (first attack in cycle)
                if (H[i] <= 1) {
                    T += 1;
                } else if (H[i] <= 2) {
                    T += 2;
                } else {
                    T += 3;
                }
            } else if (T % 3 == 1) {
                // Next attack is T+1, which is second attack in cycle (1 damage)
                if (H[i] <= 1) {
                    T += 1;
                } else if (H[i] <= 2) {
                    T += 2;
                } else if (H[i] <= 4) {
                    T += 3;
                } else {
                    T += 3;
                }
            }
        }
    }
    cout << T << endl;
    return 0;
}