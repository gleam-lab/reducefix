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

    for (int i = 0; i < N; ++i) {
        // Calculate how many full 3-attack cycles can be applied:
        // One triple attack at T mod 3 == 0, and two single attacks otherwise
        long long h = H[i];

        if (h <= 0) continue;

        // Determine how many full cycles of 3 attacks we can do
        long long cycles = h / 5;
        long long rem = h % 5;

        T += cycles * 3;

        if (rem > 0) {
            // After full cycles, apply remaining attacks
            if (T % 3 == 0) {
                // We're at a triple attack position
                T++;
                if (--rem == 0) continue;
                T++;
                if (--rem == 0) continue;
                T++;
            } else {
                // Not at triple attack position
                T++;
                if (--rem == 0) continue;
                if ((T % 3) == 0) {
                    T++;
                    if (--rem == 0) continue;
                    T++;
                } else {
                    T++;
                    if (--rem == 0) continue;
                    if ((T % 3) == 0) {
                        T++;
                    } else {
                        T++;
                    }
                }
            }
        }
    }

    cout << T << endl;
}