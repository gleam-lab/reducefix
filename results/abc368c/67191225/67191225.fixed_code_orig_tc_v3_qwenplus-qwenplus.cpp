#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<long long> H(N);
    for (int i = 0; i < N; ++i) {
        cin >> H[i];
    }

    long long T = 0;

    for (int i = 0; i < N; ++i) {
        // Calculate how many full attack cycles are needed
        long long h = H[i];
        
        // Each 3 attacks, we deal 3+1+1 = 5 damage
        long long full_cycles = h / 5;
        T += full_cycles * 3;

        // Remaining damage to apply
        long long rem = h % 5;

        if (rem > 0) {
            ++T;
            if (T % 3 == 0) {
                // Triple attack
                if (rem >= 3) {
                    rem -= 3;
                } else {
                    rem -= 1;
                    if (rem > 0) ++T;
                }
            } else {
                // Single attack
                --rem;
                if (rem > 0) {
                    ++T;
                    if (T % 3 == 0) {
                        if (rem >= 3) {
                            rem -= 3;
                        } else {
                            rem -= 1;
                            if (rem > 0) ++T;
                        }
                    } else {
                        --rem;
                        if (rem > 0) ++T;
                    }
                }
            }
        }
    }

    cout << T << '\n';
    return 0;
}