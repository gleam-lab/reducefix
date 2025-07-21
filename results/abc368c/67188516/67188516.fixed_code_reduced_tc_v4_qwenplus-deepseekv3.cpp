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
        long long cycles = H[i] / 5;
        T += cycles * 3;
        long long remaining = H[i] % 5;

        if (remaining == 0) continue;

        if (T % 3 == 0) {
            if (remaining <= 3) {
                T += 1;
            } else {
                T += 2;
            }
        } else if (T % 3 == 1) {
            if (remaining <= 1) {
                T += 1;
            } else if (remaining <= 4) {
                T += 2;
            }
        } else { // T % 3 == 2
            if (remaining <= 2) {
                T += 1;
            } else {
                T += 2;
            }
        }
    }
    cout << T << endl;
    return 0;
}