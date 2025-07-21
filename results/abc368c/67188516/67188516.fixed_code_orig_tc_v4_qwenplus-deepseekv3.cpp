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
    long long pos = 0; // T mod 3

    for (int i = 0; i < N; ++i) {
        long long h = H[i];
        if (h <= 0) continue;

        // Calculate the number of full cycles (3 steps: 1,1,3) and the remaining steps
        long long full_cycles = h / 5;
        long long remaining = h % 5;

        T += full_cycles * 3;
        pos = (pos + full_cycles * 3) % 3;

        // Handle the remaining health after full cycles
        while (remaining > 0) {
            T++;
            long long damage = (T % 3 == 0) ? 3 : 1;
            remaining -= damage;
            pos = T % 3;
        }
    }

    cout << T << endl;
    return 0;
}