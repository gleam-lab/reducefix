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
    int result = v[n - 1] - v[0]; // Initialize with the maximum possible difference
    for (int i = 0; i + (n - k) - 1 < n; ++i) {
        int current_diff = v[i + (n - k) - 1] - v[i];
        if (current_diff < result) {
            result = current_diff;
        }
    }
    cout << result << endl;
    return 0;
}