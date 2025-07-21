#include <iostream>
#include <vector>
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

    for (long long h : H) {
        // Each full 3-step cycle gives 5 damage: (3 + 1 + 1)
        long long full_cycles = h / 5;
        long long rem = h % 5;
        T += full_cycles * 3;

        if (rem > 0) {
            // After full cycles, apply remaining attacks
            if (T % 3 == 0) {
                // T is multiple of 3 -> attack with 3
                if (rem >= 3) {
                    T += 1;
                    rem -= 3;
                } else {
                    T += 1;
                    rem = 0;
                }
            } else if (T % 3 == 1) {
                // T+1 will be multiple of 3
                if (rem >= 4) {
                    T += 2; // two attacks: 1 (T), 3 (T+1)
                    rem -= 4;
                } else if (rem >= 1) {
                    T += 1; // attack with 1
                    rem -= 1;
                }
            } else if (T % 3 == 2) {
                // T+1 is not multiple of 3, T+2 is
                if (rem >= 5) {
                    T += 3; // three attacks: 1 (T), 1 (T+1), 3 (T+2)
                    rem -= 5;
                } else if (rem >= 2) {
                    T += 2; // two attacks: 1 (T), 1 (T+1)
                    rem -= 2;
                } else if (rem >= 1) {
                    T += 1; // one attack: 1
                    rem -= 1;
                }
            }

            while (rem > 0) {
                T++;
                if (T % 3 == 0) rem -= 3;
                else rem -= 1;
            }
        }
    }

    cout << T << "\n";
    return 0;
}