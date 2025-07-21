#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, q;
int x[200005];
int p[200005];
ll sum[200005];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        sum[i] = sum[i-1] + p[i];
    }
    cin >> q;
    while (q--) {
        int l_query, r_query;
        cin >> l_query >> r_query;
        int l_idx = lower_bound(x + 1, x + n + 1, l_query) - x;
        int r_idx = upper_bound(x + 1, x + n + 1, r_query) - x;
        if (l_idx > r_idx) {
            cout << 0 << endl;
        } else {
            cout << sum[r_idx - 1] - sum[l_idx - 1] << endl;
        }
    }
    return 0;
}