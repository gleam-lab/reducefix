#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> H(N);
    for (int i = 0; i < N; i++) cin >> H[i];
    
    long long T = 0;
    for (int i = 0; i < N; i++) {
        long long h = H[i];
        if (h <= 0) continue;
        
        // Calculate how many full cycles of 3T (5 damage per 3T) are needed
        long long full_cycles = h / 5;
        long long remaining = h % 5;
        
        // Each full cycle contributes 3T attacks and 5 damage
        long long attacks_needed = full_cycles * 3;
        long long damage_done = full_cycles * 5;
        
        // Now handle the remaining damage
        while (remaining > 0) {
            attacks_needed++;
            if (attacks_needed % 3 == 0) {
                remaining -= 3;
            } else {
                remaining -= 1;
            }
        }
        
        // The total T is updated by the attacks needed for this enemy
        // But the attacks must be in sequence, so T is increased by attacks_needed
        T += attacks_needed;
    }
    
    cout << T << endl;
    return 0;
}