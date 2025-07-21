#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> va(n), vb(n);
    for (int i = 0; i < n; ++i) {
        cin >> va[i];
    }
    for (int i = 0; i < n - 1; ++i) {
        cin >> vb[i];
    }

    // We need to find the minimum x that can be used to place all toys.
    // The smallest such x will be the size of the largest toy that needs to fit into a box.
    // We will iterate over all toys and find the maximum size of the box that can contain the toy.
    int max_box_size = 0;
    for (int i = 0; i < n; ++i) {
        int max_box_size_for_toy = 0;
        // Check all existing boxes to find the largest one that can fit the current toy.
        for (int j = 0; j < n - 1; ++j) {
            if (vb[j] >= va[i]) {
                max_box_size_for_toy = max(max_box_size_for_toy, vb[j]);
            }
        }
        // The toy itself may be the largest box that can fit it.
        max_box_size_for_toy = max(max_box_size_for_toy, va[i]);
        // Update the minimum box size needed for all toys.
        max_box_size = max(max_box_size, max_box_size_for_toy);
    }

    // If the maximum box size needed for any toy is more than the largest existing box,
    // we need to buy a new box of that size or larger.
    if (max_box_size <= vb[n - 1]) {
        // If the maximum size is within the range of existing boxes, we can use one of them.
        cout << vb[n - 1] << endl;
    } else {
        // Otherwise, we need to buy a new box of exactly that size.
        cout << max_box_size << endl;
    }
}