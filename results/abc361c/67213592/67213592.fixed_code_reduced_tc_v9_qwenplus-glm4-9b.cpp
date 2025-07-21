#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    
    // Sort the array
    sort(v.begin(), v.end());

    int best = INT_MAX;
    int left = 0;
    int right = 0;

    // Iterate over the array with the right pointer
    while (right + k <= n) {
        // This is our current window of size n - k
        // Now, we need to find the minimum difference between the max and min within this window
        int min_diff = v[right + k - 1] - v[left];

        // Now, we need to slide the window to the right
        // We can slide the window until we are at the end of the array
        while (right + k <= n) {
            // Update the minimum difference
            min_diff = min(min_diff, v[right + k - 1] - v[left]);

            // Slide the window to the right
            left++;
            right++;
        }

        // Save the best minimum difference found
        best = min(best, min_diff);

        // Move to the next window
        left++;
        right++;
        if (right + k > n) {
            break;
        }
    }

    cout << best << endl;
    return 0;
}