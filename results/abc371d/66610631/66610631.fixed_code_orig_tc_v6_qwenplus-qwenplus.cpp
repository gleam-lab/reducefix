#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 2e6 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

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

        // Find the first index where a[i] >= l using lower_bound
        auto left = lower_bound(a.begin() + 1, a.end(), l);
        int left_idx = distance(a.begin(), left);

        // Find the first index where a[i] > r using upper_bound
        auto right = upper_bound(a.begin() + 1, a.end(), r);
        int right_idx = distance(a.begin(), right) - 1;

        if (right_idx < left_idx) {
            cout << 0 << '\n';
        } else {
            cout << prefix_sum[right_idx] - prefix_sum[left_idx - 1] << '\n';
        }
    }

    return 0;
}