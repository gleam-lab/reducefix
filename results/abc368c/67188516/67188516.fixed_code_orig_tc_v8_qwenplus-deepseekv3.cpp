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

        // Number of full triple attacks (each deals 5 damage)
        long long full = h / 5;
        T += full * 3;
        h -= full * 5;

        if (h == 0) continue;

        // Now handle the remaining health
        while (h > 0) {
            T++;
            if (T % 3 == 0) {
                h -= 3;
            } else {
                h -= 1;
            }
            if (h <= 0) break;
        }
    }

    cout << T << endl;
    return 0;
}