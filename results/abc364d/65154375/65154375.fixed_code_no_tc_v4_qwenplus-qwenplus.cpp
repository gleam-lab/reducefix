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
        
        // Binary search over distance d
        ll low = 0, high = 2e8 + 10;
        ll answer = high;
        
        while (low <= high) {
            ll mid = (low + high) / 2;
            
            // Find first position in A where A[i] >= b - mid
            int left = lower_bound(A.begin(), A.end(), b - mid) - A.begin();
            // Find last position in A where A[i] <= b + mid
            int right = upper_bound(A.begin(), A.end(), b + mid) - A.begin();
            
            if (right - left >= k) {
                answer = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        cout << answer << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    solve();
    return 0;
}