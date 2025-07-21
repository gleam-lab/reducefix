#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, q;
    cin >> n;
    vector<int> x(n + 1), p(n + 1);
    vector<long long> sum(n + 1, 0);
    
    for (int i = 1; i <= n; ++i) {
        cin >> x[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
        sum[i] = sum[i - 1] + p[i];
    }
    
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        
        int l_pos = lower_bound(x.begin() + 1, x.end(), l) - x.begin();
        int r_pos = upper_bound(x.begin() + 1, x.end(), r) - x.begin();
        
        if (l_pos > n || r_pos <= 1 || l_pos >= r_pos) {
            cout << 0 << '\n';
        } else {
            cout << sum[r_pos - 1] - sum[l_pos - 1] << '\n';
        }
    }
    
    return 0;
}