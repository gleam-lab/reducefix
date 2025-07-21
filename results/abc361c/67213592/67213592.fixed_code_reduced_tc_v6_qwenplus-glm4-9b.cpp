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
    sort(v.begin(), v.end());

    // Calculate the minimum possible value of the maximum difference
    int ans = v[n - 1] - v[0]; // Initial range with all elements
    int left = 0, right = n - 1;
    int remove_left = 0, remove_right = 0;

    // Iterate over the sorted array and simulate removals
    while (left <= right) {
        // Check the range if we remove K elements from the left side
        if (left - remove_left < n - right - 1 - remove_right) {
            if (remove_left + k <= left) { // We can remove K elements from the left
                ans = min(ans, v[left - k] - v[left - remove_left - k]);
            } else { // Not enough elements on the left to remove K
                break;
            }
        } else {
            // Check the range if we remove K elements from the right side
            if (n - right - 1 - remove_right < k) { // Not enough elements on the right to remove K
                break;
            }
            ans = min(ans, v[right - remove_right - 1] - v[right - k - remove_right]);
        }

        // Increment the number of elements removed from the respective side
        if (left - remove_left < n - right - 1 - remove_right) {
            remove_left++;
        } else {
            remove_right++;
        }

        // Move the pointers
        if (remove_left < left - remove_left) {
            left++;
        }
        if (remove_right < n - right - 1 - remove_right) {
            right--;
        }
    }

    cout << ans << endl;
    return 0;
}