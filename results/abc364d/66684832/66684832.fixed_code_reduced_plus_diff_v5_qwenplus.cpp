#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define int long long
#define endl '\n'

const int N = 2e5 + 9;
int n, q;
int a[N];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);

    while (q--) {
        int b, k;
        cin >> b >> k;
        
        // Binary search on the distance
        int left = 0, right = 2e16;
        int ans = right;
        
        while (left <= right) {
            int mid = (left + right) / 2;
            
            // Count points in [b-mid, b+mid]
            int left_idx = lower_bound(a, a + n, b - mid) - a;
            int right_idx = upper_bound(a, a + n, b + mid) - a;
            int count = right_idx - left_idx;
            
            if (count >= k) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        
        cout << ans << endl;
    }
    
    return 0;
}