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
    
    sort(a.begin(), a.end());
    
    for (int j = 0; j < Q; j++) {
        ll b;
        int k;
        cin >> b >> k;
        
        // Find the k-th smallest distance from b to any point in a
        // We'll use binary search on the answer (distance)
        ll left = 0, right = 2e8 + 10;
        ll ans = right;
        
        while (left <= right) {
            ll mid = (left + right) / 2;
            
            // Count how many points in a are within distance 'mid' from b
            ll lower_bound = b - mid;
            ll upper_bound = b + mid;
            
            auto it1 = lower_bound(a.begin(), a.end(), lower_bound);
            auto it2 = upper_bound(a.begin(), a.end(), upper_bound);
            int count = it2 - it1;
            
            if (count >= k) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        
        cout << ans << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}