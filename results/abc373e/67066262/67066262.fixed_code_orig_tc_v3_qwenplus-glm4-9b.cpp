#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    ll k;
    cin >> n >> m >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        k -= a[i];
    }
    vector<ll> sorted_a = a;
    sort(sorted_a.begin(), sorted_a.end());
    
    vector<ll> ans(n, -1);
    for (ll i = 0; i < n; i++) {
        // Binary search for the minimum additional votes required
        ll low = 0, high = k + 1;
        while (low < high) {
            ll mid = (low + high + 1) / 2;
            ll votes_needed = 0;
            // Calculate votes needed to be in top m
            votes_needed += m * (sorted_a[i] + mid) - (mid * m);
            // Calculate votes needed to guarantee victory over candidates ahead
            votes_needed -= sorted_a[i];
            if (votes_needed <= k - a[i]) {
                high = mid;
            } else {
                low = mid;
            }
        }
        if (low <= k - a[i]) {
            ans[i] = low - sorted_a[i];
        } else {
            ans[i] = -1;
        }
    }
    for (ll vote : ans) cout << vote << ' ';
    return 0;
}