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
    vector<int> prefix_max(n);
    vector<int> suffix_min(n);
    prefix_max[0] = a[0];
    for (int i = 1; i < n; ++i) {
        prefix_max[i] = max(prefix_max[i - 1], a[i]);
    }
    suffix_min[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        suffix_min[i] = min(suffix_min[i + 1], a[i]);
    }
    int min_range = INT_MAX;
    for (int i = k; i <= n - k; ++i) {
        int range = prefix_max[i - 1] - suffix_min[i + k - 1];
        min_range = min(min_range, range);
    }
    cout << min_range << endl;
    return 0;
}