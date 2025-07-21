#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> H(N);
    for (int i = 0; i < N; i++) {
        cin >> H[i];
    }
    long long T = 0;
    for (int i = 0; i < N; i++) {
        // Calculate the number of full 3-attack cycles (each cycle deals 5 damage)
        long long full_cycles = H[i] / 5;
        H[i] -= full_cycles * 5;
        T += full_cycles * 3;
        
        // Handle remaining health
        while (H[i] > 0) {
            T++;
            if (T % 3 == 0) {
                H[i] -= 3;
            } else {
                H[i] -= 1;
            }
        }
    }
    cout << T << endl;
    return 0;
}