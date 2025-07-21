#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n - 1);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n - 1; i++) {
        cin >> b[i];
    }

    // Sort toys and boxes in descending order
    sort(a.begin(), a.end(), greater<int>());
    sort(b.begin(), b.end(), greater<int>());

    // We need to find the smallest box that can accommodate all toys
    int minBoxSize = a[0]; // Start with the largest toy as the minimum box size
    for (int i = 0; i < n - 1; i++) {
        if (a[i] < b[i]) {
            minBoxSize = b[i];
        } else if (a[i] >= b[i] && b[i] < minBoxSize) {
            minBoxSize = b[i];
        }
    }

    // If the smallest box size is not possible, then print -1
    if (minBoxSize == a[0]) {
        cout << -1 << endl;
    } else {
        cout << minBoxSize << endl;
    }

    return 0;
}