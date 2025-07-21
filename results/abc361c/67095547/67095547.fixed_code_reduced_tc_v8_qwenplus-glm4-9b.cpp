#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // Sort the array to easily find the smallest and largest elements.
    sort(a.begin(), a.end());

    int minDifference = numeric_limits<int>::max();
    vector<int> maxElements(n + 1, 0), minElements(n + 1, 0);

    // Find the minimum and maximum of the remaining elements for each possible scenario.
    for (int i = 0; i <= n - k; ++i) {
        int maxVal = 0, minVal = numeric_limits<int>::max();
        for (int j = i; j < i + k; ++j) {
            maxVal = max(maxVal, a[j]);
            minVal = min(minVal, a[j]);
        }
        int remainingMax = max(a[n - k], maxVal);
        int remainingMin = min(a[i], minVal);
        minDifference = min(minDifference, remainingMax - remainingMin);
    }

    cout << minDifference << endl;
    return 0;
}