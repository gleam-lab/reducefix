#include <iostream>
#include <vector>
#include <algorithm>

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
        long long cycles = h / 5;
        long long remaining = h % 5;

        T += cycles * 3;
        h = remaining;

        if (h > 0) {
            if (T % 3 == 0) {
                // Next attack is at T+1, which is (T+1) % 3 == 1, deals 1 damage
                if (h <= 1) {
                    T += 1;
                } else if (h <= 3) {
                    T += 2;
                } else {
                    T += 3;
                }
            } else if (T % 3 == 1) {
                // Next attack is at T+1, which is (T+1) % 3 == 2, deals 1 damage
                if (h <= 1) {
                    T += 1;
                } else if (h <= 2) {
                    T += 2;
                } else {
                    T += 3;
                }
            } else { // T % 3 == 2
                // Next attack is at T+1, which is (T+1) % 3 == 0, deals 3 damage
                if (h <= 3) {
                    T += 1;
                } else {
                    T += 2;
                }
            }
        }
    }

    cout << T << endl;
    return 0;
}