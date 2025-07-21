#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n - 1);

    // Read the sizes of the toys
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    // Read the sizes of the boxes
    for (int i = 0; i < n - 1; ++i)
        cin >> b[i];

    // Sort the toys and boxes in descending order
    sort(a.begin(), a.end(), greater<int>());
    sort(b.begin(), b.end(), greater<int>());

    // Find the smallest box size that can accommodate the largest toy
    int minBoxSize = -1;
    for (int i = 0; i < n - 1; ++i) {
        if (a[i] <= b[i]) {
            minBoxSize = max(minBoxSize, b[i]);
        } else {
            minBoxSize = -1;
            break;
        }
    }

    // If no suitable box is found, check if the last toy can fit in any box
    if (minBoxSize == -1 && a[n - 1] <= b[n - 2]) {
        minBoxSize = b[n - 2];
    }

    // Print the result
    cout << minBoxSize << endl;

    return 0;
}