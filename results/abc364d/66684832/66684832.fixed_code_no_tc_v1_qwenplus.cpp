#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define int long long
const int INF = 1e18;

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
        
        // Binary search on the answer (distance)
        int left = 0, right = 2e8;
        int ans = right;
        
        while (left <= right) {
            int mid = (left + right) / 2;
            
            // Find the range of points in A within distance 'mid' from point b
            int low = b - mid;
            int high = b + mid;
            
            // Count how many points in A are in [low, high]
            auto it1 = lower_bound(a.begin(), a.end(), low);
            auto it2 = upper_bound(a.begin(), a.end(), high);
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
    
    return 0;
}