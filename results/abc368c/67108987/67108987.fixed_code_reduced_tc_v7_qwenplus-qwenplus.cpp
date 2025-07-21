#include<bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> H(N);
    for (int i = 0; i < N; i++) cin >> H[i];
    
    long long T = 0;
    
    // We'll process enemies from left to right
    for (int i = 0; i < N; i++) {
        // How many full cycles of 3 attacks we can do on this enemy
        long long full_cycles = H[i] / 5;
        
        // Apply those full cycles
        T += full_cycles * 3;
        H[i] -= full_cycles * 5;
        
        // Now handle remaining health (0-4)
        if (H[i] > 0) {
            // If we need to do some extra attacks
            if (T % 3 == 0) {
                // We can do a triple damage attack at this time
                T += 1;
                H[i] -= 3;
            } else {
                // Need to wait until next multiple of 3 to do triple damage
                long long wait_time = 3 - (T % 3);
                T += wait_time;
                T += 1; // For the actual attack
                H[i] -= 3;
                
                // If we've overshot, check if earlier attacks could have been better
                // This is where we might have missed an optimal approach
                // Let's reconsider previous logic here
                while (H[i] > 0) {
                    T += 1;
                    if (T % 3 == 0) {
                        H[i] -= 3;
                    } else {
                        H[i] -= 1;
                    }
                }
            }
        }
        
        // If we somehow still have health left, continue attacking
        while (H[i] > 0) {
            T += 1;
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