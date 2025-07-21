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
    
    ll low = 0, high = 1e18;
    ll ans = 0;
    
    while (low <= high) {
        ll mid = (low + high) / 2;
        ll total = 0;
        for (int i = 0; i < n; ++i) {
            ll remaining = h[i];
            // The number of full 3-turn cycles (each dealing 5 damage in 3 turns)
            ll cycles = min(mid / 3, remaining / 5);
            remaining -= cycles * 5;
            // The remaining attacks after cycles
            ll t = cycles * 3;
            while (remaining > 0 && t < mid) {
                t++;
                if (t % 3 == 0) {
                    remaining -= 3;
                } else {
                    remaining -= 1;
                }
            }
            if (remaining > 0) {
                total = mid + 1;
                break;
            }
        }
        if (total <= mid) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    
    cout << ans << endl;
    return 0;
}