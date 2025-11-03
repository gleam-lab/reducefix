#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int N, Q;
    cin >> N >> Q;
    
    vector<ll> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    
    // Sort the A points for efficient binary search
    sort(a.begin(), a.end());
    
    for (int j = 0; j < Q; j++) {
        ll b;
        int k;
        cin >> b >> k;
        
        // Binary search on the distance
        ll left = 0, right = 2e8;
        ll ans = right;
        
        while (left <= right) {
            ll mid = (left + right) / 2;
            
            // Count how many points in A are within distance 'mid' from point B
            ll lower_bound = b - mid;
            ll upper_bound = b + mid;
            
            // Find the first index where a[i] >= (b - mid)
            auto it1 = lower_bound(a.begin(), a.end(), lower_bound);
            // Find the first index where a[i] > (b + mid)
            auto it2 = upper_bound(a.begin(), a.end(), upper_bound);
            
            int count = distance(it1, it2); // Number of points within [b-mid, b+mid]
            
            if (count >= k) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        
        cout << ans << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}