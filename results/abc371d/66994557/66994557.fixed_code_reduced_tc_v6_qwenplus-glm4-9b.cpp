#include<bits/stdc++.h>
using namespace std;
int n, q, x[200005], p[200005];
int sum[200005];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        sum[i] = sum[i - 1] + p[i];
    }
    cin >> q;
    while (q--) {
        int L, R;
        cin >> L >> R;
        int l = lower_bound(x, x + n, L) - x;
        int r = upper_bound(x, x + n, R) - x;
        if (l == 0) {
            cout << sum[r - 1] << endl;
        } else {
            cout << sum[r - 1] - sum[l - 1] << endl;
        }
    }
    return 0;
}