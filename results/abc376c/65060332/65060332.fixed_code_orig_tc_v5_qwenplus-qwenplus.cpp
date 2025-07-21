#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 2e5 + 5;

ll a[N], b[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

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

    // Use multiset to handle multiple toys of same size efficiently
    multiset<ll> boxes;
    for (int i = 0; i < n - 1; ++i) {
        boxes.insert(b[i]);
    }

    // Try to place each toy in a suitable box
    for (int i = 0; i < n; ++i) {
        auto it = boxes.lower_bound(a[i]);
        if (it != boxes.end()) {
            boxes.erase(it); // Use this box
        } else {
            // No suitable box found, this must be the one we need the new box for
            cout << a[i] << endl;
            return 0;
        }
    }

    // If we placed all toys in existing boxes, we still need at least the largest toy size
    cout << a[n - 1] << endl;
    return 0;
}