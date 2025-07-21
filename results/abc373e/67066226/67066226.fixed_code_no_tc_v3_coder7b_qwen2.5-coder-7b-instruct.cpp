#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    ll k;
    cin >> n >> m >> k;
    vector<ll> a(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        k -= a[i];
    }

    // Sort candidates based on their current vote counts
    vector<pair<ll, int>> candidates;
    for(int i = 0; i < n; ++i)
        candidates.emplace_back(a[i], i);

    sort(candidates.rbegin(), candidates.rend());

    // Calculate prefix sums for quick calculations
    vector<ll> pref(n + 1);
    for(int i = 0; i < n; ++i)
        pref[i + 1] = pref[i] + candidates[i].first;

    vector<ll> ans(n, -1);
    for(int i = 0; i < n; ++i) {
        ll x = candidates[i].first;
        ll needed = -1;
        
        // Binary search for the minimum additional votes needed
        ll lo = 0, hi = k + 1;
        while(lo < hi) {
            ll mid = (lo + hi) / 2;
            ll total_votes_if_i_win = x + mid;
            ll votes_needed_by_others = mid * (n - i - 1);
            
            if(total_votes_if_i_win + votes_needed_by_others > pref[n]) {
                hi = mid;
            } else {
                needed = mid;
                lo = mid + 1;
            }
        }
        
        if(needed != -1 && needed <= k - pref[n])
            ans[candidates[i].second] = needed;
    }

    for(int i = 0; i < n; ++i)
        cout << ans[i] << " ";
    
    return 0;
}