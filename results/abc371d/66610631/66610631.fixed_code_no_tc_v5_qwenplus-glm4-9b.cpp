#include<bits/stdc++.h>
using namespace std;
using LL = __int128;
typedef long long ll;
const int N = 1e6+7;

int main() {
    int n, m;
    cin >> n;
    vector<int> a(n+1, 0), b(n+1, 0), c(n+1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    for (int i = 1; i <= n; i++) {
        c[i] = c[i - 1] + b[i];  // Update the prefix sum
    }
    cin >> m;
    while (m--) {
        int l, r;
        cin >> l >> r;
        // Use upper_bound and lower_bound directly on vectors a and c
        auto l_a = lower_bound(a.begin(), a.end(), l);
        auto r_a = upper_bound(a.begin(), a.end(), r);
        auto l_c = lower_bound(c.begin(), c.end(), l);
        auto r_c = upper_bound(c.begin(), c.end(), r);

        // Calculate result using the prefix sums and bounds
        if (r_a == a.end() && l_a == a.begin()) {
            cout << c[n] << endl;
        } else if (r_a == a.end()) {
            cout << c[n] - *l_c << endl;
        } else if (l_a == a.begin()) {
            cout << *r_c << endl;
        } else {
            cout << *r_c - *l_c << endl;
        }
    }
    return 0;
}