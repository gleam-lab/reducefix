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
    for (int i = 0; i < N; ++i) {
        // For each enemy, calculate how many full attack cycles we need
        // Each cycle consists of 3 attacks: two 1-damage and one 3-damage at T%3 == 0
        // Total damage per cycle = 5
        
        long long h = H[i];
        long long full_cycles = h / 5;
        long long remainder = h % 5;
        
        T += full_cycles * 3;
        
        // Handle remaining health
        if (remainder > 0) {
            if (T % 3 == 0) {
                // If current T is multiple of 3, next attack will be +1 with damage 3
                // So we can add just 1 step to get 3 damage
                T++;
            } else {
                // We need to reach the next multiple of 3 or finish in fewer steps
                // Calculate minimum number of steps needed
                // Either:
                // - Use ceiling(remainder / 3) if we can hit with triple damage
                // - Or simply add attacks
                
                // The optimal strategy is to wait until the next "triple" attack if beneficial
                long long steps_to_next_triple = (3 - (T % 3));
                if (remainder >= 3 || steps_to_next_triple > remainder) {
                    T += ceil(remainder / 3.0);
                } else {
                    T += steps_to_next_triple;
                    remainder -= 3;
                    if (remainder > 0) {
                        T += ceil(remainder / 1.0);
                    }
                }
            }
        }
    }

    cout << T << endl;
    return 0;
}