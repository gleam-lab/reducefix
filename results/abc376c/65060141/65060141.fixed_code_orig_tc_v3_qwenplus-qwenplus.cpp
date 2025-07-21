#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 2e5 + 5;

ll a[N], b[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i < n; ++i) {
        cin >> b[i];
    }

    sort(a + 1, a + n + 1);
    sort(b + 1, b + n);

    multiset<ll> toys;
    for (int i = 1; i <= n; ++i) {
        toys.insert(a[i]);
    }

    ll required = 0;

    // Try to fit the largest toys into the largest boxes
    for (int i = n - 1; i >= 1; --i) {
        auto it = toys.upper_bound(b[i]);
        if (it != toys.begin()) {
            it--;
            toys.erase(it);
        } else {
            // Can't place any toy in this box, we'll need a new one
            required++;
        }
    }

    if (toys.empty()) {
        cout << -1 << endl;
        return 0;
    }

    if (required > 1) {
        cout << -1 << endl;
    } else {
        cout << *toys.begin() << endl;
    }

    return 0;
}