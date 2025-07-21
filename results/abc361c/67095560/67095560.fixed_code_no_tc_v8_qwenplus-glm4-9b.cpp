#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // Sort the array to easily find the minimum and maximum values
    sort(a.begin(), a.end());

    // To minimize the difference, we should remove the largest and smallest K elements
    // and then take the difference of the largest remaining and the smallest remaining.
    // This works because by removing the largest and smallest, we reduce the range.

    int max_val = a[n - k - 1]; // Second largest element after removing k elements
    int min_val = a[k];          // Smallest element after removing k elements

    // Output the difference between the second largest and smallest elements
    cout << max_val - min_val << endl;
}

int main() {
    solve();
    return 0;
}