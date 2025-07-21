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
    
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    int left = 0, right = 0;
    int next_b = b[0]; // Start with the first box size
    
    while (left < n) {
        if (right == n - 1 || b[right + 1] < a[left]) {
            // If we reach the end of box sizes or the next box is too small, we need to increase the box size
            next_b = a[left];
            right = -1; // Reset the right pointer
        }
        // Move the right pointer forward if the box size is large enough for the current toy
        while (right < n - 1 && b[right + 1] >= a[left]) {
            right++;
        }
        // Move the left pointer forward to place the current toy
        left++;
    }
    
    // The minimum box size x is the maximum of all box sizes we encountered
    cout << next_b << endl;
    return 0;
}