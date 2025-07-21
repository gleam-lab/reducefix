#include <iostream>
#include <vector>

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
    
    // Sort toys and boxes in descending order
    sort(toys.begin(), toys.end(), greater<int>());
    sort(boxes.begin(), boxes.end(), greater<int>());

    // Initialize the minimum box size `x`
    int x = 0;
    
    // Check if each toy can fit into a box
    for (int i = 0; i < n; ++i) {
        if (toys[i] > boxes[i]) {
            int l = i - 1, r = i, m;
            // Binary search for the smallest box that can fit the toy
            while (l < r) {
                m = (l + r + 1) / 2;
                if (toys[i] <= boxes[m]) {
                    r = m - 1;
                } else {
                    l = m;
                }
            }
            // If no box can fit the toy, print `-1`
            if (l == -1) {
                cout << -1 << endl;
                return 0;
            }
            x = max(x, boxes[l]);
        }
    }
    
    // Output the minimum box size `x`
    cout << x << endl;
    return 0;
}