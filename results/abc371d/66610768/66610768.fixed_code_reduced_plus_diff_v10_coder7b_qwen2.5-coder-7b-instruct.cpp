#include<bits/stdc++.h>
using namespace std;
using LL = __int128;
typedef long long ll;
const int N = 1e6 + 7;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n;
    vector<LL> a(n + 1, 0), b(n + 1, 0), c(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        c[i] = c[i - 1] + b[i];
    }
    cin >> m;
    while (m--) {
        int l, r;
        cin >> l >> r;
        if (l > r) swap(l, r);
        auto l_i = lower_bound(a.begin() + 1, a.begin() + n + 1, l);
        auto r_j = upper_bound(a.begin() + 1, a.begin() + n + 1, r);
        int i = l_i - a.begin();
        int j = r_j - a.begin();
        if (i == 0 && j == n + 1) {
            cout << c.back() << '\n';
        } else if (i == 0) {
            cout << c[j - 1] << '\n';
        } else if (j == n + 1) {
            cout << c.back() - c[i - 1] << '\n';
        } else {
            cout << c[j - 1] - c[i - 1] << '\n';
        }
    }
    return 0;
}