#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> va(n), vb(n);
    for (int i = 0; i < n; i++)
        cin >> va[i];
    for (int i = 0; i < n - 1; i++)
        cin >> vb[i];

    // Sort toys and boxes in descending order
    sort(va.begin(), va.end(), greater<int>());
    sort(vb.begin(), vb.end(), greater<int>());

    // Check if the largest toy can fit in any of the available boxes
    for (int i = 0; i < n - 1; i++) {
        if (va[i] > vb[i]) {
            // If the current toy cannot fit in the current box, check the next box
            for (int j = i + 1; j < n - 1; j++) {
                if (va[i] <= vb[j]) {
                    // Found a valid box for the current toy
                    continue;
                } else {
                    // No valid box found for the current toy
                    cout << -1 << endl;
                    return 0;
                }
            }
        }
    }

    // If all toys can fit in their respective boxes, output the maximum toy size
    cout << va[n - 1] << endl;
    return 0;
}