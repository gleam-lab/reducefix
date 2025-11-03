#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e5 + 5;

int n, q;
ll a[MAXN];

// Function to find the k-th smallest distance from point b to any A_i
ll solve_query(ll b, int k) {
    // Create vector of distances from b to each a[i]
    vector<ll> dists;
    for (int i = 0; i < n; i++) {
        dists.push_back(abs(a[i] - b));
    }
    
    // Sort and return k-th smallest (1-indexed)
    sort(dists.begin(), dists.end());
    return dists[k-1];
}

// More efficient version using binary search on answer
ll solve_query_optimized(ll b, int k) {
    ll left = 0, right = 2e8;
    ll ans = right;
    
    while (left <= right) {
        ll mid = (left + right) / 2;
        
        // Count how many points are within distance 'mid' from b
        ll count = 0;
        for (int i = 0; i < n; i++) {
            if (abs(a[i] - b) <= mid) {
                count++;
            }
        }
        
        if (count >= k) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    // Sort the A array to enable binary search optimizations
    sort(a, a + n);
    
    for (int i = 0; i < q; i++) {
        ll b;
        int k;
        cin >> b >> k;
        
        // Use binary search on answer with counting via binary search on sorted array
        ll left = 0, right = 2e8;
        ll ans = right;
        
        while (left <= right) {
            ll mid = (left + right) / 2;
            
            // Count points within distance 'mid' from b using binary search
            // Points in range [b-mid, b+mid]
            ll lower_bound = b - mid;
            ll upper_bound = b + mid;
            
            // Find first index >= (b-mid)
            int left_idx = lower_bound(a, a + n, lower_bound) - a;
            // Find first index > (b+mid)
            int right_idx = upper_bound(a, a + n, upper_bound) - a;
            
            int count = right_idx - left_idx;
            
            if (count >= k) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        
        cout << ans << '\n';
    }
    
    return 0;
}