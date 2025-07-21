#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    ll k;
    cin >> n >> m >> k;
    
    vector<ll> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        k -= a[i];
    }
    
    // Calculate the prefix sum of sorted votes array
    vector<ll> sorted_a(a);
    sort(sorted_a.begin(), sorted_a.end());
    vector<ll> prefix_sum(n + 1, 0);
    for(int i = 0; i < n; i++) {
        prefix_sum[i + 1] = prefix_sum[i] + sorted_a[i];
    }
    
    // Determine the minimum additional votes needed for each candidate
    vector<ll> ans(n, -1);
    for(int i = 0; i < n; i++) {
        ll target = a[i] + 1;
        ll required_votes = (n - m - 1) * target;
        
        // Binary search to find the minimum additional votes needed
        ll l = 0, r = k + 1;
        while(l < r) {
            ll mid = (l + r) / 2;
            ll current_votes = prefix_sum[n] - prefix_sum[i + 1] + sorted_a[i] + mid;
            
            if(current_votes >= required_votes) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        
        // Check if the found value is valid
        if(prefix_sum[n] - prefix_sum[i + 1] + sorted_a[i] + l >= required_votes) {
            ans[i] = l;
        }
    }
    
    // Output the results
    for(int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    
    return 0;
}