#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 2e5 + 5;

ll a[N], b[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n - 1; ++i) {
        cin >> b[i];
    }

    sort(a, a + n);
    sort(b, b + n - 1);

    // We need to find the minimum x such that we can assign all toys to boxes (including one new box)
    // Each toy must go to a box of size >= its size
    // Exactly one toy goes to the new box of size x

    // Try to fit n-1 toys into the existing boxes, largest toys into largest boxes
    // If we can't fit, then we need to put some toy in the new box

    multiset<ll> boxes;
    for (int i = 0; i < n - 1; ++i) {
        boxes.insert(b[i]);
    }

    int cnt = 0;
    ll needed_x = 0;

    // Try to place toys from largest to smallest
    for (int i = n - 1; i >= 0; --i) {
        auto it = boxes.upper_bound(a[i]);
        if (it != boxes.end()) {
            // Found a box big enough
            boxes.erase(it);
        } else {
            // No suitable box found, need a new box
            cnt++;
            needed_x = max(needed_x, a[i]);
        }
    }

    if (cnt > 1) {
        cout << -1 << endl;
    } else {
        cout << needed_x << endl;
    }

    return 0;
}