#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    // We use a two-pointer technique to find the best subarray to remove.
    // We want to minimize the max-min difference, so we should aim to keep the
    // middle values of the array by removing the extreme values (either very small or very large).
    
    // Initialize pointers for the range of elements to consider removing.
    int left = 0, right = n - 1;

    // We will remove elements from both ends of the array, as removing from the middle
    // would not help in minimizing the max-min difference within the remaining elements.
    while (k > 0) {
        // Decide whether to remove from the left or right side based on which side has
        // the larger difference between its minimum and maximum values.
        if (k % 2 == 1) { // If k is odd, we need to remove an element from the middle.
            if (v[right] - v[left] <= v[right - 1] - v[left + 1]) {
                right--;
            } else {
                left++;
            }
            k--;
        }
        // Remove elements from the side with the larger difference.
        if (left + 1 <= right && v[right] - v[left] <= v[right - 1] - v[left + 1]) {
            right--;
        } else {
            left++;
        }
        k--;
    }

    // Calculate the difference between the maximum and minimum of the remaining elements.
    cout << v[right] - v[left];
    return 0;
}