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
    long long pos = 0; // T % 3

    for (int i = 0; i < N; ++i) {
        long long h = H[i];
        if (h == 0) continue;

        // Calculate full cycles (each cycle is 3 attacks: 1,1,3)
        long long full_cycles = h / 5;
        T += full_cycles * 3;
        h %= 5;

        if (h == 0) {
            pos = (pos + full_cycles * 3) % 3;
            continue;
        }

        // Now handle the remaining h (0 < h < 5)
        while (h > 0) {
            T++;
            long long damage = (T % 3 == 0) ? 3 : 1;
            h -= damage;
        }
        pos = T % 3;
    }

    cout << T << endl;

    return 0;
}