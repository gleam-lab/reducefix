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
    sort(a.begin(), a.end());

    // Case where no elements are removed
    int diff1 = a[n - 1] - a[0];

    // Find the minimum difference after removing K elements
    int diff = diff1;
    int remaining = n - k;
    for (int i = 0, j = k - 1; i < remaining; ++i, ++j) {
        int cur_diff = a[remaining + j] - a[i];
        diff = min(diff, cur_diff);
    }

    cout << diff << endl;
    return 0;
}