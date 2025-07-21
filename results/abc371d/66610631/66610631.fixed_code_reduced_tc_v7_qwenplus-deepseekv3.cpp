#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n;
    vector<ll> a(n + 1), b(n + 1), c(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
        c[i] = c[i - 1] + b[i];
    }
    
    cin >> m;
    while (m--) {
        ll l, r;
        cin >> l >> r;
        auto l_it = lower_bound(a.begin() + 1, a.end(), l);
        auto r_it = upper_bound(a.begin() + 1, a.end(), r);
        
        int l_idx = l_it - a.begin();
        int r_idx = r_it - a.begin();
        
        if (l_idx > r_idx) {
            cout << "0\n";
        } else {
            ll sum = c[r_idx - 1] - c[l_idx - 1];
            cout << sum << '\n';
        }
    }
    
    return 0;
}