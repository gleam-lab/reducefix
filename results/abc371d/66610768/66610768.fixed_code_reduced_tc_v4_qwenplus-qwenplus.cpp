#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e6 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<ll> a(n + 1, 0), b(n + 1, 0), c(n + 1, 0);
    
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
        c[i] = c[i - 1] + b[i];
    }

    int m;
    cin >> m;
    while (m--) {
        int l, r;
        cin >> l >> r;

        // Find first index where a[i] >= l
        int left_idx = lower_bound(a.begin() + 1, a.end(), l) - a.begin();
        
        // Find first index where a[i] > r
        int right_idx = upper_bound(a.begin() + 1, a.end(), r) - a.begin();

        // Sum of b values from [left_idx, right_idx - 1]
        cout << c[right_idx - 1] - c[left_idx - 1] << '\n';
    }

    return 0;
}