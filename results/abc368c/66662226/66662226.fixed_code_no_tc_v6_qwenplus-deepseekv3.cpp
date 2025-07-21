#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<ll> H(n);
    rep(i, n) cin >> H[i];
    
    ll ans = 0;
    rep(i, n) {
        ll h = H[i];
        // The number of triple attacks is k, which is floor((h + 2) / 4)
        // But need to find the minimal t where k is the number of triple attacks up to t
        // So the total damage is 3*k + (t - k) >= h
        // => 2*k + t >= h
        // But t = k*3 + m, where m is the remaining turns after the last triple attack in the sequence
        // So we need to find t such that the damage is sufficient
        
        // Binary search to find the minimal t where the total damage >= h
        ll low = 0, high = 2 * h;
        while (low < high) {
            ll mid = (low + high) / 2;
            ll k = mid / 3;
            ll damage = k * 3 + (mid - k);
            if (damage >= h) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        ans = max(ans, low + i);
    }
    cout << ans << endl;
    return 0;
}