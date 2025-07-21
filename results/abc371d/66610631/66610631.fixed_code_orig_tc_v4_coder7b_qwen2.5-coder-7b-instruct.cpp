#include<bits/stdc++.h>
using namespace std;
using LL = __int128;
typedef long long ll;
const int N = 1e6 + 7;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n;
    vector<LL> a(n + 1, 0), b(n + 1, 0), c(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        b[i] = b[i - 1] + a[i];
        c[i] = c[i - 1] + b[i];
    }
    cin >> m;
    while (m--) {
        int l, r;
        cin >> l >> r;
        auto l_i = lower_bound(b.begin() + 1, b.end(), l) - b.begin();
        auto r_i = upper_bound(b.begin() + 1, b.end(), r) - b.begin();
        if (r_i == b.size() && l_i == 1) cout << c[n] << '\n';
        else if (r_i == b.size()) cout << c[n] - c[l_i - 1] << '\n';
        else if (l_i == 1) cout << c[r_i - 1] << '\n';
        else cout << c[r_i - 1] - c[l_i - 1] << '\n';
    }
    return 0;
}