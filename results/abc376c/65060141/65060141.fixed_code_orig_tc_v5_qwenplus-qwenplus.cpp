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
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n - 1; ++i) {
        cin >> b[i];
    }

    sort(a, a + n);
    sort(b, b + n - 1);

    // We need to place all toys in boxes. One toy per box.
    // We can use one new box of size x.
    // Find minimal x such that this is possible.

    // Strategy:
    // Try to match largest toys with largest available boxes.
    // If a toy cannot fit in any existing box, we'll have to put it in the new box.
    // So we must find the smallest x that fits the largest unmatched toy.

    multiset<ll> boxes;
    for (int i = 0; i < n - 1; ++i) {
        boxes.insert(b[i]);
    }

    ll required_size = -1;

    for (int i = n - 1; i >= 0; --i) {
        ll toy = a[i];
        auto it = boxes.lower_bound(toy);
        if (it != boxes.end()) {
            // Found a box that can fit this toy
            boxes.erase(it);
        } else {
            // No suitable box found, we'll have to put this toy in our custom box
            if (required_size == -1) {
                required_size = toy;
            } else {
                // More than one toy needs our custom box -> impossible
                cout << -1 << endl;
                return 0;
            }
        }
    }

    if (required_size == -1) {
        // All toys could be placed in existing boxes
        cout << 1 << endl;
    } else {
        cout << required_size << endl;
    }

    return 0;
}