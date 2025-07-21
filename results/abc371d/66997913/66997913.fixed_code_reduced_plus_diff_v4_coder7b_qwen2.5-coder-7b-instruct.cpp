#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<long long> x(n);
    for (int i = 0; i < n; i++) cin >> x[i];
    vector<long long> p(n), s(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        s[i + 1] = s[i] + p[i];
    }

    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        auto itl = lower_bound(x.begin(), x.end(), l);
        auto itr = upper_bound(x.begin(), x.end(), r);
        long long ans = s[itr - x.begin()] - s[itl - x.begin()];
        cout << ans << '\n';
    }

    return 0;
}