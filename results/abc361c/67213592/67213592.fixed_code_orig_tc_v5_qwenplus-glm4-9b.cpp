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

    // Sort the vector to facilitate easy range calculations
    sort(v.begin(), v.end());

    // Initialize pointers and distance to cover
    int left = 0, right = n - 1, dist = n - k;
    long long min_range = LLONG_MAX;

    // Explore all possible ways to remove k elements
    while (right - left + 1 > k) {
        long long current_range = v[right] - v[left];

        // Adjust pointers to minimize the range while keeping the total number of removed elements as k
        if (right - left + 1 > k + 2) {
            right--;
        }
        if (right - left + 1 < k) {
            left++;
        }

        // Update the minimum range found
        min_range = min(min_range, current_range);
    }

    // Output the minimum range
    cout << min_range << endl;
}