#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

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

    // Calculate the minimum possible value of the maximum and minimum of B
    int min_diff = INT_MAX;
    for (int i = 0; i <= n - k; ++i) {
        int max_b = a[n - k - i - 1]; // Max of B when we remove i elements from the start
        int min_b = a[i];             // Min of B when we remove i elements from the start
        min_diff = min(min_diff, max_b - min_b);
    }

    cout << min_diff << endl;
    return 0;
}