#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    ll k;
    cin >> n >> m >> k;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        k -= a[i];
    }
    
    // Sort indices based on current vote count
    vector<int> ord(n);
    iota(all(ord), 0);
    sort(all(ord), [&](int i, int j) { return a[i] < a[j]; });

    // Calculate prefix sums of sorted vote counts
    vector<ll> pref(n + 1);
    for(int i = 0; i < n; i++) {
        pref[i + 1] = pref[i] + a[ord[i]];
    }

    vector<ll> ans(n, -1);

    for(int i = 0; i < n; i++) {
        ll l = 0, r = k + 1;
        
        while(l < r) {
            ll mid = (l + r) / 2;
            
            // Number of candidates that can surpass candidate i
            ll surplus = min(m - 1, n - i - 1);
            ll needed_surplus_votes = surplus * (a[ord[i]] + mid + 1);
            
            // Total votes needed including those surplus votes
            ll total_needed_votes = needed_surplus_votes - pref[n - surplus];
            
            if(total_needed_votes > k) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        
        // Check if we found a valid number of votes
        if(l <= k) {
            ans[ord[i]] = l;
        }
    }

    for(auto i : ans) cout << i << ' ';
}