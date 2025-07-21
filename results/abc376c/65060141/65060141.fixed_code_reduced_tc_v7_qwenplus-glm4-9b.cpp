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
    
    // Sort toy sizes and box sizes
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    // Use a two-pointer technique to find the minimum box size x
    int left = 0, right = n - 2;  // right starts at n-2 because we need at least one box to fit the last toy
    int min_box_size = 1;
    
    while (left <= right) {
        if (a[right] <= b[left]) {
            // If the largest toy can fit the smallest available box, we can potentially use just this box
            if (right == 0) {
                // If it's the first toy, we need at least this box size because we can't use the existing boxes to fit it
                min_box_size = max(min_box_size, a[right]);
            }
            left++;  // Move to the next toy
        } else {
            // If the largest toy cannot fit the smallest available box, we need to increase the minimum box size
            min_box_size = max(min_box_size, a[right]);
            right--;  // Consider the next smallest box
        }
    }
    
    // Check if we have considered all toys
    if (left == n) {
        cout << min_box_size << endl;
    } else {
        cout << -1 << endl;
    }
    
    return 0;
}