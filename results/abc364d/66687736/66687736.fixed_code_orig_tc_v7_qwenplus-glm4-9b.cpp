#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long
#define rep(i, n) for (ll i = 0; i < (n); ++i)

int main() {
    ll n, q;
    cin >> n >> q;
    
    vector<ll> a(n);
    for (ll &x : a) cin >> x;

    for (ll q_i = 0; q_i < q; q_i++) {
        ll b, k;
        cin >> b >> k;
        ll lower = -1e9, upper = 1e9;

        // Binary search to find the k-th closest point
        while (upper - lower > 1) {
            ll mid = (lower + upper) / 2;
            ll count = 0;
            for (ll x : a) {
                if (abs(x - b) <= mid) count++;
                if (count >= k) break;
            }
            if (count >= k) {
                upper = mid;
            } else {
                lower = mid;
            }
        }

        cout << upper - b << endl;
    }

    return 0;
}