#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<ll> h(n);
    rep(i, n) cin >> h[i];
    ll t = 0;
    rep(i, n) {
        if (h[i] <= 0) continue;
        // Calculate the number of attacks needed for this enemy
        // The attacks alternate between 1 and 3 damage based on t+1, t+2, etc.
        // We need to find the minimal k such that sum_{m=1 to k} d_m >= h[i], where d_m is 3 if (t + m) % 3 == 0 else 1.
        // Binary search for k.
        ll low = 1, high = 2 * h[i], k = 0;
        while (low <= high) {
            ll mid = (low + high) / 2;
            ll sum = 0;
            // Compute the sum of damages over mid attacks starting at t+1
            ll full_cycles = mid / 3;
            ll remainder = mid % 3;
            sum = full_cycles * 5 + remainder * 1;
            if (remainder >= 1) sum += 0; // first attack is 1
            if (remainder >= 2) sum += 1; // second attack is 1
            if (sum >= h[i]) {
                high = mid - 1;
                k = mid;
            } else {
                low = mid + 1;
            }
        }
        t += k;
    }
    cout << t << endl;
}