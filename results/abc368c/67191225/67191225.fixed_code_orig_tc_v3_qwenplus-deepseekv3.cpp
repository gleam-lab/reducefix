#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<ll> H(N);
    for (int i = 0; i < N; i++) {
        cin >> H[i];
    }
    
    ll T = 0;
    for (int i = 0; i < N; i++) {
        ll hi = H[i];
        // The number of attacks required to kill the i-th enemy
        // Let x be the number of triple attacks (T is multiple of 3)
        // Let y be the number of single attacks (T is not multiple of 3)
        // We have: 3x + y >= hi
        // And the total attacks x + y should be minimized, but x is constrained by T
        // The total time T_i is the number of attacks up to the i-th enemy
        // The actual T after all attacks on i-th enemy is T_i
        // We need to find minimal T_i such that sum_{k=1 to T_i} (if k mod 3 == 0 then 3 else 1) >= H[i]
        
        // Binary search to find the minimal T_i >= T_prev + 1 where the sum of damages >= H[i]
        ll low = T + 1;
        ll high = T + hi * 2; // Upper bound
        ll best_Ti = high;
        while (low <= high) {
            ll mid = (low + high) / 2;
            ll x = mid / 3;
            ll y = mid - x;
            ll damage = 3 * x + y;
            if (damage >= hi) {
                best_Ti = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        T = best_Ti;
    }
    cout << T << endl;
    return 0;
}