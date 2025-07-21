#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> H(N);
    for (int i = 0; i < N; ++i) {
        cin >> H[i];
    }
    
    long long T = 0;
    long long total_attacks = 0;
    
    for (int i = 0; i < N; ++i) {
        H[i] -= total_attacks;
        if (H[i] <= 0) continue;
        
        long long full_cycles = H[i] / 5;
        long long remaining = H[i] % 5;
        
        T += full_cycles * 3;
        total_attacks += full_cycles * 5;
        
        H[i] = remaining;
        if (H[i] > 0) {
            if (T % 3 == 2) {
                // Next attack is T+1 (mod 3 is 0), so 3 damage.
                if (H[i] <= 3) {
                    T += 1;
                    total_attacks += 3;
                } else {
                    T += 3;
                    total_attacks += 5; // Wait, no. Maybe another approach.
                    // This part is tricky. Maybe better to simulate step by step.
                }
            } else {
                // Next attacks are 1 or 1+1 damage.
                if (H[i] <= 1) {
                    T += 1;
                    total_attacks += 1;
                } else if (H[i] <= 2) {
                    T += 2;
                    total_attacks += 2;
                } else {
                    T += 3;
                    total_attacks += 3 + 1; // Wait, no.
                }
            }
        }
    }
    
    // The above approach might not capture the exact sequence. Let's try a different method.
    // Alternative approach: For each enemy, compute the exact T increment required.
    
    T = 0;
    for (int i = 0; i < N; ++i) {
        if (H[i] <= 0) continue;
        
        // The damage pattern is periodic every 3 attacks: 1, 1, 3.
        // The total damage per 3 attacks is 5.
        long long full_cycles = H[i] / 5;
        long long remaining = H[i] % 5;
        
        T += full_cycles * 3;
        H[i] = remaining;
        
        if (H[i] > 0) {
            // Now, simulate the remaining attacks.
            for (int step = 1; step <= 3 && H[i] > 0; ++step) {
                T += 1;
                if (step % 3 == 0) {
                    H[i] -= 3;
                } else {
                    H[i] -= 1;
                }
            }
        }
    }
    
    cout << T << endl;
    return 0;
}