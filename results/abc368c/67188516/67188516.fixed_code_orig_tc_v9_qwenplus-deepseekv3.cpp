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
        long long H_i = H[i];
        // Calculate how many full cycles of 3 attacks (1,1,3) are needed
        long long full_cycles = H_i / 5;
        T += full_cycles * 3;
        H_i %= 5;

        // Now handle the remaining H_i with attacks depending on pos
        while (H_i > 0) {
            T += 1;
            if (T % 3 == 0) {
                H_i -= 3;
            } else {
                H_i -= 1;
            }
        }
    }

    cout << T << endl;
    return 0;
}