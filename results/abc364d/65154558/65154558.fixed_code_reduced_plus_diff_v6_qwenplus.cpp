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
    
    // Sort the A points for binary search
    sort(a.begin(), a.end());
    
    for (int q = 0; q < Q; q++) {
        ll b;
        int k;
        cin >> b >> k;
        
        // Binary search on the distance
        ll left = 0, right = 2e8;
        ll ans = right;
        
        while (left <= right) {
            ll mid = (left + right) / 2;
            
            // Find the range of A points within distance 'mid' from B
            auto low = lower_bound(a.begin(), a.end(), b - mid);
            auto high = upper_bound(a.begin(), a.end(), b + mid);
            
            // Count how many points are in [b-mid, b+mid]
            int count = distance(low, high);
            
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