#include<bits/stdc++.h>
using namespace std;
int n, q, x[200005], p[200005];
map<int, int> sum;
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        // Correct this line to ensure that if p[i] is 0, the sum is still correct.
        sum[i] = (i == 1) ? p[i] : sum[i - 1] + p[i];
    }
    cin >> q;
    while (q--) {
        int L, R;
        cin >> L >> R;
        int c = lower_bound(x + 1, x + n + 1, L) - x;
        int d = upper_bound(x + 1, x + n + 1, R) - x;
        if (c > d) {
            cout << "0\n";
        } else {
            cout << sum[d - 1] - (c > 1 ? sum[c - 2] : 0) << "\n";
        }
    }
    return 0;
}