#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n - 1);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n - 1; ++i) {
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int i = 0, j = 0;
    int count = 0;
    int x_candidate = -1;

    while (i < n && j < n - 1) {
        if (a[i] <= b[j]) {
            ++i;
            ++j;
        } else {
            if (x_candidate == -1) {
                x_candidate = a[i];
                ++i;
            } else {
                // More than one toy needs a new box, impossible.
                cout << -1 << endl;
                return 0;
            }
        }
    }

    if (i < n) {
        if (x_candidate == -1) {
            x_candidate = a.back();
        } else {
            // More than one toy needs a new box, impossible.
            cout << -1 << endl;
            return 0;
        }
    }

    if (x_candidate == -1) {
        // All toys fit in existing boxes, but we need one more box.
        // The new box can be as small as the smallest toy not placed (but all are placed).
        // So the new box can be any size >= some toy not in boxes, but all are placed.
        // This scenario is unclear; perhaps the problem implies x must be used.
        // Alternatively, perhaps if all toys fit in N-1 boxes, x is not needed, but the problem requires placing in N boxes.
        // So in this case, it's impossible because we have N toys and N boxes, but existing boxes are N-1. So x must be used, but all toys fit in N-1 boxes, which would leave one box empty, which is not allowed.
        cout << -1 << endl;
    } else {
        cout << x_candidate << endl;
    }

    return 0;
}