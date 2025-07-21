#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MOD = 3; // Since we are using modulo 3 for T

int main() {
    int N;
    cin >> N;
    vector<int> H(N);
    for (int i = 0; i < N; ++i) {
        cin >> H[i];
    }
    
    long long T = 0;
    for (int i = 0; i < N; ++i) {
        while (H[i] > 0) {
            if (T % MOD == 0) {
                H[i] -= 3;
            } else if (T % MOD == 1) {
                H[i] -= 1;
            } else { // T % MOD == 2
                if (H[i] % 2 == 1) {
                    H[i] -= 1;
                } else {
                    H[i] -= 2;
                }
            }
            // Check if health is less than or equal to zero
            if (H[i] <= 0) break;
            T++;
        }
    }
    cout << T << endl;
    return 0;
}