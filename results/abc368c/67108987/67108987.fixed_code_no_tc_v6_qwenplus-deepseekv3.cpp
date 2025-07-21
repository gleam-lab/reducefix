#include<bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> H(N);
    for (int i = 0; i < N; i++) cin >> H[i];
    long long T = 0;
    for (int i = 0; i < N; i++) {
        if (H[i] <= 0) continue;
        // The attacks on this enemy happen at times T+1, T+2, etc.
        // The damage pattern is 1, 1, 3, 1, 1, 3, ...
        // We need to find the number of attacks needed to reduce H[i] to 0.
        // The total damage from 'k' attacks is floor((k + 2)/3)*3 + (k - floor((k + 2)/3))*1
        // Which simplifies to floor((k + 2)/3)*3 + (k % 3 == 0 ? 0 : (k % 3 == 1 ? 0 : 0))
        // Alternatively, total damage per 3 attacks is 5 (1+1+3).
        long long full_cycles = H[i] / 5;
        long long remaining = H[i] % 5;
        T += full_cycles * 3;
        H[i] = remaining;
        if (H[i] > 0) {
            T += 1;
            H[i] -= 1;
            if (H[i] > 0) {
                T += 1;
                H[i] -= 1;
                if (H[i] > 0) {
                    T += 1;
                    H[i] -= 3;
                }
            }
        }
    }
    cout << T << endl;
    return 0;
}