#include<bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> H(N);
    for (int i = 0; i < N; i++) cin >> H[i];
    long long T = 0;

    for (int i = 0; i < N; i++) {
        long long cycles = H[i] / 5;
        long long remaining = H[i] % 5;

        // Each cycle consists of 3 time units causing 5 damage.
        T += cycles * 3;
        remaining += cycles * 0; // No additional remaining from cycles.

        while (remaining > 0) {
            T++;
            if (T % 3 == 0) {
                remaining -= 3;
            } else {
                remaining -= 1;
            }
        }
    }
    cout << T << endl;
    return 0;
}