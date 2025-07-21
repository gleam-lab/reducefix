#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> va(n), vb(n);
    for (int i = 0; i < n; i++) cin >> va[i];
    for (int i = 0; i < n - 1; i++) cin >> vb[i];

    sort(va.begin(), va.end());
    sort(vb.begin(), vb.end());

    // Find the minimum box size required to fit the largest toy
    long long max_size_needed = va[n - 1]; // The largest toy must fit somewhere
    bool feasible = true;

    // Check if we can fit all toys in the existing boxes
    for (int i = 0; i < n - 1; i++) {
        if (vb[i] >= va[i]) continue;
        else if (vb[i] >= va[i + 1]) {
            max_size_needed = max(max_size_needed, va[i]);
        } else {
            feasible = false;
            break;
        }
    }

    if (!feasible) {
        cout << -1 << endl;
    } else {
        cout << max_size_needed << endl;
    }

    return 0;
}