#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2 * 100005;
int n, q, x[MAXN], p[MAXN];
long long sum[MAXN];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> p[i];
        sum[i] = sum[i - 1] + p[i];
    }
    
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        
        // Find the first position where x[i] >= l
        auto it_l = lower_bound(x + 1, x + n + 1, l);
        if (it_l == x + n + 1 || *it_l != l) {
            it_l--;
        }
        
        // Find the last position where x[i] <= r
        auto it_r = upper_bound(x + 1, x + n + 1, r);
        if (it_r == x + n + 1) {
            it_r--;
        }
        
        int idx_l = it_l - x;
        int idx_r = it_r - x;
        
        cout << sum[idx_r] - sum[idx_l - 1] << endl;
    }

    return 0;
}