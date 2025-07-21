#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> va(n), vb(n-1);
    for(int i = 0; i < n; ++i) cin >> va[i];
    for(int i = 0; i < n-1; ++i) cin >> vb[i];

    sort(va.rbegin(), va.rend()); // Sort toys in descending order
    sort(vb.begin(), vb.end());    // Sort boxes in ascending order

    long long minBoxSize = -1; // Initialize with -1 as default (not found)

    // Iterate over each toy starting from the largest
    for(int i = 0; i < n; ++i) {
        // Find the first box that can fit this toy
        auto it = lower_bound(vb.begin(), vb.end(), va[i]);
        if(it != vb.end()) { // If a suitable box is found
            minBoxSize = *it; // Update the minimum box size needed
            break; // Exit loop as we found the minimum required box size
        }
    }

    cout << minBoxSize << endl; // Output the result

    return 0;
}