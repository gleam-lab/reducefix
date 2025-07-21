#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 2e5+7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<LL> a(n+2), b(n+2), prefix_sum(n+2, 0);
    
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
        prefix_sum[i] = prefix_sum[i-1] + b[i];
    }

    int m;
    cin >> m;
    while (m--) {
        LL l, r;
        cin >> l >> r;

        // Find first index where a[i] >= l using lower_bound
        auto left = lower_bound(a.begin() + 1, a.end(), l);
        // Find first index where a[i] > r using upper_bound
        auto right = upper_bound(a.begin() + 1, a.end(), r);

        int li = left - a.begin();
        int ri = right - a.begin();

        // Output the sum of b's corresponding to the range in a that is [li, ri-1]
        cout << (prefix_sum[ri - 1] - prefix_sum[li - 1]) << '\n';
    }

    return 0;
}