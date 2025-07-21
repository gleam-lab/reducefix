#include<bits/stdc++.h>
using namespace std;
using LL = __int128;
typedef long long ll;
const int N = 2e5 + 7;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, q;
    cin >> n;
    vector<int> x(n + 1, 0), p(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }

    vector<LL> prefix_sum(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        prefix_sum[i] = prefix_sum[i - 1] + p[i];
    }

    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        auto it_l = lower_bound(x.begin() + 1, x.end(), l);
        auto it_r = upper_bound(x.begin() + 1, x.end(), r);

        int idx_l = distance(x.begin(), it_l);
        int idx_r = distance(x.begin(), it_r);

        if (idx_r == 0 || idx_l > n || idx_r > n) {
            cout << "0\n";
        } else {
            cout << prefix_sum[min(idx_r - 1, n)] - prefix_sum[max(0, idx_l - 1)] << "\n";
        }
    }

    return 0;
}