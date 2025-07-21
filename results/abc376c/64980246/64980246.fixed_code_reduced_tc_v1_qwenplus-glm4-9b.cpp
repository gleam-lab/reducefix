#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n - 1);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n - 1; ++i) {
        cin >> b[i];
    }

    // Sort toy sizes in descending order and box sizes in descending order
    sort(a.begin(), a.end(), greater<int>());
    sort(b.begin(), b.end(), greater<int>());

    // Minimum size box to be bought to fit the largest toy that cannot fit in the boxes
    int minBoxSize = 0;

    // Find the first toy that cannot fit in any of the existing boxes
    for (int i = 0; i < n; ++i) {
        bool canFit = false;
        for (int j = 0; j < n - 1; ++j) {
            if (b[j] >= a[i]) {
                canFit = true;
                break;
            }
        }
        if (!canFit) {
            minBoxSize = a[i];
            break;
        }
    }

    // If no toy was too large for existing boxes, no new box is needed
    if (minBoxSize == 0) {
        cout << -1 << endl;
    } else {
        // Check if we can fit the toy that requires the largest box in the largest box
        bool canFit = false;
        for (int i = 0; i < n - 1; ++i) {
            if (b[i] >= minBoxSize) {
                canFit = true;
                break;
            }
        }
        if (canFit) {
            cout << minBoxSize << endl;
        } else {
            // If the largest box is not big enough, we need to buy a larger box
            cout << a[0] << endl;
        }
    }

    return 0;
}