#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (auto& val : v) {
        cin >> val;
    }
    sort(v.begin(), v.end());
    int min_diff = v[n - 1] - v[0]; // Initialize to the maximum possible difference
    for (int i = 0; i <= k; ++i) {
        // The window is from i to i + (n - k) - 1
        int current_diff = v[i + (n - k) - 1] - v[i];
        if (current_diff < min_diff) {
            min_diff = current_diff;
        }
    }
    cout << min_diff << endl;
    return 0;
}