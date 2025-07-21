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

    sort(a.begin(), a.end());

    // Initial difference between max and min after removing K elements
    int min_diff = a[n - k] - a[k - 1];

    // Try removing both smallest and largest K elements to find the minimum difference
    for (int i = 0; i <= k; ++i) {
        int diff = a[n - k] - a[k - i - 1];
        min_diff = min(min_diff, diff);
    }

    cout << min_diff << endl;

    return 0;
}