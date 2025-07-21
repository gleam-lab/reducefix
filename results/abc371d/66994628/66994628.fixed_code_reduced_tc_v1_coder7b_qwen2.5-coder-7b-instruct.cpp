#include<bits/stdc++.h>
using namespace std;

int n, q, x[200005], p[200005], sum[200005];

int main() {
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> x[i];
    }
    for(int i = 1; i <= n; ++i) {
        cin >> p[i];
        sum[i] = sum[i-1] + p[i];
    }
    cin >> q;
    while(q--) {
        int l, r;
        cin >> l >> r;
        auto it_l = lower_bound(x + 1, x + n + 1, l);
        auto it_r = upper_bound(x + 1, x + n + 1, r);
        int idx_l = distance(x + 1, it_l);
        int idx_r = distance(x + 1, it_r);
        if(idx_l > 0 && idx_r <= n) {
            cout << sum[idx_r] - sum[idx_l - 1] << endl;
        } else if(idx_l == 0 && idx_r <= n) {
            cout << sum[idx_r] << endl;
        } else if(idx_l > 0 && idx_r > n) {
            cout << sum[n] - sum[idx_l - 1] << endl;
        } else {
            cout << "0" << endl;
        }
    }
    return 0;
}