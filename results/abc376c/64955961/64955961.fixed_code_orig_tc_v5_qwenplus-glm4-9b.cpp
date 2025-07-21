#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n-1);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n-1; i++) cin >> b[i];

    int x = 1; // Minimum box size to be purchased
    for (int i = 0; i < n; i++) {
        // Check if the current toy size can fit into the smallest available box
        if (a[i] <= x) {
            x++;
        } else {
            // Update the box size to be at least the size of the current toy
            x = a[i];
        }

        // Check if the current toy size can fit into any of the existing boxes
        for (int j = 0; j < n-1; j++) {
            if (a[i] <= b[j]) {
                // Update the box size to be the maximum of the current and this existing box size
                x = max(x, b[j]);
                break;
            }
        }
    }

    // If x is still 1 after all toys have been processed, print -1 (indicating that no valid box size exists)
    if (x == 1) cout << -1 << endl;
    else cout << x << endl;

    return 0;
}