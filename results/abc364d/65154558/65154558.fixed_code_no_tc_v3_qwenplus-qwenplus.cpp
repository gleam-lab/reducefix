#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    int N, Q;
    cin >> N >> Q;
    
    vector<ll> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    // Sort the A array for binary search operations
    sort(A.begin(), A.end());
    
    for (int q = 0; q < Q; ++q) {
        ll b;
        int k;
        cin >> b >> k;
        
        // Binary search on distance
        ll low = 0, high = 2e8 + 10; // Max possible distance is ~2e8
        while (low < high) {
            ll mid = (low + high) / 2;
            
            // Count how many points have distance <= mid from b
            // That is, count points in [b-mid, b+mid]
            ll left = b - mid;
            ll right = b + mid;
            
            // Using lower_bound and upper_bound to find the range
            int l = lower_bound(A.begin(), A.end(), left) - A.begin();
            int r = upper_bound(A.begin(), A.end(), right) - A.begin();
            
            if (r - l >= k) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        
        cout << low << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    solve();
    return 0;
}