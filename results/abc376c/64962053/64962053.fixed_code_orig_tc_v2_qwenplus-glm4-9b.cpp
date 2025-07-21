#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> toys(n), boxes(n - 1);
    for (int i = 0; i < n; ++i) {
        cin >> toys[i];
    }
    for (int i = 0; i < n - 1; ++i) {
        cin >> boxes[i];
    }
    
    // Sort the toys and boxes
    sort(toys.begin(), toys.end());
    sort(boxes.begin(), boxes.end());
    
    int min_box_size = 0;
    bool impossible = false;

    // Try to fit the largest toy in a box
    for (int i = 0; i < n - 1; ++i) {
        if (boxes[i] >= toys[n - 1]) {
            min_box_size = toys[n - 1];
            break;
        }
    }
    
    // If the largest toy can't be placed in any box, set the flag to true
    if (min_box_size == 0) {
        impossible = true;
    } else {
        // Check if all other toys can fit in the boxes
        bool toy_placed[n];
        fill_n(toy_placed, n, false);
        for (int i = 0; i < n - 1; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!toy_placed[j] && toys[j] <= boxes[i]) {
                    toy_placed[j] = true;
                    break;
                }
            }
        }

        // If there is a toy that can't be placed in any box, set the flag to true
        for (int i = 0; i < n; ++i) {
            if (!toy_placed[i]) {
                impossible = true;
                break;
            }
        }
    }
    
    // Output the result
    if (impossible) {
        cout << -1 << endl;
    } else {
        cout << min_box_size << endl;
    }
    
    return 0;
}