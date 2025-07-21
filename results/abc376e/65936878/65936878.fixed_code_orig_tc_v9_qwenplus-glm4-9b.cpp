#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<pair<int, int>> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i].first >> a[i].second;
        }
        sort(a.begin(), a.end(), greater<pair<int, int>>());
        
        int sum_a_first_k = 0, sum_b_first_k = 0;
        for (int i = 0; i < k; i++) {
            sum_a_first_k += a[i].first;
            sum_b_first_k += a[i].second;
        }
        
        int ans = sum_a_first_k * sum_b_first_k;
        for (int i = k; i < n; i++) {
            sum_a_first_k += a[i].first - a[i - k].first;
            sum_b_first_k += a[i].second - a[i - k].second;
            ans = min(ans, sum_a_first_k * sum_b_first_k);
        }
        
        cout << ans << '\n';
    }
    
    return 0;
}