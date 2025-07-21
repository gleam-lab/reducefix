#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> toys(n);
    vector<int> boxes(n - 1);

    // Read toy sizes and boxes sizes
    for (int i = 0; i < n; ++i) {
        cin >> toys[i];
    }
    for (int i = 0; i < n - 1; ++i) {
        cin >> boxes[i];
    }

    // Sort toy sizes and box sizes
    sort(toys.begin(), toys.end());
    sort(boxes.begin(), boxes.end());

    // Initialize the minimum box size needed
    int minBoxSize = 1;

    // Check if the smallest toy can fit into the smallest box
    if (toys[0] > boxes[0]) {
        // If not, find the smallest box size that can fit the smallest toy
        for (int i = 0; i < n - 1; ++i) {
            if (toys[0] <= boxes[i]) {
                minBoxSize = boxes[i] + 1;
                break;
            }
        }

        // If no box can fit the smallest toy, output -1
        if (minBoxSize == 1) {
            cout << -1 << endl;
            return 0;
        }
    }

    // Output the minimum box size
    cout << minBoxSize << endl;
    return 0;
}