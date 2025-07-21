#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e5 + 5;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, Q;
    cin >> N >> Q;
    
    vector<ll> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    // Sort A for binary search later
    sort(A.begin(), A.end());
    
    for (int q = 0; q < Q; ++q) {
        ll b;
        int k;
        cin >> b >> k;
        
        // Binary search on distance using k-th smallest distance
        auto count_less_or_equal = [&](ll dist) {
            // Find number of elements in A where |A[i] - b| <= dist
            ll low = b - dist;
            ll high = b + dist;
            
            // Use binary search to find range in sorted A
            auto l = lower_bound(A.begin(), A.end(), low);
            auto r = upper_bound(A.begin(), A.end(), high);
            return (int)(r - l);
        };
        
        ll left = 0, right = 2e8 + 5; // Max possible distance is ~2e8
        while (left < right) {
            ll mid = (left + right) / 2;
            int cnt = count_less_or_equal(mid);
            if (cnt < k) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        
        cout << left << "\n";
    }
    
    return 0;
}