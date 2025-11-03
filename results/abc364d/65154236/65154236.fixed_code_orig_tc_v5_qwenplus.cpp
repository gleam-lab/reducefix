#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int N, Q;
    cin >> N >> Q;
    
    vector<ll> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    
    // Sort the A array to enable binary search and two pointers
    sort(A.begin(), A.end());
    
    for (int q = 0; q < Q; q++) {
        ll b;
        int k;
        cin >> b >> k;
        
        // Binary search on the answer (distance)
        ll left = 0, right = 200000000;
        ll ans = right;
        
        while (left <= right) {
            ll mid = (left + right) / 2;
            
            // Count how many points in A are within distance 'mid' from b
            ll lower_bound = b - mid;
            ll upper_bound = b + mid;
            
            // Find the first index where A[i] >= (b - mid)
            auto it1 = lower_bound(A.begin(), A.end(), lower_bound);
            // Find the first index where A[i] > (b + mid)
            auto it2 = upper_bound(A.begin(), A.end(), upper_bound);
            
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