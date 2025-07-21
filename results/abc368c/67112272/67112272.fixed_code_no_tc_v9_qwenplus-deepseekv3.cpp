#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for (ll i=0;i < (n); i++)
using ll = long long;

// Function to compute the minimal T such that 2*(T//3) + T >= H
ll compute_min_T(ll H) {
    ll low = 0, high = 2 * H;
    while (low < high) {
        ll mid = (low + high) / 2;
        ll k = mid / 3;
        ll damage = 2 * k + mid;
        if (damage >= H) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    return low;
}

int main() {
    int n; cin >> n;
    vector<ll> h(n);
    rep(i, n) cin >> h[i];
    
    ll total_T = 0;
    rep(i, n) {
        ll H = h[i];
        // The minimal T for this enemy is the smallest T where 2*(T//3) + T >= H
        ll min_T = compute_min_T(H);
        // The actual T is the maximum between the current total_T + min_T and adjustments
        // Because attacks must be sequential; previous enemies' attacks affect the current one's T
        // The total T must be at least the sum of previous T's plus the current min_T in some way
        // However, the attacks are sequential, so the current enemy's T must be after all previous attacks
        // Thus, the minimal T for the current enemy is the minimal T' such that T' >= previous total_T + 1 and 2*(T'//3) + T' >= H
        // So we need to find T' >= previous total_T + 1 that satisfies the damage condition
        ll low = total_T + 1, high = 2 * (H + total_T);
        ll T_candidate = 0;
        while (low <= high) {
            ll mid = (low + high) / 2;
            ll k = mid / 3;
            ll damage = 2 * k + mid;
            if (damage >= H) {
                T_candidate = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        total_T = T_candidate;
    }
    cout << total_T << endl;
    return 0;
}