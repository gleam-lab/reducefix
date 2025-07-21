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

    sort(a.begin(), a.end());  // Sort the array

    // Calculate the minimum difference after removing elements from the ends
    long long removeEnds = max(a[k-1] - a[0], a[n-k-1] - a[k]);

    // Calculate the minimum difference after removing elements from the middle
    long long minDiff = LLONG_MAX;
    for (int i = k; i < n - k; ++i) {
        minDiff = min(minDiff, a[i] - a[k-1]);
    }

    // The answer is the minimum of the two calculated differences
    cout << min(removeEnds, minDiff) << endl;

    return 0;
}