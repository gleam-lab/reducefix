#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<int> x(n);
    for (int i = 0; i < n; i++) cin >> x[i];
    vector<ll> p(n), s(n + 1, 0);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        s[i + 1] = s[i] + p[i];
    }
    
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        // Find the positions of l and r in the x array using lower_bound and upper_bound
        auto it_l = lower_bound(x.begin(), x.end(), l);
        auto it_r = upper_bound(x.begin(), x.end(), r);
        
        // Calculate the indices in the x array
        int idx_l = it_l - x.begin();
        int idx_r = it_r - x.begin();
        
        // If it_r is at the end of the vector, idx_r should be n (end of prefix sums array)
        if (it_r == x.end()) {
            idx_r = n;
        }
        
        // Calculate the sum of prefixes from idx_l (inclusive) to idx_r (exclusive)
        ll ans = s[idx_r] - s[idx_l];
        cout << ans << endl;
    }
    return 0;
}