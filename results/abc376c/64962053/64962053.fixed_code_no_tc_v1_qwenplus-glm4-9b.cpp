#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> toys(n);
    vector<int> boxes(n - 1);
    
    for (int i = 0; i < n; ++i) {
        cin >> toys[i];
    }
    for (int i = 0; i < n - 1; ++i) {
        cin >> boxes[i];
    }

    // Sort the toy sizes and box sizes
    sort(toys.begin(), toys.end());
    sort(boxes.begin(), boxes.end());

    // We need to find the smallest possible size x that can be used to fit all toys
    // We start by checking the largest box size and try to fit all toys starting from the smallest
    if (toys[0] <= boxes[n - 2]) {
        // The smallest box size that can fit the smallest toy
        int min_box_size = toys[0];
        // Check if all toys can fit in boxes of size min_box_size or larger
        for (int i = 0; i < n; ++i) {
            if (toys[i] > min_box_size) {
                cout << -1 << endl;
                return 0;
            }
        }
        cout << min_box_size << endl;
    } else {
        // If the largest box size cannot even fit the smallest toy, it's impossible
        cout << -1 << endl;
    }
    
    return 0;
}