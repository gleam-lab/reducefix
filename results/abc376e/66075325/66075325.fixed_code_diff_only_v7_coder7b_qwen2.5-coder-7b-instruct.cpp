#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define int long long

const int N = 2e5 + 9, inf = 0x3f3f3f3f3f3f3f3f;

signed main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        
        vector<pair<int, int>> a(n), b(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i].first;
            a[i].second = i;
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i].first;
            b[i].second = i;
        }
        
        // Sort based on A values
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        
        // Calculate prefix sums for B
        vector<int> prefix_b(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            prefix_b[i] = prefix_b[i - 1] + b[i - 1].first;
        }
        
        int ans = inf;
        for (int i = k - 1; i < n; i++) {
            int max_a = a[i].first;
            int sum_b = prefix_b[i + 1] - prefix_b[i - k + 1];
            ans = min(ans, max_a * sum_b);
        }
        
        cout << ans << endl;
    }
    return 0;
}