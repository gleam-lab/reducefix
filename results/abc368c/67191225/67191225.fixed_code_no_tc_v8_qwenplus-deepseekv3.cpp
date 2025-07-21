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
        ll h = H[i];
        ll k3 = (h + 2) / 3;  // ceil(h / 3)
        ll remainder = h - 3 * k3;
        if (remainder < 0) {
            remainder += 3;
            k3--;
        }
        
        // The minimal T required to kill this enemy is T >= 3*k3 - 2 + (remainder > 0 ? 1 : 0)
        // But we need to ensure that T is at least the previous T plus the required steps for this enemy
        // So we need to find the minimal T' such that T' >= T + 1 and the attacks on this enemy are correctly timed
        // We can model it as:
        // The attacks on this enemy start at T + 1, T + 2, ..., T + steps
        // The steps are combinations of 1-damage and 3-damage attacks
        // The total steps must satisfy: 3 * (steps / 3) + (steps % 3) >= h
        // But a better approach is to compute the minimal steps to kill the enemy under the attack pattern
        // Let steps be the number of attacks needed: steps = ceil(h / 3) * 2 - (if h mod 3 == 0)
        // But let's compute it step by step
        
        ll low = 0, high = 2 * h;
        ll steps = 0;
        while (low <= high) {
            ll mid = (low + high) / 2;
            ll damage = (mid / 3) * 3 + (mid - mid / 3);
            if (damage >= h) {
                steps = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        // Now, the enemy is killed at T + steps
        // So the new T is T + steps
        T += steps;
    }
    cout << T << endl;
    
    return 0;
}