#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<int> x(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }
    vector<ll> p(n);
    vector<ll> prefix(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        prefix[i + 1] = prefix[i] + p[i];
    }
    
    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        int lt = lower_bound(x.begin(), x.end(), l) - x.begin();
        int rt = upper_bound(x.begin(), x.end(), r) - x.begin();
        ll ans = prefix[rt] - prefix[lt];
        cout << ans << '\n';
    }
    
    return 0;
}