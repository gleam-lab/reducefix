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
    
    // Sort candidates based on the number of votes they have received
    vector<pair<ll, int>> candidates;
    for(int i = 0; i < n; ++i)
        candidates.emplace_back(a[i], i);
    
    sort(candidates.rbegin(), candidates.rend());
    
    // Calculate the prefix sum of votes
    vector<ll> pref(n + 1);
    for(int i = 0; i < n; ++i)
        pref[i + 1] = pref[i] + candidates[i].first;
    
    vector<ll> ans(n, -1);
    
    for(int i = 0; i < n; ++i) {
        ll target = k + 1;
        
        // Binary search to find the minimum number of additional votes needed
        ll left = 0, right = k;
        while(left <= right) {
            ll mid = left + (right - left) / 2;
            
            // Count the number of candidates who can still win
            int count = 0;
            for(int j = i + 1; j < n; ++j) {
                if(pref[n] - pref[j + 1] + candidates[j].first + mid > pref[j] - pref[i]) {
                    ++count;
                } else {
                    break;
                }
            }
            
            if(count < m) {
                target = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        
        if(target != k + 1) {
            ans[candidates[i].second] = target;
        }
    }
    
    for(auto i : ans) 
        cout << i << ' ';
    
    return 0;
}