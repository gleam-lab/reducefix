#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int N, Q;
    cin >> N >> Q;
    
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    
    // Sort the array to enable binary search
    sort(A.begin(), A.end());
    
    for (int q = 0; q < Q; q++) {
        int b, k;
        cin >> b >> k;
        
        // Binary search on the distance
        int left = 0, right = 200000000;
        int ans = right;
        
        while (left <= right) {
            int mid = (left + right) / 2;
            
            // Count points in [b-mid, b+mid]
            auto it1 = lower_bound(A.begin(), A.end(), b - mid);
            auto it2 = upper_bound(A.begin(), A.end(), b + mid);
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