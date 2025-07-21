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
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        k -= a[i];
    }
    
    // Calculate prefix sums of sorted array for binary search
    vector<ll> sorted_a(a);
    sort(all(sorted_a));
    vector<ll> prefix_sorted(n + 1);
    for (int i = 0; i < n; i++) {
        prefix_sorted[i + 1] = sorted_a[i] + prefix_sorted[i];
    }
    
    // Result vector
    vector<ll> ans(n, -1);
    
    // If no votes are left or m is 0, all candidates cannot win
    if (k == 0 || m == 0) {
        for (int i = 0; i < n; i++) {
            ans[i] = -1;
        }
        for (ll i : ans) cout << i << ' ';
        return 0;
    }
    
    // Find the candidate that is currently in M-th position
    int mth_index = n - m;
    
    for (int i = 0; i < n; i++) {
        if (a[i] >= a[mth_index]) {
            mth_index++;
        }
    }
    
    // Binary search to find minimum votes needed
    ll l = 0, r = k + 1;
    while (l + 1 < r) {
        ll mid = (l + r) / 2;
        ll required_votes = 0;
        int count = 0;
        
        // Check if adding mid votes guarantees i's victory
        for (int j = 0; j < n; j++) {
            ll votes_needed = mth_index + 1 - count;
            if (a[j] < a[i]) {
                votes_needed = min(votes_needed, mid + 1);
            }
            if (votes_needed > k) break;
            
            required_votes += votes_needed;
            count++;
        }
        
        if (required_votes > k) {
            r = mid;
        } else {
            l = mid;
        }
    }
    
    // Set answer for all candidates
    for (int i = 0; i < n; i++) {
        if (i == n - m) {
            ans[i] = l - a[i];
        } else {
            ans[i] = -1;
        }
    }
    
    for (ll i : ans) cout << i << ' ';
}