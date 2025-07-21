#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> toy_sizes(n);
    vector<int> box_sizes(n - 1);

    for (int i = 0; i < n; i++) {
        cin >> toy_sizes[i];
    }
    for (int i = 0; i < n - 1; i++) {
        cin >> box_sizes[i];
    }

    sort(toy_sizes.begin(), toy_sizes.end(), greater<int>());
    sort(box_sizes.begin(), box_sizes.end());

    int min_x = 0;
    bool possible = true;

    for (int i = 0; i < n; i++) {
        if (i < n - 1 && toy_sizes[i] > box_sizes[i]) {
            // If current toy size cannot be placed in any of the existing boxes
            min_x = toy_sizes[i];
            possible = false;
            break;
        }
        // Ensure we find the maximum box size that can contain the current toy size
        if (i > 0 && toy_sizes[i] <= box_sizes[i]) {
            min_x = max(min_x, box_sizes[i]);
        }
    }

    if (possible) {
        cout << min_x << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}