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
    int min_diff = v.back() - v.front(); // Initialize with the whole array's difference
    int window_size = n - k;
    for (int i = 0; i + window_size <= n; ++i) {
        int current_diff = v[i + window_size - 1] - v[i];
        if (current_diff < min_diff) {
            min_diff = current_diff;
        }
    }
    cout << min_diff << endl;
    return 0;
}