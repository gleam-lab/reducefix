#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, Q;
    cin >> N >> Q;
    
    vector<ll> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    // Sort the A array to enable binary search
    sort(A.begin(), A.end());
    
    for (int q = 0; q < Q; ++q) {
        ll b;
        int k;
        cin >> b >> k;
        
        // Binary search on distance
        ll low = 0, high = 2e8 + 10; // Max possible distance is ~2*1e8
        ll answer = high;
        
        while (low <= high) {
            ll mid = (low + high) / 2;
            
            // Count how many points are within distance mid from b
            int count = 0;
            auto left = lower_bound(A.begin(), A.end(), b - mid);
            auto right = upper_bound(A.begin(), A.end(), b + mid);
            count = right - left;
            
            if (count >= k) {
                answer = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        cout << answer << '\n';
    }
}

int main() {
    solve();
    return 0;
}