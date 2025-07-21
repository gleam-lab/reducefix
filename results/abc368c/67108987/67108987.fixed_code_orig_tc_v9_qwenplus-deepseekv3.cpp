#include<bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> H(N);
    for (int i = 0; i < N; i++) cin >> H[i];
    long long T = 0;
    for (int i = 0; i < N; i++) {
        long long full_cycles = H[i] / 5;
        long long remaining = H[i] % 5;
        T += full_cycles * 3;
        if (remaining > 0) {
            if (remaining <= 1) {
                T += 1;
            } else if (remaining <= 3) {
                T += 2;
            } else {
                T += 3;
            }
        }
    }
    cout << T << endl;
    return 0;
}