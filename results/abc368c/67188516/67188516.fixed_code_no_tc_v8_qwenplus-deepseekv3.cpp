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
    for (int i = 0; i < N; ++i) {
        long long h = H[i];
        long long full_cycles = h / 5;
        long long remaining = h % 5;

        long long attacks = 0;
        attacks += full_cycles * 3;

        // The attacks so far contribute T += full_cycles * 3
        // The remaining health is 'remaining'
        long long current_T = T + attacks;
        while (remaining > 0) {
            current_T++;
            if (current_T % 3 == 0) {
                remaining -= 3;
            } else {
                remaining -= 1;
            }
            attacks++;
        }
        T += attacks;
    }

    cout << T << endl;
    return 0;
}