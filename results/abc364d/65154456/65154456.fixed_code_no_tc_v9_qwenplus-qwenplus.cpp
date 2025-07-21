#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, Q;
    cin >> N >> Q;
    
    vector<ll> a(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }
    
    // Sort the A array for binary search usage
    sort(a.begin(), a.end());
    
    for (int q = 0; q < Q; ++q) {
        ll b;
        int k;
        cin >> b >> k;
        
        // Binary search on distance
        ll low = 0, high = 2e8 + 10; // Max possible distance is ~2e8
        
        while (low < high) {
            ll mid = (low + high) / 2;
            
            // Count how many points have distance <= mid from b
            int left = lower_bound(a.begin(), a.end(), b - mid) - a.begin();
            int right = upper_bound(a.begin(), a.end(), b + mid) - a.begin();
            int count = right - left;
            
            if (count >= k) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        
        cout << low << "\n";
    }
}

int main() {
    solve();
    return 0;
}