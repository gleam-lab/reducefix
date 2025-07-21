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
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        k -= a[i];
    }
    
    // Sort candidates based on the number of votes they currently have
    vector<pair<ll, int>> candidates(n);
    for(int i = 0; i < n; ++i) {
        candidates[i].first = a[i];
        candidates[i].second = i;
    }
    sort(candidates.begin(), candidates.end());
    
    // Calculate the prefix sum of votes
    vector<ll> pref(n + 1);
    for(int i = 0; i < n; ++i) {
        pref[i + 1] = pref[i] + candidates[i].first;
    }
    
    // Initialize answer array with -1
    vector<ll> ans(n, -1);
    
    // Iterate over each candidate
    for(int i = 0; i < n; ++i) {
        ll x = candidates[i].first;
        int id = candidates[i].second;
        
        // Calculate the maximum number of votes other candidates can get
        ll max_votes_other = pref[n] - pref[i + 1];
        
        // Calculate the minimum number of votes needed to ensure victory
        ll min_votes_needed = (n - m - 1) * (x + 1) - max_votes_other;
        
        // Check if it's possible to achieve the required votes
        if(min_votes_needed <= k) {
            ans[id] = 0;
        } else {
            // Binary search to find the minimum number of additional votes needed
            ll l = 0, r = k + 1;
            while(l < r) {
                ll mid = (l + r) / 2;
                ll total_votes = pref[n] - pref[i + 1] + mid;
                ll needed_votes = (n - m - 1) * (x + mid + 1) - total_votes;
                
                if(needed_votes <= k) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }
            ans[id] = l;
        }
    }
    
    // Print the result
    for(ll val : ans) {
        cout << val << " ";
    }
    cout << endl;
    
    return 0;
}