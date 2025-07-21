#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<ll> h(n);
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
    }

    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        ll cycles = h[i] / 5;
        ll remainder = h[i] % 5;
        
        if (remainder == 0) {
            ans += cycles * 3;
        } else if (remainder <= 2) {
            ans += cycles * 3 + remainder;
        } else {
            ans += cycles * 3 + 3;
        }
    }

    // Now, we need to adjust for overlapping attacks where the previous enemy's attacks affect the current one's T
    // We need to find the minimal T such that for each enemy, the total damage is >= H_i
    // The initial approach didn't account for the fact that attacks on previous enemies contribute to T
    // So we need a different approach
    
    // Alternative approach: binary search for T
    ll low = 0, high = 1e18;
    ll answer = 0;
    while (low <= high) {
        ll mid = (low + high) / 2;
        bool possible = true;
        ll total_attacks = 0;
        for (int i = 0; i < n; ++i) {
            ll damage = (mid / 3) * 5 + (mid % 3);
            if (mid % 3 == 0) {
                damage = (mid / 3) * 5;
            } else if (mid % 3 == 1) {
                damage = (mid / 3) * 5 + 1;
            } else if (mid % 3 == 2) {
                damage = (mid / 3) * 5 + 2;
            }
            if (damage < h[i]) {
                possible = false;
                break;
            }
        }
        if (possible) {
            answer = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    cout << answer << endl;
    
    return 0;
}