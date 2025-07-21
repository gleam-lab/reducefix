#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> va(n), vb(n - 1);
    for (int i = 0; i < n; ++i)
        cin >> va[i];
    for (int i = 0; i < n - 1; ++i)
        cin >> vb[i];

    // Sort both arrays
    sort(va.begin(), va.end());
    sort(vb.begin(), vb.end());

    // Initialize the answer as -1
    int ans = -1;

    // Iterate through the toys and check if we can place them in the boxes
    for (int i = 0; i < n; ++i) {
        // If we can place the current toy in any of the existing boxes
        bool can_place = false;
        for (int j = 0; j < i; ++j) {
            if (vb[j] >= va[i]) {
                can_place = true;
                break;
            }
        }
        // If we cannot place the toy in any of the existing boxes
        if (!can_place) {
            // Check if we can place it in a new box
            if (i == 0 || va[i] > vb[i - 1]) {
                ans = va[i];
                break;
            }
        }
    }

    // Print the result
    cout << ans << endl;

    return 0;
}