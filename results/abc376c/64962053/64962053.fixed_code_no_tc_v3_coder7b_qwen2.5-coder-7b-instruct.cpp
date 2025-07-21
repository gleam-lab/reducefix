#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> va(n), vb(n);
    for (int i = 0; i < n; ++i)
        cin >> va[i];
    for (int i = 0; i < n - 1; ++i)
        cin >> vb[i];

    // Sort both arrays
    sort(va.begin(), va.end());
    sort(vb.begin(), vb.end());

    // Initialize the minimum box size needed
    int min_box_size = 0;

    // Iterate through toys and check if they can fit in any available box
    for (int i = 0; i < n; ++i) {
        bool found = false;
        for (int j = 0; j < n - 1; ++j) {
            if (vb[j] >= va[i]) {
                vb[j] = -1; // Mark this box as used
                found = true;
                break;
            }
        }
        if (!found) {
            // If no box can accommodate the current toy, calculate the new box size
            min_box_size = max(min_box_size, va[i]);
        }
    }

    // Check if we need to buy a new box
    if (min_box_size > 0) {
        cout << min_box_size << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}