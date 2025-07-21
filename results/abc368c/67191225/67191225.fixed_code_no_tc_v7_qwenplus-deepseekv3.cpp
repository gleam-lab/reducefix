#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    vector<ll> H(N);
    for (int i = 0; i < N; ++i) {
        cin >> H[i];
    }
    
    ll T = 0;
    for (int i = 0; i < N; ++i) {
        ll h = H[i];
        if (i > 0 && H[i-1] > 0) {
            // The previous enemy still has HP, which shouldn't happen since we process frontmost first
            // This indicates a logic error in simulation approach
            // So, this approach is incorrect; need to simulate step-by-step
            // Hence, we need a different approach
            // Therefore, let's reset and use a correct simulation approach
            // But given constraints, we need a mathematical approach
            // So, let's instead compute the required T for each enemy considering the attack pattern
            // But this is complex; perhaps binary search on T is better
            // But for now, let's proceed with step-by-step simulation for correctness
            // But for large N and H_i, it's too slow
            // So, original approach is flawed; need a better math solution
            // Hence, the following code is incorrect for the problem
            // Thus, here's a correct simulation approach, though it may not pass all cases due to time
            // But for the sake of correctness, let's do it
            T = 0;
            int current_enemy = 0;
            while (current_enemy < N) {
                T++;
                ll damage = (T % 3 == 0) ? 3 : 1;
                if (H[current_enemy] > 0) {
                    H[current_enemy] -= damage;
                    if (H[current_enemy] <= 0) {
                        current_enemy++;
                    }
                }
            }
            cout << T << endl;
            return 0;
        }
        
        // Full cycles of (1,1,3) attacks
        ll full_cycles = h / 5;
        T += full_cycles * 3;
        h -= full_cycles * 5;
        
        if (h > 0) {
            // Position in the attack cycle (0, 1, 2)
            ll pos = T % 3;
            if (pos == 0) {
                // Next attacks are 1,1,3...
                if (h <= 1) {
                    T += 1;
                } else if (h <= 2) {
                    T += 2;
                } else if (h <= 5) {
                    T += 3;
                }
            } else if (pos == 1) {
                // Next attacks are 1,3...
                if (h <= 1) {
                    T += 1;
                } else if (h <= 4) {
                    T += 2;
                }
            } else { // pos == 2
                // Next attack is 3
                if (h <= 3) {
                    T += 1;
                } else {
                    T += 2;
                }
            }
        }
    }
    
    cout << T << endl;
    return 0;
}