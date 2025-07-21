#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> H(N);
    for (int i = 0; i < N; ++i) {
        cin >> H[i];
    }

    long long T = 0;
    long long pos = 0; // T % 3 before each attack (0, 1, or 2)
    for (int i = 0; i < N; ++i) {
        long long h = H[i];
        if (h == 0) continue;

        // Calculate full cycles (3 attacks per cycle, total damage 5 per cycle)
        long long full_cycles = h / 5;
        T += full_cycles * 3;
        h -= full_cycles * 5;

        // Handle remaining health after full cycles
        while (h > 0) {
            T++;
            if (pos == 0) {
                h -= 3;
            } else {
                h -= 1;
            }
            pos = (pos + 1) % 3;
        }
    }

    cout << T << endl;
    return 0;
}