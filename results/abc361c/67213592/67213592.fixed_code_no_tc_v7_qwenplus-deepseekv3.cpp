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
    int result = v[n - 1] - v[0]; // Initialize with the worst possible difference
    for (int x = 0; x <= k; ++x) {
        int y = k - x;
        if (x + y > k) continue; // Not necessary, but just to ensure x + y == k
        int current_min = v[x];
        int current_max = v[n - 1 - y];
        result = min(result, current_max - current_min);
    }
    cout << result << '\n';
    return 0;
}