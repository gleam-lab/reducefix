#include <bits/stdc++.h>
using namespace std;

int n, q;
vector<int> x, p, sum;

int main() {
    cin >> n;
    x.resize(n + 1);
    p.resize(n + 1);
    sum.resize(n + 1);

    for (int i = 1; i <= n; ++i) {
        cin >> x[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
        sum[i] = sum[i - 1] + p[i];
    }

    cin >> q;
    while (q--) {
        int L, R;
        cin >> L >> R;

        // Adjust indices for 1-based to 0-based
        int l = lower_bound(x.begin() + 1, x.end(), L) - x.begin();
        int r = upper_bound(x.begin() + 1, x.end(), R) - x.begin();

        if (l > r) {
            cout << "0" << endl;
        } else {
            cout << sum[r - 1] - sum[l - 1] << endl;
        }
    }

    return 0;
}