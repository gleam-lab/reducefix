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

    // Sort the array to easily access the smallest and largest values
    sort(v.begin(), v.end());

    // If k is 0, no elements are removed, so the answer is the difference between the max and min of the array
    if (k == 0) {
        cout << v[n - 1] - v[0] << endl;
        return 0;
    }

    // The minimum possible value of the max of B minus the min of B after removing k elements
    int minMaxMinDiff = numeric_limits<int>::max();

    // Use a sliding window approach to find the minimum difference
    // Initialize the left pointer to 0, right pointer to n-k-1 (since we need to keep k elements in the window)
    for (int left = 0; left <= n - k; ++left) {
        int right = left + k - 1;
        // Calculate the difference between the max and min in the current window
        int currentDiff = v[right] - v[left];
        // Update the minimum possible difference
        minMaxMinDiff = min(minMaxMinDiff, currentDiff);
    }

    cout << minMaxMinDiff << endl;
    return 0;
}