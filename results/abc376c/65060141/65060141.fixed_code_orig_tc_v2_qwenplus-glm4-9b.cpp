#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n - 1);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n - 1; ++i) cin >> b[i];
    
    // Sort the toy sizes and the box sizes
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    int max_box_size = 0;
    bool all_placed = true;
    
    for (int i = 0; i < n; ++i) {
        if (i > 0 && b[i] < a[i]) {
            // If the current box size is smaller, check the next box
            if (i < n - 1 && b[i + 1] >= a[i]) {
                // Update the maximum box size that can fit this toy
                max_box_size = max(max_box_size, b[i + 1]);
                // Remove the current box from consideration for the next toys
                ++i;
            } else {
                // No box can fit this toy, all toys cannot be placed
                all_placed = false;
                break;
            }
        }
        // If the current box is large enough, move to the next toy
    }
    
    if (all_placed) {
        cout << max_box_size << endl;
    } else {
        cout << -1 << endl;
    }
    
    return 0;
}