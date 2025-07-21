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
    int potential_box_sizes = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > b[i]) {
            potential_box_sizes = max(potential_box_sizes, a[i] - b[i]);
        }
    }
    if (potential_box_sizes > 0) {
        cout << potential_box_sizes << endl;
    } else {
        cout << -1 << endl;
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}