#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;
    
    vector<long long> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    
    sort(A.begin(), A.end());
    
    while (Q--) {
        long long b;
        int k;
        cin >> b >> k;
        
        // Binary search on the answer (distance)
        long long left = 0, right = 2e9;
        long long ans = right;
        
        while (left <= right) {
            long long mid = (left + right) / 2;
            
            // Count points in [b-mid, b+mid]
            auto low = lower_bound(A.begin(), A.end(), b - mid);
            auto high = upper_bound(A.begin(), A.end(), b + mid);
            int count = high - low;
            
            if (count >= k) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        
        cout << ans << '\n';
    }
    
    return 0;
}