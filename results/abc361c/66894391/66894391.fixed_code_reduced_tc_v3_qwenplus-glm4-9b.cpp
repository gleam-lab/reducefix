#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, k;
    vector<int> nums;

    // Read input
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        nums.push_back(num);
    }

    sort(nums.begin(), nums.end());

    long long minRange = numeric_limits<long long>::max();

    // Iterate over each possible split point
    for (int i = k; i <= n - k; ++i) {
        long long maxVal = nums[n - k - 1];
        long long minVal = nums[k - 1];
        long long currentRange = maxVal - minVal;

        // Calculate the range if we remove k elements
        // We can remove elements from either side of the middle
        int leftRemovals = min(k, i - k);
        int rightRemovals = min(k, n - i - 1);

        if (leftRemovals <= k && rightRemovals <= k) {
            if (leftRemovals <= rightRemovals) {
                minVal = nums[i - leftRemovals - 1];
            } else {
                maxVal = nums[i + rightRemovals];
            }
            currentRange = maxVal - minVal;
            minRange = min(minRange, currentRange);
        }
    }

    cout << minRange << endl;

    return 0;
}