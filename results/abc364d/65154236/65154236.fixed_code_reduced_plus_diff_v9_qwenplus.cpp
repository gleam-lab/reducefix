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
    
    // Sort the A array to enable binary search
    sort(A.begin(), A.end());
    
    for (int q = 0; q < Q; q++) {
        ll b;
        int k;
        cin >> b >> k;
        
        // We want to find the k-th smallest distance from b to points in A
        // Instead of computing all distances, we can use binary search on the answer
        
        // The maximum possible distance is when point is at -1e8 and b is at 1e8 (or vice versa)
        ll left = 0, right = 2e8 + 1;
        
        while (left < right) {
            ll mid = (left + right) / 2;
            
            // Count how many points in A are within distance 'mid' from b
            // This means points in [b-mid, b+mid]
            auto low = lower_bound(A.begin(), A.end(), b - mid);
            auto high = upper_bound(A.begin(), A.end(), b + mid);
            int count = high - low;
            
            if (count >= k) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        cout << left << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}