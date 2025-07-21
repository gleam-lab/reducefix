#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll calculate_min_time(ll h, ll start_T) {
    ll low = start_T;
    ll high = start_T + 3 * h;
    ll ans = high;
    
    while (low <= high) {
        ll mid = (low + high) / 2;
        ll t3 = mid / 3;
        ll t_remain = mid - t3;
        ll damage = t3 * 3 + t_remain * 1;
        if (damage >= h) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<ll> h(n);
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
    }
    
    ll total_T = 0;
    for (int i = 0; i < n; ++i) {
        ll h_i = h[i];
        ll low = total_T;
        ll high = total_T + 3 * h_i;
        ll ans = high;
        
        while (low <= high) {
            ll mid = (low + high) / 2;
            ll t3 = (mid - total_T) / 3;
            ll t_remain = (mid - total_T) - t3;
            ll damage = t3 * 3 + t_remain * 1;
            if (damage >= h_i) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        total_T = ans;
    }
    
    cout << total_T << endl;
    
    return 0;
}