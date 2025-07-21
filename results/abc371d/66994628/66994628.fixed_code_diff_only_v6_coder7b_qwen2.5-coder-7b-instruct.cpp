#include<bits/stdc++.h>
using namespace std;

const int MAXN = 200005;

int n, q, x[MAXN], p[MAXN];
long long sum[MAXN];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        sum[i] = sum[i - 1] + p[i];
    }
    
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        
        // Adjust indices to be zero-based for lower_bound and upper_bound
        auto it_l = lower_bound(x + 1, x + n + 1, l);
        auto it_r = upper_bound(x + 1, x + n + 1, r);
        
        // Calculate the range sum using prefix sums
        int pos_l = distance(x + 1, it_l);
        int pos_r = distance(x + 1, it_r) - 1;
        
        if (pos_l <= n && pos_r <= n) {
            cout << sum[pos_r] - sum[pos_l - 1] << endl;
        } else {
            cout << "Invalid range" << endl;
        }
    }
    return 0;
}