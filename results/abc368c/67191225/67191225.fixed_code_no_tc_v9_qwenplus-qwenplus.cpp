#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<ll> H(N);
    for (int i = 0; i < N; ++i) {
        cin >> H[i];
    }

    ll T = 0;
    for (int i = 0; i < N; ++i) {
        // Determine how many attacks are needed to defeat this enemy
        ll h = H[i];
        
        // We simulate the attack pattern:
        // Every 3rd attack deals 3 damage, others deal 1 damage
        // So in each cycle of 3 attacks: total damage is 5 (1 + 1 + 3)
        ll full_cycles = h / 5;
        ll remaining = h % 5;
        
        // Each full cycle takes 3 seconds
        T += full_cycles * 3;
        
        // Remaining damage needs to be handled
        if (remaining > 0) {
            T++;
            if (T % 3 == 0) T++;  // If it's a 3rd second, we already used it for triple damage
            remaining--;
            if (remaining > 0) {
                T++;
                if (T % 3 == 0) T++;
                remaining--;
                if (remaining > 0) {
                    T++;
                }
            }
        }
    }

    cout << T << endl;
}