#include<bits/stdc++.h>
using namespace std;

using LL = __int128_t;
typedef long long ll;

const int N = 1e6 + 7;
vector<LL> a(N), b(N), c(N);

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
        c[i] = b[i] + c[i - 1];
    }

    cin >> m;
    while (m--) {
        int l, r;
        cin >> l >> r;
        auto l_i = lower_bound(a.begin() + 1, a.begin() + n + 1, l);
        auto r_i = upper_bound(a.begin() + 1, a.begin() + n + 1, r);
        if (r_i == a.end() && l_i == a.begin() + 1) cout << c[n] << '\n';
        else if (r_i == a.end()) cout << c[n] - c[l_i - a.begin()] << '\n';
        else if (l_i == a.begin() + 1) cout << c[r_i - a.begin() - 1] << '\n';
        else cout << c[r_i - a.begin() - 1] - c[l_i - a.begin()] << '\n';
    }
    return 0;
}