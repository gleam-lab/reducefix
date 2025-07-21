#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> H(N);
    for (int i = 0; i < N; i++) cin >> H[i];
    
    long long T = 0;
    long long sum_extra = 0;
    
    for (int i = 0; i < N; i++) {
        H[i] -= sum_extra;
        if (H[i] <= 0) continue;
        
        long long cycles = H[i] / (3 + 1 + 1); // Each cycle of 3 turns deals 5 damage (3 + 1 + 1)
        long long remaining = H[i] % (3 + 1 + 1);
        
        T += 3 * cycles;
        sum_extra += 3 * cycles;
        H[i] = remaining;
        
        while (H[i] > 0) {
            T++;
            if (T % 3 == 0) {
                H[i] -= 3;
                sum_extra += 3;
            } else {
                H[i] -= 1;
                sum_extra += 1;
            }
        }
    }
    
    cout << T << endl;
    return 0;
}