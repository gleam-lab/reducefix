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
    int pos = 0; // position in the attack cycle: 0, 1, 2

    for (int i = 0; i < N; ++i) {
        long long h = H[i];
        if (h == 0) continue;

        // Calculate full cycles of 3 attacks (5 damage)
        long long full_cycles = h / 5;
        T += full_cycles * 3;
        h -= full_cycles * 5;

        // Handle remaining damage
        while (h > 0) {
            T++;
            if (T % 3 == 0) {
                h -= 3;
            } else {
                h -= 1;
            }
        }
    }

    cout << T << endl;
    return 0;
}