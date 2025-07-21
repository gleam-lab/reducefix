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
    int pos = 0; // T mod 3 (0, 1, 2)

    for (int i = 0; i < N; ++i) {
        long long cycles = H[i] / 5;
        T += cycles * 3;
        long long rem = H[i] % 5;

        if (rem == 0) continue;

        if (pos == 0) {
            if (rem <= 1) {
                T += 1;
                pos = 1;
            } else if (rem <= 2) {
                T += 2;
                pos = 2;
            } else if (rem <= 5) {
                T += 3;
                pos = 0;
            }
        } else if (pos == 1) {
            if (rem <= 1) {
                T += 1;
                pos = 2;
            } else if (rem <= 4) {
                T += 2;
                pos = 0;
            }
        } else if (pos == 2) {
            if (rem <= 3) {
                T += 1;
                pos = 0;
            } else if (rem <= 4) {
                T += 2;
                pos = 1;
            }
        }
    }

    cout << T << endl;
    return 0;
}