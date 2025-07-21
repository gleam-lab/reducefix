#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    // Binary search for removing elements from the right end
    int left = 0; // minimum value of remaining elements
    int right = n - 1; // maximum value of remaining elements
    int minRange = numeric_limits<int>::max();
    int bestLeft = 0;
    int bestRight = 0;

    while (k--) {
        // If removing an element from the right results in a smaller range
        if (v[right] - v[left] < v[right - 1] - v[left]) {
            right--;
        } else {
            // Otherwise, remove an element from the left and update the left index
            left++;
        }
        // Update the minimum range
        int currentRange = v[right] - v[left];
        if (currentRange < minRange) {
            minRange = currentRange;
            bestLeft = left;
            bestRight = right;
        }
    }

    cout << minRange << endl;
    return 0;
}