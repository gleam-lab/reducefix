#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<long long> H(N);
    for (int i = 0; i < N; ++i) {
        cin >> H[i];
    }

    long long T = 0;
    for (int i = 0; i < N; ++i) {
        long long full_cycles = H[i] / 5;
        long long remaining = H[i] % 5;

        T += full_cycles * 3;
        H[i] = remaining;

        if (H[i] > 0) {
            if (T % 3 == 2) { // Next attack is a 3-damage attack
                if (H[i] <= 3) {
                    T += 1;
                    H[i] = 0;
                } else {
                    T += 1;
                    H[i] -= 3;
                    if (H[i] > 0) {
                        T += H[i];
                        H[i] = 0;
                    }
                }
            } else {
                long long needed_attacks = (H[i] + 2) / 3; // ceil(H[i] / 3) if we can use a 3-damage attack optimally
                if (needed_attacks == 1) {
                    if (H[i] <= 1) {
                        T += 1;
                        H[i] = 0;
                    } else if (H[i] <= 2) {
                        if (T % 3 == 0) {
                            T += 2;
                            H[i] = 0;
                        } else if (T % 3 == 1) {
                            T += 1;
                            H[i] -= 1;
                            if (H[i] > 0) {
                                T += 1;
                                H[i] -= 1;
                            }
                        }
                    }
                } else {
                    T += H[i];
                    H[i] = 0;
                }
            }
        }
    }

    // Re-simulate the process to ensure correctness
    T = 0;
    for (int i = 0; i < N; ++i) {
        while (H[i] > 0) {
            T += 1;
            if (T % 3 == 0) {
                H[i] -= 3;
            } else {
                H[i] -= 1;
            }
        }
    }

    cout << T << endl;
    return 0;
}