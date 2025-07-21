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
        long long remaining = H[i];
        // The attack pattern is 1, 1, 3, 1, 1, 3, etc.
        // To find how many full cycles (3 attacks) are needed.
        long long full_cycles = remaining / 5;
        remaining -= full_cycles * 5;
        T += full_cycles * 3;
        
        // Now handle the remaining health after full cycles.
        while (remaining > 0) {
            T += 1;
            if (T % 3 == 0) {
                remaining -= 3;
            } else {
                remaining -= 1;
            }
        }
    }
    cout << T << endl;
    return 0;
}