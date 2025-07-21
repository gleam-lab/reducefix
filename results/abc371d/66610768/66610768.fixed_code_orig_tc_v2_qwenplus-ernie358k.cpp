#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
const int N = 1e6 + 7;

int main() {
    int n, m;
    cin >> n;
    vector<ll> a(n), b(n), c(n + 1, 0);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> b[i];
        c[i + 1] = c[i] + b[i];
    }

    cin >> m;
    while (m--) {
        ll l, r;
        cin >> l >> r;
        auto it_l = lower_bound(a.begin(), a.end(), l);
        auto it_r = upper_bound(a.begin(), a.end(), r);
        ll sum = (it_r != a.end()) ? c[it_r - a.begin()] - c[it_l - a.begin()] : c[n] - c[it_l - a.begin()];
        cout << sum << endl;
    }

    return 0;
}