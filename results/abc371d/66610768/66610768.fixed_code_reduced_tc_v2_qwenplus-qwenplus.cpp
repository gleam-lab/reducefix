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
        int l, r;
        cin >> l >> r;

        // Find the first index in a >= l using lower_bound
        auto left = lower_bound(a.begin() + 1, a.end(), l);
        int i = left - a.begin();

        // Find the last index in a <= r using upper_bound
        auto right = upper_bound(a.begin() + 1, a.end(), r);
        int j = right - a.begin() - 1;

        if (i > j) {
            cout << 0 << '\n';
        } else {
            cout << prefix_sum[j] - prefix_sum[i - 1] << '\n';
        }
    }

    return 0;
}