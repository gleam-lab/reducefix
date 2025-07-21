#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> toy_sizes(n);
    vector<int> box_sizes(n - 1);

    for (int i = 0; i < n; ++i) {
        cin >> toy_sizes[i];
    }

    for (int i = 0; i < n - 1; ++i) {
        cin >> box_sizes[i];
    }

    // Sort both vectors in descending order
    sort(toy_sizes.rbegin(), toy_sizes.rend());
    sort(box_sizes.rbegin(), box_sizes.rend());

    // Now we need to find the smallest x such that all toys can fit
    for (int i = 0; i < n - 1; ++i) {
        // Check if the current toy cannot fit in the current or previous box
        if (toy_sizes[i] > box_sizes[i]) {
            // We need to skip the previous box and use the next one
            continue;
        } else if (toy_sizes[i] > box_sizes[i + 1]) {
            // If the current toy cannot fit in the next box, we need to increase the box size
            cout << toy_sizes[i] << endl;
            return 0;
        }
    }

    // If all toys fit in the given boxes, the smallest x is the largest toy size
    cout << toy_sizes[0] << endl;
    return 0;
}