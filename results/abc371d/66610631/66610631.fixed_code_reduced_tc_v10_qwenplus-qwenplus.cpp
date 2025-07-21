#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e6 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    
    vector<ll> a(n + 1, 0), b(n + 1, 0), prefix_sum(n + 1, 0);
    
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
        prefix_sum[i] = prefix_sum[i - 1] + b[i];
    }

    int m;
    cin >> m;
    
    while (m--) {
        ll l, r;
        cin >> l >> r;
        
        // Find first index where a[i] >= l
        auto left = lower_bound(a.begin() + 1, a.end(), l);
        // Find first index where a[i] > r
        auto right = upper_bound(a.begin() + 1, a.end(), r);
        
        int left_idx = distance(a.begin(), left);
        int right_idx = distance(a.begin(), right);
        
        // Sum of b[i] from left_idx to right_idx - 1
        if (right_idx == 0 || left_idx == n + 1) {
            cout << 0 << "\n";
        } else {
            cout << prefix_sum[right_idx - 1] - prefix_sum[left_idx - 1] << "\n";
        }
    }

    return 0;
}