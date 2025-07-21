#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2 * 100050;

int n, x[MAXN], p[MAXN], q, a[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> x[i];
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
        a[i] = a[i - 1] + p[i];
    }

    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        
        // Find the first index where x[index] >= l
        int left = lower_bound(x + 1, x + n + 1, l) - x;
        
        // Find the first index where x[index] > r
        int right = upper_bound(x + 1, x + n + 1, r) - x;
        
        cout << a[right - 1] - a[left - 1] << endl;
    }

    return 0;
}