#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 7;

int main() {
    int n, m;
    cin >> n;
    vector<int> a(n+1), b(n+1), c(n+1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
    }
    for (int i = 1; i <= n; ++i) {
        c[i] = c[i-1] + b[i];  // Calculate cumulative sum of b
    }

    cin >> m;
    while (m--) {
        int l, r;
        cin >> l >> r;
        auto l_i = lower_bound(a.begin() + 1, a.end() + 1, l); // +1 to match vector indexing
        auto r_i = upper_bound(a.begin() + 1, a.end() + 1, r); // +1 to match vector indexing

        if (r_i == a.end() && l_i == a.begin() + 1) {
            cout << c[n] << endl;
        } else if (r_i == a.end()) {
            cout << c[n] - c[l_i - a.begin() - 1] << endl;
        } else if (l_i == a.begin() + 1) {
            cout << c[r_i - a.begin() - 1] << endl;
        } else {
            cout << c[r_i - a.begin() - 1] - c[l_i - a.begin() - 1] << endl;
        }
    }
    return 0;
}