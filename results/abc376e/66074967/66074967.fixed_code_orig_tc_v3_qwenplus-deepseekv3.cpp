#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define int long long

const int inf = 1LL << 60;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<pair<int, int>> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i].first;
        }
        for (int i = 0; i < n; i++) {
            cin >> a[i].second;
        }
        
        sort(a.begin(), a.end());
        
        vector<int> prefix_sum(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix_sum[i + 1] = prefix_sum[i] + a[i].second;
        }
        
        int ans = inf;
        
        if (k == 1) {
            for (int i = 0; i < n; i++) {
                ans = min(ans, a[i].first * a[i].second);
            }
        } else {
            vector<int> min_b(n, inf);
            min_b[n - 1] = a[n - 1].second;
            for (int i = n - 2; i >= 0; i--) {
                min_b[i] = min(min_b[i + 1], a[i].second);
            }
            
            for (int i = k - 1; i < n; i++) {
                int current_max_a = a[i].first;
                int sum_b = prefix_sum[i + 1] - prefix_sum[i + 1 - k];
                ans = min(ans, current_max_a * sum_b);
            }
        }
        
        cout << ans << '\n';
    }
    return 0;
}