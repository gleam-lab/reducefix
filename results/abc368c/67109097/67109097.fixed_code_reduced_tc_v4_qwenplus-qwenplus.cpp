#include<bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> H(N);
    for (int i = 0; i < N; i++) cin >> H[i];
    
    long long T = 0;
    
    for (int i = 0; i < N; i++) {
        // For each enemy, determine how many attacks it needs
        // Each attack cycle consists of 3 turns: two 1-damage attacks and one 3-damage attack
        // Total damage per cycle: 5
        long long h = H[i];
        long long cycles = h / 5;
        long long remainder = h % 5;
        
        T += cycles * 3; // 3 time units per full cycle
        
        // Handle remaining health after full cycles
        if (remainder > 0) {
            // At most one final partial attack sequence
            if (remainder <= 2) {
                T += remainder; // Just 1-damage attacks
            } else { // 3 or 4
                T += 2; // First attack (T not multiple of 3), second attack (T+1)
                if (remainder == 4) {
                    T += 1; // Third attack needed for remaining 1 health point
                }
            }
        }
    }
    
    cout << T << endl;
    return 0;
}