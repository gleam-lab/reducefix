#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;
    
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    
    sort(a.begin(), a.end());
    
    while (Q--) {
        int b, k;
        cin >> b >> k;
        
        // Binary search on the distance
        int left = 0, right = 2e8;
        int ans = right;
        
        while (left <= right) {
            int mid = (left + right) / 2;
            
            // Count points in [b-mid, b+mid]
            int l_idx = lower_bound(a.begin(), a.end(), b - mid) - a.begin();
            int r_idx = upper_bound(a.begin(), a.end(), b + mid) - a.begin();
            int count = r_idx - l_idx;
            
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