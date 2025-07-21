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

    // Sort the array
    sort(a.begin(), a.end());

    // Calculate differences between consecutive elements
    vector<int> diffs(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        diffs[i] = a[i + 1] - a[i];
    }

    // Sort differences to easily pick the smallest and largest
    sort(diffs.begin(), diffs.end());

    // Calculate minimal possible value of the max-min for remaining sequence
    int minSpread = INT_MAX;
    for (int i = 0; i < k; ++i) {
        // Consider removing i-th smallest and (k-1-i)-th largest gap
        int maxVal = a[0] + diffs[i] - diffs[k - 1 - i];
        int minVal = a[n - 1] - diffs[i] + diffs[k - 1 - i];
        minSpread = min(minSpread, maxVal - minVal);
    }

    cout << minSpread << endl;
    return 0;
}