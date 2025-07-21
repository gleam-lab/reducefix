#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define int long long

const int inf = 1e9;

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        
        vector<int> a(n), b(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }
        
        // Sort A in descending order and B in ascending order
        sort(a.begin(), a.end(), greater<int>());
        sort(b.begin(), b.end());
        
        int ans = inf;
        for (int i = 0; i <= n - k; ++i) {
            int current_sum = 0;
            for (int j = 0; j < k; ++j) {
                current_sum += b[i + j];
            }
            ans = min(ans, a[i] * current_sum);
        }
        
        cout << ans << '\n';
    }
    
    return 0;
}