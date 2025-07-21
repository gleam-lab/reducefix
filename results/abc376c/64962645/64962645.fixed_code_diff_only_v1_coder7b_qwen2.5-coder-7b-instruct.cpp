#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> va(n), vb(n - 1);
    for (int i = 0; i < n; i++) cin >> va[i];
    for (int i = 0; i < n - 1; i++) cin >> vb[i];

    // Sort the toys and boxes in descending order
    sort(va.begin(), va.end(), greater<int>());
    sort(vb.begin(), vb.end(), greater<int>());

    // Initialize the maximum box size needed
    int maxBoxSize = 0;

    // Iterate through the toys and boxes
    for (int i = 0; i < n; i++) {
        // Check if the current toy can fit in the current box
        if (va[i] <= vb[i]) {
            continue;
        }
        // If not, calculate the additional box size needed
        maxBoxSize = max(maxBoxSize, va[i]);
    }

    // If no additional box was needed, the maximum box size is 0
    if (maxBoxSize == 0) {
        cout << "0" << endl;
    } else {
        cout << maxBoxSize << endl;
    }

    return 0;
}