#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n - 1);
    for (auto &tt : a)
        cin >> tt;
    for (auto &tt : b)
        cin >> tt;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    multiset<int> b_set(b.begin(), b.end());

    for (int i = 0; i < n; ++i) {
        auto it = b_set.lower_bound(a[i]);
        if (it != b_set.end()) {
            b_set.erase(it);
        } else {
            // This toy cannot fit in any existing box, must go to new box
            cout << a[i] << endl;
            return;
        }
    }

    // All toys fit in existing boxes, minimum x is 1 (though not used)
    cout << 1 << endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}