#include <bits/stdc++.h>
using namespace std;
using LL = long long;  // __int128 is not needed if values fit within long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<LL> a(n + 1), b(n + 1), prefix_b(n + 1, 0);
    
    // Read array a (sorted)
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    // Read array b and compute prefix sums of b
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
        prefix_b[i] = prefix_b[i - 1] + b[i];
    }

    int m;
    cin >> m;

    while (m--) {
        LL l, r;
        cin >> l >> r;

        // Use binary search to find the indices
        auto left = lower_bound(a.begin() + 1, a.end(), l);
        auto right = upper_bound(a.begin() + 1, a.end(), r);

        int left_idx = left - a.begin();
        int right_idx = right - a.begin();

        // Sum from b[left_idx] to b[right_idx - 1]
        if (left_idx <= right_idx - 1) {
            cout << prefix_b[right_idx - 1] - prefix_b[left_idx - 1] << "\n";
        } else {
            cout << "0\n";  // No elements in range
        }
    }

    return 0;
}