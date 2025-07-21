#include <iostream>
#define rep(i, n) for (int i = 0; i < (n); ++i)

using namespace std;

int main() {
    int N;
    cin >> N;
    long long healths[N];
    long long T = 0, total_attacks = 0;

    // Read enemy healths
    rep(i, N) {
        cin >> healths[i];
    }

    // Process each enemy
    for (int i = 0; i < N; ++i) {
        if (healths[i] > 0) {
            while (healths[i] > 0) {
                if (T % 3 == 0) {
                    healths[i] -= 3;
                } else {
                    healths[i] -= 1;
                }
                T++;
            }
            total_attacks += T - 1; // Adjust T to account for the last successful attack
        }
    }

    cout << total_attacks << endl;
    return 0;
}