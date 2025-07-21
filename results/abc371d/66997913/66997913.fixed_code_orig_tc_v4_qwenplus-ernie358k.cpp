#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<int> x(n);
    for (int i = 0; i < n; i++) cin >> x[i];
    vector<ll> p(n), s(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        s[i + 1] = s[i] + p[i];
    }
    
    vector<int> sorted_x = x;
    sort(sorted_x.begin(), sorted_x.end());
    
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        
        auto it_l = lower_bound(sorted_x.begin(), sorted_x.end(), l);
        auto it_r = upper_bound(sorted_x.begin(), sorted_x.end(), r);
        
        int idx_l = it_l - sorted_x.begin();
        int idx_r = it_r - sorted_x.begin();
        
        // Since we used upper_bound, idx_r points to one past the last element in range, adjust accordingly.
        if (idx_r < n && sorted_x[idx_r] == r) idx_r--;
        
        // idx_l and idx_r are now 0-based indices in the original array x.
        // We need to find the corresponding indices in p (which is the same as in x since they are parallel arrays).
        ll ans = s[idx_r + 1] - s[idx_l];
        cout << ans << endl;
    }
    return 0;
}