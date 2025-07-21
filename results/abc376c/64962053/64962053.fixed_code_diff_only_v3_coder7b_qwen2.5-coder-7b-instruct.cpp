#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> va(n), vb(n);
    for(int i = 0; i < n; ++i)
        cin >> va[i];
    for(int i = 0; i < n - 1; ++i)
        cin >> vb[i];

    // Sort both arrays
    sort(va.begin(), va.end());
    sort(vb.begin(), vb.end());

    // Initialize the minimum box size to be the largest toy size
    long long minBoxSize = va[n - 1];

    // Iterate through the sorted box sizes
    for(int i = 0; i < n - 1; ++i) {
        // Check if the current box size can accommodate the current toy
        if(vb[i] >= va[i]) {
            // If yes, update the minimum box size if necessary
            minBoxSize = min(minBoxSize, (long long)vb[i]);
        } else {
            // If no, print -1 and return
            cout << -1 << endl;
            return 0;
        }
    }

    // Print the minimum box size required
    cout << minBoxSize << endl;
    return 0;
}