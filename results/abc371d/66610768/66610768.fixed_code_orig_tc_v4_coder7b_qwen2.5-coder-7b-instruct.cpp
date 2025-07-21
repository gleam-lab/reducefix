#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 7;
vector<long long> prefix_sum(MAXN, 0);

long long query(int l, int r) {
    return prefix_sum[r] - prefix_sum[l - 1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, q;
    cin >> n >> q;
    
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
        prefix_sum[i] = prefix_sum[i - 1] + b[i];
    }
    
    while (q--) {
        int l, r;
        cin >> l >> r;
        
        auto it_l = lower_bound(a.begin() + 1, a.begin() + n + 1, l);
        auto it_r = upper_bound(a.begin() + 1, a.begin() + n + 1, r);
        
        int idx_l = it_l - a.begin();
        int idx_r = it_r - a.begin();
        
        if (idx_r > n) idx_r = n;
        
        if (idx_l == idx_r) {
            cout << prefix_sum[idx_r] - prefix_sum[idx_l - 1] << '\n';
        } else {
            cout << prefix_sum[idx_r - 1] - prefix_sum[idx_l - 1] << '\n';
        }
    }
    
    return 0;
}