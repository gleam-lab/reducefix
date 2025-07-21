#include<bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n;
    vector<int> x(n + 2), p(n + 2);
    vector<long long> sum(n + 2, 0);
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        sum[i] = sum[i - 1] + p[i];
    }
    cin >> q;
    while (q--) {
        int L, R;
        cin >> L >> R;
        int l = lower_bound(x.begin() + 1, x.begin() + n + 1, L) - x.begin();
        int r = upper_bound(x.begin() + 1, x.begin() + n + 1, R) - x.begin();
        cout << sum[r - 1] - sum[l - 1] << '\n';
    }
    return 0;
}