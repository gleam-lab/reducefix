#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200050;

int n, x[MAXN], p[MAXN], q, a[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> x[i];
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
        a[i] = a[i - 1] + p[i];
    }
    
    cin >> q;
    while (q--) {
        int l, r; cin >> l >> r;
        auto it1 = lower_bound(x + 1, x + n + 1, l);
        auto it2 = upper_bound(x + 1, x + n + 1, r);
        
        if (it1 == x + n + 1) --it1;
        if (it2 == x + n + 1) --it2;
        
        cout << a[it2->second] - a[it1->second - 1] << '\n';
    }

    return 0;
}