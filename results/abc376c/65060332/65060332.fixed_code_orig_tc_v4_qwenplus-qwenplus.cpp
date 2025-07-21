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
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n - 1; ++i) cin >> b[i];

    sort(a, a + n);
    sort(b, b + n - 1);

    // We need to assign toys to boxes such that each toy fits in its box.
    // We try to match largest toys with the largest possible boxes.
    // If we can't find a suitable box for a toy, we need to use the new box.

    ll required_size = 0;
    int used_boxes = 0;

    int j = n - 2; // index for boxes (0..n-2)
    for (int i = n - 1; i >= 0; --i) { // toys from largest to smallest
        if (j >= 0 && b[j] >= a[i]) {
            --j;
        } else {
            // Need to use the new box for this toy
            required_size = max(required_size, a[i]);
        }
    }

    cout << required_size << endl;

    return 0;
}