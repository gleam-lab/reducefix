#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool isPossible(ll T, const vector<ll>& H) {
    ll additional_attacks = 0;
    for (ll h : H) {
        ll attacks_needed = 0;
        // The damage dealt is (T - additional_attacks) attacks, where every 3rd attack is 3 damage.
        // The total damage is (T - additional_attacks) + 2 * ((T - additional_attacks) / 3)
        // Because every 3rd attack adds 2 extra damage (3 instead of 1).
        ll total_damage = (T - additional_attacks) + 2 * ((T - additional_attacks) / 3);
        if (total_damage < h) {
            return false;
        }
        // The number of attacks needed to defeat this enemy is the minimal t where t + 2*(t/3) >= h
        // Find minimal t such that h <= t + 2*(t/3)
        ll low = 0, high = T - additional_attacks;
        ll t_needed = high;
        while (low <= high) {
            ll mid = (low + high) / 2;
            if (mid + 2 * (mid / 3) >= h) {
                t_needed = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        additional_attacks += t_needed;
        if (additional_attacks > T) {
            return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    vector<ll> H(N);
    for (int i = 0; i < N; ++i) {
        cin >> H[i];
    }
    
    ll left = 0;
    ll right = 1; // Initialize right to a small value and expand dynamically
    while (!isPossible(right, H)) {
        right *= 2;
    }
    
    ll answer = right;
    while (left <= right) {
        ll mid = (left + right) / 2;
        if (isPossible(mid, H)) {
            answer = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    
    cout << answer << endl;
    
    return 0;
}