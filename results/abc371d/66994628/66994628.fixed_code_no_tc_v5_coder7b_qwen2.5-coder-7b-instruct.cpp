#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2 * 100005;

int n, q, x[MAXN], p[MAXN];
long long sum[MAXN];

int main() {
    cin >> n;
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
        
        // Find the first index where x[i] >= l
        auto it_l = lower_bound(x + 1, x + n + 1, l);
        if (it_l == x + n + 1 || *it_l != l) --it_l; // If no such index exists, decrement to get the largest smaller index
        
        // Find the first index where x[i] > r
        auto it_r = upper_bound(x + 1, x + n + 1, r);
        if (it_r == x + n + 1) --it_r; // If no such index exists, decrement to get the largest smaller index
        
        // Calculate the result using prefix sums
        cout << sum[it_r->second] - sum[it_l->second] << endl;
    }

    return 0;
}