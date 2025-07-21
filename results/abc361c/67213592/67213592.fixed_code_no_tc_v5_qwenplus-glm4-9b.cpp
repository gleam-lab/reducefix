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

    // Sort the vector in non-decreasing order
    sort(v.begin(), v.end());

    // Initialize variables to track the minimum and maximum values of B
    int minB = INT_MAX;
    int maxB = INT_MIN;

    // Two pointers to consider removing elements from the ends of the array
    int left = 0;
    int right = n - 1;

    // Perform the removal of K elements
    while (k > 0) {
        // Decide whether to remove from the left or the right
        if (k == 1) {
            // If exactly one element is left to remove, choose the one that maximizes the range
            if (v[right] - v[left + 1] >= v[right - 1] - v[left]) {
                minB = min(minB, v[left + 1]);
                maxB = max(maxB, v[right]);
            } else {
                minB = min(minB, v[left]);
                maxB = max(maxB, v[right - 1]);
            }
            break;
        } else {
            minB = min(minB, v[left + k / 2]);
            maxB = max(maxB, v[right - k / 2]);
        }

        // Remove the elements chosen to maximize the range
        if (v[right] - v[left + 1] >= v[right - 1] - v[left]) {
            left++;
        } else {
            right--;
        }
        k -= 2; // Two elements are removed in each iteration
    }

    // If no elements are removed, the range is the difference between the first and last elements
    if (k == 0) {
        minB = v[0];
        maxB = v[n - 1];
    }

    // Output the result
    cout << maxB - minB << endl;

    return 0;
}