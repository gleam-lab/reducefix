#include<bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> H(N);
    for (int i = 0; i < N; ++i) cin >> H[i];
    long long T = 0;
    for (int i = 0; i < N; ++i) {
        long long full_cycles = H[i] / 5;
        long long remaining = H[i] % 5;
        T += full_cycles * 3;
        H[i] = remaining;
    }
    long long extra = 0;
    for (int i = 0; i < N; ++i) {
        if (H[i] <= 0) continue;
        long long t_extra = 0;
        if (H[i] == 1) {
            t_extra = 1;
        } else if (H[i] == 2) {
            t_extra = 2;
        } else if (H[i] == 3) {
            t_extra = 3;
        } else if (H[i] == 4) {
            t_extra = 4;
        }
        if (t_extra > 0) {
            long long start_T = T + extra;
            long long end_T = start_T + t_extra;
            for (long long t = start_T + 1; t <= end_T; ++t) {
                if (t % 3 == 0) {
                    H[i] -= 3;
                } else {
                    H[i] -= 1;
                }
                if (H[i] <= 0) break;
            }
            extra += t_extra;
        }
    }
    T += extra;
    cout << T << endl;
    return 0;
}